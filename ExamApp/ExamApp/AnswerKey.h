/*+===================================================================
File:      AnswerKey.h

Summary:   Header file for AnswerKey

Classes:   AnswerKey

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamAppModels
{
	/*+===================================================================
	Class:    AnswerKey

	Summary:  Data Model for an answer key item.

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
		int getAnswerKeyValue() const;
		void setAnswerKeyValue(int value);
		int getStudentAnswerValue() const;
		void setStudentAnswerValue(int value);

	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int questionId;
		int answerKeyValue;
		int studentAnswerValue;
	};
}
