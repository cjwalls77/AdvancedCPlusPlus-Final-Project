/*+===================================================================
File:      MenuOptions.h

Summary:   Enums for Menu Options.

Classes:   LogOnRoles, StudentMenuItems, StudentGradedExamMenuItems,
		   ProfessorMenuItems

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamAppModels
{
	/*+===================================================================
	Class:    LogOnRoles

	Summary:  Menu options for role logon.

	===================================================================+*/
	enum class LogOnRoles { Unknown = 0, Student = 1, Professor = 2, Exit = 3 };

	/*+===================================================================
	Class:    StudentMenuItems

	Summary:  Menu options for student main menu.

	===================================================================+*/
	enum class StudentMenuItems { Unkown = 0, TakeExam = 1, ViewExam = 2, Logout = 3 };

	/*+===================================================================
	Class:    StudentGradedExamMenuItems

	Summary:  Menu options for student graded exam menu.

	===================================================================+*/
	enum class StudentGradedExamMenuItems { Unkown = 0, ViewQuestions = 1, GoBack = 2 };

	/*+===================================================================
	Class:    ProfessorMenuItems

	Summary:  Menu options for professor main menu.

	===================================================================+*/
	enum class ProfessorMenuItems { Unkown = 0, CreateExam = 1, Logout = 2 };
}
