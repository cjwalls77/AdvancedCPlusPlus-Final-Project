/*+===================================================================
File:     FileRepository.h

Summary:   Header file for FileRepository

Classes:   FileRepository

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "Repository.h"
#include <fstream>

namespace ExamGraderAppModels
{
	/*+===================================================================
	Class:    FileRepository

	Summary:  Manage read/write access to application files.

	===================================================================+*/
	class FileRepository : public Repository
	{
	public:
		/*+===================================================================
		Constructor
		===================================================================+*/
		FileRepository();

		/*+===================================================================
		Destructor
		===================================================================+*/
		~FileRepository() override;

		/*+===================================================================
		Implement Repository Interface
		===================================================================+*/
		std::vector<IndexItem*>* getAnswerSheetIndex() override;
		AnswerSheet* getAnswerSheet(IndexItem *item) override;
		std::vector<IndexItem*>* getExamRubricIndex() override;
		ExamRubric* getExamRubric(IndexItem *item) override;
		ExamRubric* getExamRubricForExam(int examId) override;
		void saveGradedAnswerSheet(AnswerSheet &answersheet, ExamRubric &examRubric) override;
		void removeAnswerSheetFromPending(int indexId) override;

	private:
		/*+===================================================================
		Private Member Variables
		===================================================================+*/
		std::ifstream fileReader;
		std::ofstream fileWriter;
		std::string line;
		char delimiter;
		std::vector<std::string> lineItems;

		/*+===================================================================
		Function: openFileForRead

		Summary:  Open file for reading, ensure success.

		Args:     filePath
		Path for file to be opened for reading.

		Returns:  bool
		Indicate if file opened successfully.
		===================================================================+*/
		void openFileForRead(std::string filePath);

		/*+===================================================================
		Function: openFileForWrite

		Summary:  Open file for writing, ensure success.

		Args:     filePath
		Path for file to be opened for reading.

		Returns:  bool
		Indicate if file opened successfully.
		===================================================================+*/
		void openFileForWrite(std::string filePath);

		/*+===================================================================
		Function: parseLineItems

		Summary:  Parse line by delimiter and save to lineItems vector.

		Args:     None

		Returns:  None
		===================================================================+*/
		void parseLineItems();

		/*+===================================================================
		Function: getDirectoryIndex

		Summary:  Get vector of IndexItem objects from a directory index file.

		Args:     indexFilePath
		File path for directory index file.

		Returns:  vector<IndexItem*>*
		Pointer to vector of IndexItems loaded from index file.
		===================================================================+*/
		std::vector<IndexItem*>* getDirectoryIndex(std::string indexFilePath);

		/*+===================================================================
		Function:  mapIndexItem

		Summary:  Initialize IndexItem object and map to current line item.

		Args:     None

		Returns:  IndexItem*
		Pointer to IndexItem object.
		===================================================================+*/
		IndexItem* mapIndexItem();

		/*+===================================================================
		Function:  mapAnswerSheet

		Summary:  Initialize AnswerSheet object and map to index item.

		Args:     item
					IndexItem object for answer sheet to be mapped.

		Returns:  AnswerSheet*
					Pointer to AnswerSheet object.
		===================================================================+*/
		static AnswerSheet* mapAnswerSheet(IndexItem &item);

		/*+===================================================================
		Function:  mapAnswer

		Summary:  Initialize Answer object and map to current line item.

		Args:     None

		Returns:  Answer*
					Pointer to Answer object.
		===================================================================+*/
		Answer* mapAnswer();

		/*+===================================================================
		Function:  mapExamRubric

		Summary:  Initialize ExamRubric object and map to index item.

		Args:     item
					IndexItem object for exam rubric to be mapped.

		Returns:  ExamRubric*
					Pointer to ExamRubric object.
		===================================================================+*/
		static ExamRubric* mapExamRubric(IndexItem &item);

		/*+===================================================================
		Function:  mapAnswerKey

		Summary:  Initialize AnswerKey object and map to current line item.

		Args:     None

		Returns:  AnswerKey*
					Pointer to AnswerKey object.
		===================================================================+*/
		AnswerKey* mapAnswerKey();

		/*+===================================================================
		Function: getQuestionCount

		Summary:  Get question count from file.

		Args:     None

		Returns:  int
		Question count.
		===================================================================+*/
		int getQuestionCount();

		/*+===================================================================
		Function: saveAnswerSheet

		Summary:  Save graded answer sheet for exam to a file.
				  Update dirctory index after answer sheet is saved.

		Args:     answerSheet
					Reference to graded AnswerSheet object to be saved.
				  examRubric
					Reference to ExamRubric object for answersheet to be saved.

		Returns:  None
		===================================================================+*/
		void saveAnswerSheet(AnswerSheet &answerSheet, ExamRubric &examRubric);

		/*+===================================================================
		Function: updateDirectoryIndex

		Summary:  Update file directory index file.

		Args:     indexFilePath
		File path to index file.
		items
		Pointer to vector of IndexItem object pointers to be saved.

		Returns:  None
		===================================================================+*/
		void updateDirectoryIndex(std::string indexFilePath, std::vector<IndexItem*> *items);

		/*+===================================================================
		Function: clearIndexItems

		Summary:  Deallocate IndexItem object pointers in vector.

		Args:     items
		Pointer to vector of IndexItem object pointers to be cleared.

		Returns:  None
		===================================================================+*/
		static void clearIndexItems(std::vector<IndexItem*> *items);
	};
}

