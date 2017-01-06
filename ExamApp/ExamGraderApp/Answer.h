/*+===================================================================
File:      Answer.h

Summary:   Header file for Answer

Classes:   Answer

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamGraderAppModels
{
	/*+===================================================================
	Class:    Answer

	Summary:  Data Model for an answer on answer sheet.

	===================================================================+*/
	class Answer
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		Answer();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~Answer();

		/*+===================================================================
		Getters / Setters
		===================================================================+*/
		int getQuestionId();
		void setQuestionId(int id);
		int getOptionValue() const;
		void setOptionValue(int value);

	private:
		int questionId;
		int optionValue;
	};
}
