/*+===================================================================
File:      AnswerChangeException.h

Summary:   Header file for AnswerChangeException

Classes:   AnswerChangeException

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace CustomExceptions
{
	/*+===================================================================
	Class:    AnswerChangeException

	Summary:  Exception thrown when attempting to change answer on graded exam

	===================================================================+*/
	class AnswerChangeException : public std::logic_error
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		explicit AnswerChangeException()
			: logic_error("Error: Modify Graded Exam Answer Not Allowed") {}
	};
}
