/*+===================================================================
File:      LogOnView.cpp

Summary:   Source file for LogOnView

Classes:   LogOnView

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "LogOnView.h"

using namespace std;

namespace ExamAppViews
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	void LogOnView::displayWelcomeMessage()
	{
		cout << endl << "Welcome to the Exam Application!" << endl << endl;
	}

	ExamAppModels::LogOnRoles LogOnView::displayRoleSelection()
	{
		// Variable declaration and initialization
		string input = "";
		ExamAppModels::LogOnRoles optionSelection = ExamAppModels::LogOnRoles::Unknown;
		bool isValid = false;

		// Display menu on UI
		cout << "Log On Options:" << endl << "1 - Student" << endl << "2 - Professor" << endl << "3 - Exit Applicaiton" << endl;

		// Menu loop
		do
		{
			// Get user input
			getline(cin, input);

			// Validate input
			try
			{
				optionSelection = static_cast<ExamAppModels::LogOnRoles>(stoi(input));
			}
			catch (...)
			{
				cout << "Not a valid menu option, please try again" << endl;
				continue;
			}

			switch (optionSelection)
			{
			case ExamAppModels::LogOnRoles::Student:
			case ExamAppModels::LogOnRoles::Professor:
			case ExamAppModels::LogOnRoles::Exit:
				isValid = true;
				break;
			default:
				cout << "Not a valid menu option, please try again." << endl;
				break;
			}
		} while (!isValid);

		return optionSelection;
	}

	int LogOnView::displayStudentIdInput()
	{
		cout << endl << "Please enter your student id." << endl;

		return getStudentId();
	}


	void LogOnView::displayStudentIdNotFoundMessage()
	{
		cout << endl << "Student id not found in student roster." << endl;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/

	int LogOnView::getStudentId()
	{
		// Variable declaration and initialization
		string input;
		int studentId = 0;
		bool isValid = false;

		// Get user input lool until valid
		do
		{
			getline(cin, input);

			try
			{
				studentId = stoi(input);
				isValid = true;
			}
			catch (...)
			{
				cout << "Not a valid student id, please try again" << endl;
			}
		} while (!isValid);

		return studentId;
	}
}
