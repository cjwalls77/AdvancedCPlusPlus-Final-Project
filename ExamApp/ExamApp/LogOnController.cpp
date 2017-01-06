/*+===================================================================
File:      LogOnController.cpp

Summary:   Source file for LogOnController

Classes:   LogOnController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "LogOnController.h"
#include "LogOnView.h"
#include "Repository.h"

using namespace std;

namespace ExamAppControllers
{
	/*+===================================================================
		Public Members
	===================================================================+*/

	LogOnController::LogOnController(ExamAppModels::Repository * repository)
	{
		this->repository = repository;
		this->authenticatedStudent = nullptr;
	}

	LogOnController::~LogOnController()
	{
		delete authenticatedStudent;
	}

	ExamAppModels::LogOnRoles LogOnController::logOn()
	{
		// Variable declaration and initialization
		ExamAppModels::LogOnRoles role = ExamAppModels::LogOnRoles::Unknown;
		int studentId = 0;
		bool isValid = false;

		// Menu loop
		do
		{
			// Welcome Message
			ExamAppViews::LogOnView::displayWelcomeMessage();
			// Display role menu and return user menu selection
			role = ExamAppViews::LogOnView::displayRoleSelection();

			// If role selected is student prompt for student id
			if (role == ExamAppModels::LogOnRoles::Student)
			{
				studentId = ExamAppViews::LogOnView::displayStudentIdInput();

				// check if student id provided is int student roster file
				//IMPORTANT: Student instantiated must be mangaged by this class
				authenticatedStudent = repository->getStudent(studentId);

				// Check if student found
				if (authenticatedStudent != nullptr)
				{
					isValid = true;
				}
				else
				{
					ExamAppViews::LogOnView::displayStudentIdNotFoundMessage();
				}
			}
			else
			{
				isValid = true;
			}
		} while (!isValid);

		// return selected role
		return role;
	}

	ExamAppModels::Student* LogOnController::getAuthenticatedStudent() const
	{
		return authenticatedStudent;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
