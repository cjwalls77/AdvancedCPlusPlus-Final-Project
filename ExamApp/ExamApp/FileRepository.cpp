/*+===================================================================
File:      FileRepository.cpp

Summary:   Source file for FileRepository

Classes:   FileRepository

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "FileRepository.h"
#include "TFQuestion.h"
#include "MCQuestion.h"
#include "MCOption.h"
#include "FileNotFoundException.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	FileRepository::FileRepository()
	{
		delimiter = ','; // file delimiter for all exam application files
		line = "";
		setupAppIndexDirectoryFiles();
	}

	FileRepository::~FileRepository()
	{
		// Close any open files
		fileReader.close();
		fileWriter.close();
	}

	Student* FileRepository::getStudent(int studentId)
	{
		// Variable declaration and initialization
		Student *student = nullptr;
		int currentLineStudentId = 0;
		bool isValidData = false;

		// Attempt to open file for read
		try
		{
			openFileForRead(ExamApp::Config::getStudentRosterFilePath());
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			return nullptr;
		}

		// Try/Catch if file not correct format or type
		try
		{
			while (!fileReader.eof())
			{
				getline(fileReader, line);

				if (line != "")
				{
					parseLineItems();
					currentLineStudentId = stoi(lineItems[0]);
				}

				// If id match load student into memory and return
				if (currentLineStudentId == studentId)
				{
					student = mapStudent();
					isValidData = true;
					break;
				}
			}
		}
		catch (...)
		{
			cout << endl << "Error: Student Roster file could not be read" << endl;
		}

		// close file
		fileReader.close();

		return isValidData ? student : nullptr;
	}

	Exam* FileRepository::getNewExam(IndexItem *item)
	{
		// Variable declaration and initialization
		Exam *exam = new Exam();
		bool isValidData = true;  // assumed to be valid until error found during loading questions

		isValidData = loadTemplateData((*item), (*exam));

		if (isValidData)
			return exam;
		else
		{
			delete exam;
			return nullptr;
		}
	}

	GradedExam* FileRepository::getGradedExam(IndexItem *item)
	{
		// Variable declaration and initialization
		GradedExam *gradedExam = new GradedExam();
		bool isValidData = true;  // assumed to be valid until error found during loading questions

		IndexItem *templateIndex = GetIndexForExamTemplate(item->getExamId());

		if (templateIndex != nullptr)
		{
			isValidData = loadTemplateData((*templateIndex), (*gradedExam));

			if (isValidData)
				isValidData = loadGradedAnswerSheetData((*item), (*gradedExam));
		}
		else
			isValidData = false;

		// Clean-up
		delete templateIndex;

		if (isValidData)
			return gradedExam;
		else
		{
			delete gradedExam;
			return nullptr;
		}
	}

	vector<IndexItem*> *FileRepository::getExamTemplateIndex()
	{
		// Get index items for exam template directory
		return getDirectoryIndex(ExamApp::Config::getExamTemplatesIndexFilePath());
	}

	vector<IndexItem*> *FileRepository::getGradedExamIndex(int studentId)
	{
		// Get index items for graded exam directory
		return getDirectoryIndexForStudent(ExamApp::Config::getGradedExamsIndexFilePath(), studentId);
	}

	bool FileRepository::saveExamTemplate(Exam* exam)
	{
		bool isSuccess = true;

		isSuccess = saveNewExamTemplate((*exam));

		if (isSuccess)
			isSuccess = saveNewExamRubric((*exam));

		return isSuccess;

	}

	bool FileRepository::savePendingExam(Exam *exam, Student *student)
	{
		// Variable declaration and initialization
		vector<IndexItem*> *indexItems = getDirectoryIndex(ExamApp::Config::getPendingExamsIndexFilePath());
		int newIndexId = indexItems->empty() ? 1 : indexItems->back()->getId() + 1;
		string newExamFileName = "exam_" + to_string(newIndexId) + ".txt";
		bool isSuccess = true;

		// Add Answer Sheet File
		try
		{
			openFileForWrite(ExamApp::Config::getPendingExamsBasePath() + newExamFileName);
			saveAnswerSheet(exam);
			fileWriter.close();
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			isSuccess = false;
		}

		if (isSuccess)
		{
			// Create New Index
			IndexItem *newItem = new IndexItem();
			newItem->setId(newIndexId);
			newItem->setExamId(exam->getId());
			newItem->setStudentId(student->getId());
			newItem->setIndexItemName(exam->getName());
			newItem->setFileName(newExamFileName);

			// Add Index
			indexItems->push_back(newItem);
			updateDirectoryIndex(ExamApp::Config::getPendingExamsIndexFilePath(), indexItems);
		}

		// Clean-up
		clearIndexItems(indexItems);
		delete indexItems;

		return isSuccess;
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
			cout << endl << "Error: Index file " << indexFilePath << " could not be read" << endl;
		}

		// Close file
		fileReader.close();

		return items;
	}

	std::vector<IndexItem*>* FileRepository::getDirectoryIndexForStudent(std::string indexFilePath, int studentId)
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
					ExamAppModels::IndexItem *indexItem = mapIndexItem();
					
					if (indexItem->getStudentId() == studentId)
					{
						items->push_back(indexItem);
					}
					else
					{
						// Clean-up if not included in vector
						delete indexItem;
					}
				}
			}
		}
		catch (...)
		{
			cout << endl << "Error: Index file " << indexFilePath << " could not be read" << endl;
		}

		// Close file
		fileReader.close();

		return items;
	}

	Student* FileRepository::mapStudent()
	{
		// Map student object from parsed line item
		Student * student = new Student();
		student->setId(stoi(lineItems[0]));
		student->setFirstName(lineItems[1]);
		student->setLastName(lineItems[2]);

		return student;
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

	bool FileRepository::loadTemplateData(IndexItem &item, Exam &exam)
	{
		// Variable declaration and initialization
		int questionCount = 0;
		bool isSuccess = true;  // assumed to be valid until error found during loading questions

		// Map exam from index item
		exam.setId(item.getExamId());
		exam.setName(item.getIndexItemName());

		 // Attempt to open file for read
		try
		{
			string filePath = ExamApp::Config::getExamTemplatesBasePath() + item.getFileName();
			openFileForRead(filePath);
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			isSuccess = false;

			// Close file
			fileReader.close();

			return isSuccess;
		}

		// Try/Catch if file not correct format or type
		try
		{
			// Get question count from file
			questionCount = getQuestionCount();

			// Loop to load question from file
			for (int i = 1; i <= questionCount; i++)
			{
				getline(fileReader, line);
				parseLineItems();

				switch (static_cast<QuestionTypes>(stoi(lineItems[1])))
				{
				case QuestionTypes::TF:
					exam.addQuestion(mapTFQuestion());
					break;
				case QuestionTypes::MC:
					exam.addQuestion(mapMCQuestion());
					break;
				case QuestionTypes::Unknown:
				default:
					isSuccess = false;
					break;
				}

				// Check if still valid data
				if (!isSuccess)
					break;
			}
		}
		catch (...)
		{
			cout << endl << "Error: Exam Template file could not be read" << endl;
			isSuccess = false;
		}

		// Close file
		fileReader.close();

		return isSuccess;
	}

	bool FileRepository::loadGradedAnswerSheetData(IndexItem& item, GradedExam& gradedExam)
	{
		// Variable declaration and initialization
		int keyCount = 0;
		bool isSuccess = true;  // assumed to be valid until error found during loading questions

		// Attempt to open file for read
		try
		{
			string filePath = ExamApp::Config::getGradedExamBasePath() + item.getFileName();
			openFileForRead(filePath);
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			isSuccess = false;

			// Close file
			fileReader.close();

			return isSuccess;
		}

		// Try/Catch if file not correct format or type
		try
		{
			// Get question count from file
			keyCount = getQuestionCount();

			// Set graded exam points
			getline(fileReader, line);
			parseLineItems();
			gradedExam.setTotalPoints(stoi(lineItems[0]));
			gradedExam.setPointsScored(stoi(lineItems[1]));

			// Loop to load question from file
			for (int i = 1; i <= keyCount; i++)
			{
				getline(fileReader, line);
				parseLineItems();

				gradedExam.addAnswerKey(mapAnswerKey());
			}
		}
		catch (...)
		{
			cout << endl << "Error: Graded answer sheet file could not be read" << endl;
			isSuccess = false;
		}

		// Close file
		fileReader.close();

		return isSuccess;
	}

	IndexItem* FileRepository::GetIndexForExamTemplate(int examId)
	{
		// Variable declaration and initialization
		IndexItem *currentItem = nullptr;

		// Try/Catch if file not correct format or type
		try
		{
			openFileForRead(ExamApp::Config::getExamTemplatesIndexFilePath());

			while (!fileReader.eof())
			{
				// Get index item
				getline(fileReader, line);

				if (line != "")
				{
					parseLineItems();
					currentItem = mapIndexItem();

					if (currentItem->getExamId() == examId)
						break;
					else
					{
						delete currentItem;
						currentItem = nullptr;
					}
				}
			}
		}
		catch (...)
		{
			cout << endl << "Error: Exam Template Index file could not be read" << endl;
		}

		// Close file
		fileReader.close();

		return currentItem;
	}

	int FileRepository::getQuestionCount()
	{
		// Read question count from exam file
		getline(fileReader, line);

		return stoi(line);
	}

	void FileRepository::saveAnswerSheet(Exam* exam)
	{
		// Add Question count
		int examQuestionCount = exam->getQuestionCount();

		// Write question count to top of file
		fileWriter << examQuestionCount << endl;

		// Add Question Answers to file
		for (int i = 0; i < examQuestionCount; i++)
		{
			stringstream ss;
			Question* question = exam->goToQuestion(i);

			if (question != nullptr)
			{
				ss << question->getId() << "," << question->getAnswerValue();

				fileWriter << ss.str() << endl;
			}
		}
	}

	Question* FileRepository::mapTFQuestion()
	{
		// Map TF question from parsed line item
		Question *question = new TFQuestion();
		question->setId(stoi(lineItems[0]));
		question->setPointValue(stoi(lineItems[2]));

		getline(fileReader, line);
		question->setQuestionText(line);

		return question;
	}

	Question* FileRepository::mapMCQuestion()
	{
		// Map MC question from parsed line item
		MCQuestion *question = new MCQuestion();
		int optionCount = 0;

		question->setId(stoi(lineItems[0]));
		question->setPointValue(stoi(lineItems[2]));

		getline(fileReader, line);
		question->setQuestionText(line);

		getline(fileReader, line);
		optionCount = stoi(line);

		// Map question options from file
		for (int i = 1; i <= optionCount; i++)
		{
			getline(fileReader, line);
			MCOption *option = new MCOption();

			option->setId(i);
			option->setText(line);
			question->addOption(option);
		}

		return question;
	}

	AnswerKey* FileRepository::mapAnswerKey()
	{
		AnswerKey *key = new AnswerKey();

		key->setQuestionId(stoi(lineItems[0]));
		key->setStudentAnswerValue(stoi(lineItems[1]));
		key->setAnswerKeyValue(stoi(lineItems[2]));

		return key;
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

	void FileRepository::setupAppIndexDirectoryFiles()
	{
		// Check if index files exist in directories if not create them
		if (!checkFileExists(ExamApp::Config::getStudentRosterFilePath()))
			addEmptyFile(ExamApp::Config::getStudentRosterFilePath());

		if (!checkFileExists(ExamApp::Config::getPendingExamsIndexFilePath()))
			addEmptyFile(ExamApp::Config::getPendingExamsIndexFilePath());

		if (!checkFileExists(ExamApp::Config::getGradedExamsIndexFilePath()))
			addEmptyFile(ExamApp::Config::getGradedExamsIndexFilePath());

		if (!checkFileExists(ExamApp::Config::getExamTemplatesIndexFilePath()))
			addEmptyFile(ExamApp::Config::getExamTemplatesIndexFilePath());

		if (!checkFileExists(ExamApp::Config::getExamRubricsIndexFilePath()))
			addEmptyFile(ExamApp::Config::getExamRubricsIndexFilePath());
	}

	bool FileRepository::checkFileExists(string filePath)
	{
		// Check if file exists
		struct stat buffer;
		return (stat(filePath.c_str(), &buffer) == 0);
	}

	void FileRepository::addEmptyFile(string filePath)
	{
		// Create new empty file
		fileWriter.open(filePath);
		fileWriter.close();
	}

	bool FileRepository::saveNewExamTemplate(Exam& exam)
	{
		// Variable declaration and initialization
		vector<IndexItem*> *indexItems = getDirectoryIndex(ExamApp::Config::getExamTemplatesIndexFilePath());
		int newIndexId = indexItems->empty() ? 1 : indexItems->back()->getId() + 1;
		string newExamFileName = "exam_" + to_string(newIndexId) + ".txt";
		bool isSuccess = true;

		// Add Answer Sheet File
		try
		{
			openFileForWrite(ExamApp::Config::getExamTemplatesBasePath() + newExamFileName);

			// Add Question count
			int examQuestionCount = exam.getQuestionCount();

			// Write question count to top of file
			fileWriter << examQuestionCount << endl;

			// Add Question to file
			for (int i = 0; i < examQuestionCount; i++)
			{
				Question *question = exam.goToQuestion(i);
				stringstream ss;

				if (question != nullptr)
				{
					// Write question information to file
					ss << question->getId() << "," << static_cast<int>(question->getQuestionType()) << "," << question->getPointValue();
					fileWriter << ss.str() << endl << question->getQuestionText() << endl;

					// Write MC options to file if MC question type
					if (question->getQuestionType() == QuestionTypes::MC)
					{
						fileWriter << question->getOptionCount() << endl;
						fileWriter << question->getAnswerOptions();
					}
				}
			}

			fileWriter.close();
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			isSuccess = false;
		}

		if (isSuccess)
		{
			// Create New Index
			IndexItem *newItem = new IndexItem();
			newItem->setId(newIndexId);
			newItem->setExamId(newIndexId);
			newItem->setStudentId(-1); // No student associated
			newItem->setIndexItemName(exam.getName());
			newItem->setFileName(newExamFileName);

			// Add Index
			indexItems->push_back(newItem);
			updateDirectoryIndex(ExamApp::Config::getExamTemplatesIndexFilePath(), indexItems);

			// Clean-up
			clearIndexItems(indexItems);
			delete indexItems;

			// Set exam id
			exam.setId(newIndexId);
		}

		return  isSuccess;
	}

	bool FileRepository::saveNewExamRubric(Exam& exam)
	{
		// Variable declaration and initialization
		vector<IndexItem*> *indexItems = getDirectoryIndex(ExamApp::Config::getExamRubricsIndexFilePath());
		int newIndexId = indexItems->empty() ? 1 : indexItems->back()->getId() + 1;
		string newExamFileName = "exam_" + to_string(newIndexId) + ".txt";
		bool isSuccess = true;

		// Add Answer Sheet File
		try
		{
			openFileForWrite(ExamApp::Config::getExamRubricsBasePath() + newExamFileName);

			// Add Question count
			int examQuestionCount = exam.getQuestionCount();

			// Write question count to top of file
			fileWriter << examQuestionCount << endl;

			// Add answer keys to file
			for (int i = 0; i < examQuestionCount; i++)
			{
				Question *question = exam.goToQuestion(i);
				stringstream ss;

				if (question != nullptr)
				{
					// Write question information to file
					ss << question->getId() << "," << question->getAnswerValue() << "," << question->getPointValue();
					fileWriter << ss.str() << endl;
				}
			}

			fileWriter.close();
		}
		catch (exception& ex)
		{
			cout << endl << ex.what() << endl;
			isSuccess = false;
		}

		if (isSuccess)
		{
			// Create New Index
			IndexItem *newItem = new IndexItem();
			newItem->setId(newIndexId);
			newItem->setExamId(exam.getId());
			newItem->setStudentId(-1); // no student associated
			newItem->setIndexItemName(exam.getName());
			newItem->setFileName(newExamFileName);

			// Add Index
			indexItems->push_back(newItem);
			updateDirectoryIndex(ExamApp::Config::getExamRubricsIndexFilePath(), indexItems);

			// Clean-up
			clearIndexItems(indexItems);
			delete indexItems;
		}

		return isSuccess;
	}
}
