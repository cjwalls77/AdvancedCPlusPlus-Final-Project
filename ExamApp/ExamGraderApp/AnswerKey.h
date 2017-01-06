/*+===================================================================
File:      AnswerKey.h

Summary:   Header file for AnswerKey

Classes:   AnswerKey

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamGraderAppModels
{
	/*+===================================================================
	Class:    AnswerKey

	Summary:  Data Model for an answer key on exam rubric.

	===================================================================+*/
	class AnswerKey
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		AnswerKey();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~AnswerKey();

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		int getQuestionId() const;
		void setQuestionId(int id);
		int getKeyOptionValue() const;
		void setKeyOptionValue(int value);
		int getPointValue() const;
		void setPointValue(int value);

	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int questionId;
		int keyOptionValue;
		int pointValue;
	};
}
