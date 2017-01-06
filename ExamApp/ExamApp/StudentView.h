/*+===================================================================
File:      StudentView.h

Summary:   Header file for Student View.

Classes:   StudentView

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

#include "MenuOptions.h"
#include "Exam.h"
#include "GradedExam.h"
#include "Question.h"
#include "IndexItem.h"

namespace ExamAppViews
{
	/*+===================================================================
	Class:    StudentView

	Summary:  Manages UI output/input for application student role menus.

	===================================================================+*/
	class StudentView
	{
	public:
		/*+===================================================================
		Function: StudentView::displayMenu

		Summary:  Display main menu for student role.

		Args:     studentName
					Name of current student authenticated.

		Returns:  Student
					Selected student menu option.
		===================================================================+*/
		static ExamAppModels::StudentMenuItems displayMenu(std::string studentName);

		/*+===================================================================
		Function: StudentView::displayExamItemsToSelect

		Summary:  Display list of available exam index items to select,
				  return valid user selection.

		Args:     items
					Pointer to vector of exam index items.
				  message
					Message to display on UI for selection.

		Returns:  int
					Index value in vector for selected exam index item.
		===================================================================+*/
		static int displayExamItemsToSelect(std::vector<ExamAppModels::IndexItem*>* items, std::string message);

		/*+===================================================================
		Function: StudentView::displayExamStart

		Summary:  Display exam start information on UI.

		Args:     exam
					Pointer to exam to start.

		Returns:  None
		===================================================================+*/
		static void displayExamStart(ExamAppModels::Exam* exam);

		/*+===================================================================
		Function: StudentView::displayExamNavInstructions

		Summary:  Display exam navigation instructions.

		Args:     None

		Returns:  None
		===================================================================+*/
		static void displayExamNavInstructions();

		/*+===================================================================
		Function: StudentView::displayExamQuestion

		Summary:  Display question text and options, get user input for answer.

		Args:     question
					Pointer to question to be displayed.

		Returns:  int
					Valid answer value from user input.
		===================================================================+*/
		static int displayExamQuestion(ExamAppModels::Question* question);

		/*+===================================================================
		Function: StudentView::displayExamSavedMessage

		Summary:  Dislpay exam saved message to UI.

		Args:     examName
					Name of saved exam.

		Returns:  None
		===================================================================+*/
		static void displayExamSavedMessage(std::string examName);

		/*+===================================================================
		Function: StudentView::displayNoExamsAvailableMessage

		Summary:  Display no exam templates available message to UI.

		Args:     None

		Returns:  None
		===================================================================+*/
		static void displayNoExamsAvailableMessage();

		/*+===================================================================
		Function: StudentView::displayErrorOpeningExamMessage

		Summary:  Display error message for opening an exam template file to UI.

		Args:     None

		Returns:  None
		===================================================================+*/
		static void displayErrorOpeningExamMessage();

		/*+===================================================================
		Function: StudentView::logOn

		Summary:  Display results for graded exam on UI.

		Args:     gradedExam
					Pointer to GradedExam object.

		Returns:  None
		===================================================================+*/
		static void displayGradedExam(ExamAppModels::GradedExam *gradedExam);

		/*+===================================================================
		Function: StudentView::displayGradedExamMenu

		Summary:  Display menu options for viewing a graded exam

		Args:     None

		Returns:  StudentGradedExamMenuItems
					Enum for menu option selected.
		===================================================================+*/
		static ExamAppModels::StudentGradedExamMenuItems displayGradedExamMenu();

		/*+===================================================================
		Function: StudentView::displayGradedExamQuestion

		Summary:  Display menu options for viewing a graded exam

		Args:     Question
					Pointer to question to display.
				  AnswerKey
					Pointer to answer key for question.

		Returns:  None
		===================================================================+*/
		static void displayGradedExamQuestion(ExamAppModels::Question *question, ExamAppModels::AnswerKey *answerKey);

		/*+===================================================================
		Function: StudentView::displayEndofGradedQuestionsReached

		Summary:  Display message for end of graded questions reached.

		Args:     None

		Returns:  None
		===================================================================+*/
		static void displayEndofGradedQuestionsReached();
	};
}
