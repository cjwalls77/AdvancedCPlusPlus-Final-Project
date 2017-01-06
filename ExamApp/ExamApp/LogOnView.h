/*+===================================================================
File:      LogOnView.h

Summary:   Header file for LogOnView

Classes:   LogOnView

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "MenuOptions.h"

namespace ExamAppViews
{
	/*+===================================================================
	Class:    LogOnView

	Summary:  Manages UI output/input for application logon.

	===================================================================+*/
	class LogOnView
	{
	public:
		/*+===================================================================
		Function: LogOnController::displayWelcomeMessage

		Summary:  Display welecom message on UI.

		Args:     None

		Returns:  None
		===================================================================+*/
		static void displayWelcomeMessage();

		/*+===================================================================
		Function: LogOnController::displayRoleSelection

		Summary:  Display role selection on UI and retrive valid menu selection.

		Args:     None

		Returns:  LogOnRoles
					Logon menu option selected.
		===================================================================+*/
		static ExamAppModels::LogOnRoles displayRoleSelection();

		/*+===================================================================
		Function: LogOnController::displayStudentIdInput

		Summary:  Dispaly UI for student id prompt get valid id input.

		Args:     None

		Returns:  int
					Student id.
		===================================================================+*/
		static int displayStudentIdInput();

		/*+===================================================================
		Function: LogOnController::displayStudentIdNotFoundMessage

		Summary:  Display UI message indicating student id not found in roster.

		Args:     None

		Returns:  None
		===================================================================+*/
		static void displayStudentIdNotFoundMessage();

	private:
		/*+===================================================================
		Function: getStudentId

		Summary:  Helper method to validate student id input.

		Args:     None

		Returns:  int
					Student id.
		===================================================================+*/
		static int getStudentId();
	};
}
