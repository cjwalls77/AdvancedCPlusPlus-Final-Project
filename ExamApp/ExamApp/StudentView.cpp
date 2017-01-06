/*+===================================================================
File:      StudentView.cpp

Summary:   Source file for StudentView

Classes:   StudentView

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "StudentView.h"

using namespace std;

namespace ExamAppViews
{
	/*+===================================================================
	Public Members
	===================================================================+*/
	ExamAppModels::StudentMenuItems StudentView::displayMenu(string studentName)
	{
		// Variable declaration and initialization
		string input = "";
		ExamAppModels::StudentMenuItems optionSelection = ExamAppModels::StudentMenuItems::Unkown;
		bool isValid = false;

		// Display student main menu
		cout << endl << "Welcome " << studentName << ", what would you like to do?" << endl;
		cout << "1 - Take an exam" << endl;
		cout << "2 - View exam results" << endl;
		cout << "3 - Log Out" << endl;

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				optionSelection = static_cast<ExamAppModels::StudentMenuItems>(stoi(input));
			}
			catch (...)
			{
				cout << "Not a valid menu option, please try again" << endl;
				continue;
			}

			switch (optionSelection)
			{
			case ExamAppModels::StudentMenuItems::TakeExam:
			case ExamAppModels::StudentMenuItems::ViewExam:
			case ExamAppModels::StudentMenuItems::Logout:
				isValid = true;
				break;
			case ExamAppModels::StudentMenuItems::Unkown:
			default:
				cout << "Not a valid menu option, please try again" << endl;
				break;
			}

		} while (!isValid);

		return optionSelection;
	}

	int StudentView::displayExamItemsToSelect(vector<ExamAppModels::IndexItem*> *items, string message)
	{
		// Variable declaration and initialization
		string input = "";
		bool isValid = false;
		int selectedId = -1;
		int selectedIndex = -1;


		// Display list of available exams
		cout << endl << message << endl;

		for (vector<ExamAppModels::IndexItem*>::iterator it = items->begin(); it != items->end(); ++it)
		{
			cout << (*it)->getId() << " - " << (*it)->getIndexItemName() << endl;
		}

		// Get valid input loop
		do
		{
			// Get user input
			getline(cin, input);

			// Validate input
			try
			{
				selectedId = stoi(input);
			}
			catch (...)
			{
				cout << "Not a valid menu option, please try again" << endl;
				continue;
			}

			// Validate exam template id exists and get index for that item in vector
			int index = 0;
			for (vector<ExamAppModels::IndexItem*>::iterator it = items->begin(); it != items->end(); ++it, index++)
			{
				if (selectedId == (*it)->getId())
				{
					isValid = true;
					selectedIndex = index;
					break;
				}
			}

			if (!isValid)
				cout << "Not a valid menu option, please try again" << endl;

		} while (!isValid);

		// return selected index in vector
		return selectedIndex;
	}

	void StudentView::displayExamStart(ExamAppModels::Exam* exam)
	{
		// Display exam start notification on UI
		cout << endl << exam->getName() << " exam started." << endl;

		//TODO: Add question navigation functionality
		//displayExamNavInstructions();
	}

	void StudentView::displayExamNavInstructions()
	{
		// Display exam navigation instructions on UI
		cout << endl << "*********** Exam Navigation ***********" << endl << endl;
		cout << "--p Go to previous question." << endl;
		cout << "--n Go to next question." << endl;
		cout << "--q:[question number] Go to specific question in exam." << endl;
		cout << "--e End the exam." << endl << endl;
		cout << "Type -- help at any time to view these controls again." << endl << endl;
	}

	int StudentView::displayExamQuestion(ExamAppModels::Question* question)
	{
		// Variable declaration and initialization
		string input = "";
		int answer = -1;
		int optionCount = question->getOptionCount();
		bool isValid = false;

		// Display question Id, text and options
		cout << endl << "*********** Question " << question->getId() << " ***********" << endl;
		cout << question->getQuestionText() << endl;
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

	void StudentView::displayExamSavedMessage(std::string examName)
	{
		// Display confirmation message on UI
		cout << endl << examName << " completed. Saved to file." << endl;
	}

	void StudentView::displayNoExamsAvailableMessage()
	{
		// Display message on UI
		cout << endl << "No exams available." << endl;
	}

	void StudentView::displayErrorOpeningExamMessage()
	{
		// Display error message on UI
		cout << endl << "Error: Exam template file could not be opened." << endl;
	}

	void StudentView::displayGradedExam(ExamAppModels::GradedExam* gradedExam)
	{
		// Display results
		cout << endl << "*********** Exam results for " << gradedExam->getName() << " ***********" << endl;
		cout << "Points Earned: " << gradedExam->getPointsScored() << endl;
		cout << "Points Possible: " << gradedExam->getTotalPoints() << endl;
		cout << "Grade: " << gradedExam->getScorePercentage() << "% (" << gradedExam->getLetterGrade() << ")" << endl;
	}

	ExamAppModels::StudentGradedExamMenuItems StudentView::displayGradedExamMenu()
	{
		// Variable declaration and initialization
		string input = "";
		ExamAppModels::StudentGradedExamMenuItems optionSelection = ExamAppModels::StudentGradedExamMenuItems::Unkown;
		bool isValid = false;

		// Display menu information
		cout << endl << "What would you like to do?" << endl;
		cout << "1 - View exam questions with answer key" << endl;
		cout << "2 - Go Back" << endl;

		// Valid input loop
		do
		{
			// Get input
			getline(cin, input);

			// Validate input
			try
			{
				optionSelection = static_cast<ExamAppModels::StudentGradedExamMenuItems>(stoi(input));
			}
			catch (...)
			{
				cout << "Not a valid menu option, please try again" << endl;
				continue;
			}

			switch (optionSelection)
			{
			case ExamAppModels::StudentGradedExamMenuItems::ViewQuestions:
			case ExamAppModels::StudentGradedExamMenuItems::GoBack:
				isValid = true;
				break;
			case ExamAppModels::StudentGradedExamMenuItems::Unkown:
			default:
				cout << "Not a valid menu option, please try again" << endl;
				break;
			}

		} while (!isValid);

		return optionSelection;
	}

	void StudentView::displayGradedExamQuestion(ExamAppModels::Question* question, ExamAppModels::AnswerKey* answerKey)
	{
		// Display question and answer key values
		cout << endl << "*********** Question " << question->getId() << " ***********" << endl;
		cout << question->getQuestionText() << endl;
		cout << question->getAnswerOptionsDisplay();
		cout << endl << "Your Answer: " << answerKey->getStudentAnswerValue() << endl;
		cout << "Correct Answer: " << answerKey->getAnswerKeyValue() << endl;
		cout << "Point Value: " << question->getPointValue() << endl;

		// Wait for input to continue
		cout << endl << "Press enter to continue..." << endl;
		string line;
		getline(cin, line);
	}

	void StudentView::displayEndofGradedQuestionsReached()
	{
		cout << endl << "End of exam questions reached" << endl;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
