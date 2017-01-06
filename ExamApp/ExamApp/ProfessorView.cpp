/*+===================================================================
File:      ProfessorView.cpp

Summary:   Source file for ProfessorView

Classes:   ProfessorView

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "ProfessorView.h"
#include "Question.h"

using namespace std;

namespace ExamAppViews
{
	ExamAppModels::ProfessorMenuItems ProfessorView::displayMenu()
	{
		// Variable declaration and initialization
		string input = "";
		ExamAppModels::ProfessorMenuItems optionSelection = ExamAppModels::ProfessorMenuItems::Unkown;
		bool isValid = false;

		// Display student main menu
		cout << endl << "Welcome professor, what would you like to do?" << endl;
		cout << "1 - Create an exam" << endl;
		cout << "2 - Log Out" << endl;

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				optionSelection = static_cast<ExamAppModels::ProfessorMenuItems>(stoi(input));
			}
			catch (...)
			{
				cout << "Not a valid menu option, please try again" << endl;
				continue;
			}

			switch (optionSelection)
			{
			case ExamAppModels::ProfessorMenuItems::CreateExam:
			case ExamAppModels::ProfessorMenuItems::Logout:
				isValid = true;
				break;
			case ExamAppModels::ProfessorMenuItems::Unkown:
			default:
				cout << "Not a valid menu option, please try again" << endl;
				break;
			}

		} while (!isValid);

		return optionSelection;
	}

	std::string ProfessorView::displayExamNameInput()
	{
		// Variable declaration and initialization
		string input = "";

		cout << endl << "Provide a name for this exam:" << endl;

		// Get input
		getline(cin, input);

		return input;
	}

	int ProfessorView::displayQuestionCountInput()
	{
		// Variable declaration and initialization
		string input = "";
		int count = 0;
		bool isValid = false;

		cout << endl << "How many questions will this exam have?" << endl;

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				count = stoi(input);
				isValid = true;
			}
			catch (...)
			{
				cout << "Not a valid question count, please try again" << endl;
			}

		} while (!isValid);

		return count;
	}

	void ProfessorView::displayQuestionNumber(int number)
	{
		// Display question number
		cout << endl << "*********** Question " << number << " ***********" << endl;
	}

	ExamAppModels::QuestionTypes ProfessorView::displayQuestionTypeInput()
	{
		// Variable declaration and initialization
		string input = "";
		ExamAppModels::QuestionTypes type = ExamAppModels::QuestionTypes::Unknown;
		bool isValid = false;

		// Display type options to select
		cout << endl << "Select question type:" << endl;
		cout << "1 - True/False" << endl;
		cout << "2 - Multiple Choice" << endl;

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				type = static_cast<ExamAppModels::QuestionTypes>(stoi(input));
			}
			catch (...)
			{
				cout << "Not a valid menu option, please try again" << endl;
				continue;
			}

			switch (type)
			{
			case ExamAppModels::QuestionTypes::TF:
			case ExamAppModels::QuestionTypes::MC:
				isValid = true;
				break;
			case ExamAppModels::QuestionTypes::Unknown:
			default:
				cout << "Not a valid menu option, please try again" << endl;
				break;
			}

		} while (!isValid);

		return type;
	}

	int ProfessorView::displayQuestionPointValueInput()
	{
		// Variable declaration and initialization
		string input = "";
		int points = 0;
		bool isValid = false;

		cout << endl << "Provide point value for question:" << endl;

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				points = stoi(input);
				isValid = true;
			}
			catch (...)
			{
				cout << "Not a valid point value, please try again" << endl;
			}

		} while (!isValid);

		return points;
	}

	std::string ProfessorView::displayQuestionTextInput()
	{
		// Variable declaration and initialization
		string input = "";

		cout << endl << "Provide text for this question:" << endl;

		// Get input
		getline(cin, input);

		return input;
	}

	int ProfessorView::displayMCOptionsCountInput()
	{
		// Variable declaration and initialization
		string input = "";
		int count = 0;
		bool isValid = false;

		cout << endl << "How many multiple choice options will this question have?" << endl;

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				count = stoi(input);
				isValid = true;
			}
			catch (...)
			{
				cout << "Not a valid option count, please try again" << endl;
			}

		} while (!isValid);

		return count;
	}

	std::string ProfessorView::displayMCOptionTextInput(int optionNumber)
	{
		// Variable declaration and initialization
		string input = "";

		cout << endl << "Provide text for option " << optionNumber  << ":" << endl;

		// Get input
		getline(cin, input);

		return input;
	}

	int ProfessorView::displayAnswerKeyInput(ExamAppModels::Question *question)
	{
		// Variable declaration and initialization
		string input = "";
		int answer = -1;
		int optionCount = question->getOptionCount();
		bool isValid = false;

		// Display question Id, text and options
		cout << endl << "Provide answer key value for question:" << endl;
		cout << question->getAnswerOptionsDisplay();

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				answer = stoi(input);

				if (answer >= 1 && answer <= optionCount)
					isValid = true;
				else
					cout << "Not a valid answer, please try again" << endl;
			}
			catch (...)
			{
				cout << "Not a valid answer, please try again" << endl;
			}
		} while (!isValid);

		return answer;
	}

	void ProfessorView::displayExamTemplateCreatedConfirmation(std::string examName)
	{
		cout << endl << "Exam " << examName << " created." << endl;
	}
}
