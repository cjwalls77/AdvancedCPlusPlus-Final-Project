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

namespace ExamAppModels
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
		Student* getStudent(int studentId) override;
		Exam* getNewExam(IndexItem *item) override;
		GradedExam* getGradedExam(IndexItem *item) override;
		std::vector<IndexItem*>* getExamTemplateIndex() override;
		std::vector<IndexItem*>* getGradedExamIndex(int studentId) override;
		bool saveExamTemplate(Exam *exam) override;
		bool savePendingExam(Exam *exam, Student *student) override;

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

		Returns:  None
		===================================================================+*/
		void openFileForRead(std::string filePath);

		/*+===================================================================
		Function: openFileForWrite

		Summary:  Open file for writing, ensure success.

		Args:     filePath
					Path for file to be opened for reading.

		Returns:  None
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
		Function: getDirectoryIndexForStudent

		Summary:  Get vector of IndexItem objects from a directory index file,
			      for a specific student.

		Args:     indexFilePath
					File path for directory index file.
				  studentId
					Id for student to pull index items for.

		Returns:  vector<IndexItem*>*
					Pointer to vector of IndexItems loaded from index file for student.
		===================================================================+*/
		std::vector<IndexItem*>* getDirectoryIndexForStudent(std::string indexFilePath, int studentId);

		/*+===================================================================
		Function:  mapStudent

		Summary:  Initialize Student object and map to current line items.

		Args:     None

		Returns:  Student*
					Pointer to Student object.
		===================================================================+*/
		Student* mapStudent();

		/*+===================================================================
		Function:  mapIndexItem

		Summary:  Initialize IndexItem object and map to current line items.

		Args:     None

		Returns:  IndexItem*
					Pointer to IndexItem object.
		===================================================================+*/
		IndexItem* mapIndexItem();

		/*+===================================================================
		Function: loadTemplateData

		Summary:  Load template data in exam reference from file

		Args:     item
					Reference to an IndexItem object.
				  Exam
					Exam reference to load template data into

		Returns:  Boolean
					Load is success
		===================================================================+*/
		bool loadTemplateData(IndexItem &item, Exam &exam);

		/*+===================================================================
		Function: loadGradedAnswerSheetData

		Summary:  Load graded answer sheet data into GradedExam reference

		Args:     item
					Reference to an IndexItem object.
				  gradedExam
					GradedExam reference to load graded answer sheet data into

		Returns:  Boolean
					Load is success
		===================================================================+*/
		bool loadGradedAnswerSheetData(IndexItem &item, GradedExam &gradedExam);

		/*+===================================================================
		Function: GetIndexForExamTemplate

		Summary:  Get index item for exam template from exam id.

		Args:     examId
					Id for exam.

		Returns:  IndexItem
					Pointer for index item.
		===================================================================+*/
		IndexItem* GetIndexForExamTemplate(int examId);

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

		Summary:  Save answer sheet for exam to a file.
				  Update dirctory index after answer sheet is saved.

		Args:     exam
					Pointer to Exam object to be saved.

		Returns:  None
		===================================================================+*/
		void saveAnswerSheet(Exam *exam);

		/*+===================================================================
		Function: mapTFQuestion

		Summary:  Initialize TF question from open exam template file.

		Args:     None

		Returns:  bool
		Indicate if answer was correct.
		===================================================================+*/
		Question* mapTFQuestion();

		/*+===================================================================
		Function: mapMCQuestion

		Summary:  Initialize MC question from open exam template file.

		Args:     None

		Returns:  bool
		Indicate if answer was correct.
		===================================================================+*/
		Question* mapMCQuestion();

		/*+===================================================================
		Function: mapAnswerKey

		Summary:  Initialize answer key from open graded exam file.

		Args:     None

		Returns:  AnswerKey
					Pointer to AnswerKey object
		===================================================================+*/
		AnswerKey* mapAnswerKey();

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

		/*+===================================================================
		Function: setupAppIndexDirectoryFiles

		Summary:  Setup index files for application if they do not exist.

		Args:     None

		Returns:  None
		===================================================================+*/
		void setupAppIndexDirectoryFiles();

		/*+===================================================================
		Function: checkFileExists

		Summary:  Check if file exists.

		Args:     filePath
					Path of file to be checked.

		Returns:  bool
					Indicate if file exists.
		===================================================================+*/
		static bool checkFileExists(std::string filePath);

		/*+===================================================================
		Function: addEmptyFile

		Summary:  Add empty file.

		Args:     filePath
					Path of file to be added.

		Returns:  None
		===================================================================+*/
		void addEmptyFile(std::string filePath);

		/*+===================================================================
		Function: saveNewExamTemplate

		Summary:  Add new exam template to exam_template directory and update
				  directory index.

		Args:     exam
					Reference to exam to save a template from.

		Returns:  Boolean
					Confirmation that exam template was saved.
		===================================================================+*/
		bool saveNewExamTemplate(Exam &exam);

		/*+===================================================================
		Function: saveNewExamRubric

		Summary:  Add exam grading rubric for new exam template to
				  exam_rubrics directory and updated directory index.

		Args:     exam
					Reference to exam to save rubric from.

		Returns:  Boolean
					Confirmation that exam rubric was saved.
		===================================================================+*/
		bool saveNewExamRubric(Exam &exam);
	};
}
