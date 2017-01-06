/*+===================================================================
File:      FileRepository.cpp

Summary:   Source file for FileRepository

Classes:   FileRepository

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "FileRepository.h"
#include "Config.h"
#include "FileNotFoundException.h"

using namespace std;

namespace ExamGraderAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	FileRepository::FileRepository()
	{
		delimiter = ','; // file delimiter for all exam application files
		line = "";
	}

	FileRepository::~FileRepository()
	{
		// Close any open files
		fileReader.close();
		fileWriter.close();
	}

	std::vector<IndexItem*>* FileRepository::getAnswerSheetIndex()
	{
		return getDirectoryIndex(ExamGraderApp::Config::getPendingExamsIndexFilePath());
	}

	AnswerSheet* FileRepository::getAnswerSheet(IndexItem *item)
	{
		AnswerSheet* answerSheet = mapAnswerSheet(*item);
		int questionCount = 0;
		bool isValidData = true; // assumed to be valid until error found during loading questions

		// Attempt to open file for read
		try
		{
			string filePath = ExamGraderApp::Config::getPendingExamsBasePath() + item->getFileName();
			openFileForRead(filePath);
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			return nullptr;
		}

		// Try/Catch if file not correct format or type
		try
		{
			// Get question count from file
			questionCount = getQuestionCount();
			answerSheet->setQuestionCount(questionCount);

			// Loop to load answers from file
			for (int i = 1; i <= questionCount; i++)
			{
				getline(fileReader, line);
				parseLineItems();

				answerSheet->addAnswer(mapAnswer());
			}
		}
		catch(...)
		{
			cout << "Error: Exam answer sheet file could not be read." << endl;
			isValidData = false;
		}

		// Close file
		fileReader.close();
		
		return isValidData ? answerSheet : nullptr;
	}

	std::vector<IndexItem*>* FileRepository::getExamRubricIndex()
	{
		return getDirectoryIndex(ExamGraderApp::Config::getExamRubricsIndexFilePath());
	}

	ExamRubric* FileRepository::getExamRubric(IndexItem *item)
	{
		ExamRubric* examRubric = mapExamRubric(*item);
		int questionCount = 0;
		bool isValidData = true; // assumed to be valid until error found during loading questions

		// Attempt to open file for read
		try
		{
			string filePath = ExamGraderApp::Config::getExamRubricsBasePath() + item->getFileName();
			openFileForRead(filePath);
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			return nullptr;
		}

		// Try/Catch if file not correct format or type
		try
		{
			// Get question count from file
			questionCount = getQuestionCount();

			// Loop to load answers from file
			for (int i = 1; i <= questionCount; i++)
			{
				getline(fileReader, line);
				parseLineItems();

				examRubric->addAnswerKey(mapAnswerKey());
			}
		}
		catch (...)
		{
			cout << "Error: Exam rubric file could not be read." << endl;
			isValidData = false;
		}

		// Close file
		fileReader.close();

		return isValidData ? examRubric : nullptr;
	}

	ExamRubric* FileRepository::getExamRubricForExam(int examId)
	{
		auto indexItems = getDirectoryIndex(ExamGraderApp::Config::getExamRubricsIndexFilePath());
		IndexItem *examIndexItem = nullptr;
		ExamRubric *examRubric = nullptr;

		for (auto it = indexItems->begin(); it != indexItems->end(); ++it)
		{
			if ((*it)->getExamId() == examId)
			{
				examIndexItem = (*it);
				break;
			}
		}

		if (examIndexItem != nullptr)
		{
			examRubric = getExamRubric(examIndexItem);
		}

		// Clean-up
		clearIndexItems(indexItems);
		delete indexItems;

		return examRubric;
	}

	void FileRepository::saveGradedAnswerSheet(AnswerSheet &answerSheet, ExamRubric &examRubric)
	{
		// Variable declaration and initialization
		auto indexItems = getDirectoryIndex(ExamGraderApp::Config::getGradedExamsIndexFilePath());
		int newIndexId = indexItems->empty() ? 1 : indexItems->back()->getId() + 1;
		string newExamFileName = "gradedexam_" + to_string(newIndexId) + ".txt";

		// Add Answer Sheet File
		try
		{
			openFileForWrite(ExamGraderApp::Config::getGradedExamBasePath() + newExamFileName);
			saveAnswerSheet(answerSheet, examRubric);
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
		}

		// Close answer sheet file
		fileWriter.close();

		// Create New Index
		IndexItem *newItem = new IndexItem();
		newItem->setId(newIndexId);
		newItem->setExamId(answerSheet.getExamId());
		newItem->setStudentId(answerSheet.getStudentId());
		newItem->setIndexItemName(answerSheet.getExamName());
		newItem->setFileName(newExamFileName);

		// Add Index
		indexItems->push_back(newItem);
		updateDirectoryIndex(ExamGraderApp::Config::getGradedExamsIndexFilePath(), indexItems);

		// Clean-up
		clearIndexItems(indexItems);
		delete indexItems;
	}

	void FileRepository::removeAnswerSheetFromPending(int indexId)
	{
		string indexFilePath = "";
		int index = 0;
		bool indexFound = false;
		vector<IndexItem*> *indexItems = getDirectoryIndex(ExamGraderApp::Config::getPendingExamsIndexFilePath());

		for (auto it = indexItems->begin(); it != indexItems->end(); ++it)
		{
			if ((*it)->getId() == indexId)
			{
				indexFound = true;
				break;
			}

			index++;
		}

		// Remove index item
		indexFilePath = ExamGraderApp::Config::getPendingExamsBasePath() + (*indexItems)[index]->getFileName();
		remove(indexFilePath.c_str());
		delete (*indexItems)[index];
		indexItems->erase(indexItems->begin() + index);

		// Update Index
		updateDirectoryIndex(ExamGraderApp::Config::getPendingExamsIndexFilePath(), indexItems);

		// Clean-up
		clearIndexItems(indexItems);
		delete indexItems;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/

	void FileRepository::openFileForRead(string filePath)
	{
		fileReader.open(filePath);

		// Check file open successful
		if (!fileReader.is_open() && fileReader.fail())
		{
			throw CustomExceptions::FileNotFoundException();
		}
	}

	void FileRepository::openFileForWrite(string filePath)
	{
		fileWriter.open(filePath);

		// Check file open successful
		if (!fileWriter.is_open() && fileWriter.bad())
		{
			throw CustomExceptions::FileNotFoundException();
		}
	}

	void FileRepository::parseLineItems()
	{
		// Load file line into stream
		istringstream stream(line);

		// Clear line items vector of old line data
		lineItems.clear();

		// Parse line into lineItems vector for each delimited item
		while (stream)
		{
			string item = "";
			if (!getline(stream, item, delimiter))
				break;

			lineItems.push_back(item);
		}

	}

	std::vector<IndexItem*>* FileRepository::getDirectoryIndex(string indexFilePath)
	{
		// Variable declaration and initialization
		vector<IndexItem*> *items = new vector<IndexItem*>;

		// Try/Catch if file not correct format or type
		try
		{
			openFileForRead(indexFilePath);

			while (!fileReader.eof())
			{
				// Get index item
				getline(fileReader, line);

				if (line != "")
				{
					parseLineItems();
					items->push_back(mapIndexItem());
				}
			}
		}
		catch (...)
		{
			cout << "Error: Index file " << indexFilePath << " could not be read." << endl;
		}

		// Close file
		fileReader.close();

		return items;
	}

	IndexItem* FileRepository::mapIndexItem()
	{
		// Map index item from parsed line item
		IndexItem *item = new IndexItem();
		item->setId(stoi(lineItems[0]));
		item->setStudentId(stoi(lineItems[1]));
		item->setExamId(stoi(lineItems[2]));
		item->setIndexItemName(lineItems[3]);
		item->setFileName(lineItems[4]);

		return item;
	}

	AnswerSheet* FileRepository::mapAnswerSheet(IndexItem& item)
	{
		AnswerSheet *answerSheet = new AnswerSheet();
		answerSheet->setExamId(item.getExamId());
		answerSheet->setExamName(item.getIndexItemName());
		answerSheet->setStudentId(item.getStudentId());

		return answerSheet;
	}

	Answer* FileRepository::mapAnswer()
	{
		Answer* answer = new Answer();
		answer->setQuestionId(stoi(lineItems[0]));
		answer->setOptionValue(stoi(lineItems[1]));

		return answer;
	}

	ExamRubric* FileRepository::mapExamRubric(IndexItem& item)
	{
		ExamRubric* examRubric = new ExamRubric();
		examRubric->setExamId(item.getExamId());

		return examRubric;
	}

	AnswerKey* FileRepository::mapAnswerKey()
	{
		AnswerKey* key = new AnswerKey();
		key->setQuestionId(stoi(lineItems[0]));
		key->setKeyOptionValue(stoi(lineItems[1]));
		key->setPointValue(stoi(lineItems[2]));

		return key;
	}

	int FileRepository::getQuestionCount()
	{
		// Read question count from exam file
		getline(fileReader, line);

		return stoi(line);
	}

	void FileRepository::saveAnswerSheet(AnswerSheet &answerSheet, ExamRubric &examRubric)
	{
		stringstream ss;

		// Write question count to top of file
		fileWriter << answerSheet.getQuestionCount() << endl;

		// Write answer sheet points
		ss << answerSheet.getTotalPoints() << "," << answerSheet.getPointsScored();
		fileWriter << ss.str() << endl;

		// Add graded answers to file
		for (int i = 0; i < answerSheet.getQuestionCount(); i++)
		{
			ss.str("");
			ss << answerSheet.getAnswerQuestionId(i) << "," << answerSheet.getAnswerValue(i) << "," << examRubric.getAnswerKeyValue(i);

			fileWriter << ss.str() << endl;
		}
	}

	void FileRepository::updateDirectoryIndex(string indexFilePath, vector<IndexItem*>* items)
	{
		// Open directory index file
		try
		{
			openFileForWrite(indexFilePath);
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
		}
		// Iterate over index items and write them to the file
		for (vector<IndexItem*>::iterator it = items->begin(); it != items->end(); ++it)
		{
			fileWriter << (*it)->getId() << "," << (*it)->getStudentId() << "," << (*it)->getExamId() << "," << (*it)->getIndexItemName() << "," << (*it)->getFileName() << endl;
		}

		fileWriter.close();
	}

	void FileRepository::clearIndexItems(std::vector<IndexItem*> *items)
	{
		// Loop over vector to deallocate IndexItem pointers
		while (!items->empty())
		{
			delete items->back();
			items->pop_back();
		}
	}
}
