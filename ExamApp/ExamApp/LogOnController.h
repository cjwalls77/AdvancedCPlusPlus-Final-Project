/*+===================================================================
File:      LogOnController.h

Summary:   Header file for LogOnController

Classes:   LogOnController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "Repository.h"

namespace ExamAppControllers
{
	/*+===================================================================
	Class:    LogOnController

	Summary:  Responsible for managing the UI for the Exam applications
			  logon process.  Uses the LogOnView to output to console.

	===================================================================+*/
	class LogOnController
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		LogOnController(ExamAppModels::Repository *repository);

		/*+===================================================================
			Destructor
		===================================================================+*/
		~LogOnController();

		/*+===================================================================
		Function: LogOnController::logOn

		Summary:  Present logon menu for exam application.

		Args:     None

		Returns:  LogOnRoles
					Selected logon menu option.
		===================================================================+*/
		ExamAppModels::LogOnRoles logOn();

		/*+===================================================================
		Function: LogOnController::getAuthenticatedStudent

		Summary:  Get currently authenticated student.
				  If no student authenticated retunrs null pointer.

		Args:     None

		Returns:  Student*
					Pointer to student object for id input from user.
		===================================================================+*/
		ExamAppModels::Student* getAuthenticatedStudent() const;

	private:
		ExamAppModels::Repository *repository;
		ExamAppModels::Student *authenticatedStudent;

	};
}
