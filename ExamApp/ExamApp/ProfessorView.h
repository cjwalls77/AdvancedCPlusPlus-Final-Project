/*+===================================================================
File:      ProfessorView.h

Summary:   Header file for ProfessorView

Classes:   ProfessorView

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "MenuOptions.h"
#include "Question.h"

namespace ExamAppViews
{
	/*+===================================================================
	Class:    ProfessorView

	Summary:  Manages UI output/input for application professor role menus.

	===================================================================+*/
	class ProfessorView
	{
	public:
		/*+===================================================================
		Function: ProfessorView::displayMenu

		Summary:  Present main menu for professor role.

		Args:     None

		Returns:  ProfessorMenuItems
					Selected menu option for professor main menu.
		===================================================================+*/
		static ExamAppModels::ProfessorMenuItems  displayMenu();

		/*+===================================================================
		Function: ProfessorView::displayExamNameInput

		Summary:  Present input for exam name

		Args:     None

		Returns:  String
					Exam name.
		===================================================================+*/
		static std::string displayExamNameInput();

		/*+===================================================================
		Function: ProfessorView::displayQuestionCountInput

		Summary:  Present input for question count

		Args:     None

		Returns:  Integer
					Question count for exam.
		===================================================================+*/
		static int displayQuestionCountInput();

		/*+===================================================================
		Function: ProfessorView::displayQuestionNumber

		Summary:  Present current number of question being created

		Args:     number
					Current question number.

		Returns:  None
		===================================================================+*/
		static void displayQuestionNumber(int number);

		/*+===================================================================
		Function: ProfessorView::displayQuestionTypeInput

		Summary:  Present input for question type

		Args:     None

		Returns:  QuestionTypes
					Question type enum.
		===================================================================+*/
		static ExamAppModels::QuestionTypes displayQuestionTypeInput();

		/*+===================================================================
		Function: ProfessorView::displayQuestionPointValueInput

		Summary:  Present input for question point value

		Args:     None

		Returns:  Integer
					Point value.
		===================================================================+*/
		static int displayQuestionPointValueInput();

		/*+===================================================================
		Function: ProfessorView::displayQuestionTextInput

		Summary:  Present input for question text.

		Args:     None

		Returns:  string
					Question text.
		===================================================================+*/
		static std::string displayQuestionTextInput();

		/*+===================================================================
		Function: ProfessorView::displayMCOptionsCountInput

		Summary:  Present input for number of MC options

		Args:     None

		Returns:  Integer
					MC option count.
		===================================================================+*/
		static int displayMCOptionsCountInput();

		/*+===================================================================
		Function: ProfessorView::displayMCOptionTextInput

		Summary:  Present input for MC option text

		Args:     optionNumber
					Option number.

		Returns:  string
					MC option text.
		===================================================================+*/
		static std::string displayMCOptionTextInput(int optionNumber);

		/*+===================================================================
		Function: ProfessorView::displayAnswerKeyInput

		Summary:  Present input for question answer.

		Args:     None

		Returns:  Integer
					Answer value.
		===================================================================+*/
		static int displayAnswerKeyInput(ExamAppModels::Question *question);

		/*+===================================================================
		Function: ProfessorView::displayExamTemplateCreatedConfirmation

		Summary:  Present input for question answer.

		Args:     None

		Returns:  None
		===================================================================+*/
		static void displayExamTemplateCreatedConfirmation(std::string examName);
	};
}
