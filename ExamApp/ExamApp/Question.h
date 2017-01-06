/*+===================================================================
File:      Question.h

Summary:   Header file for Question abstract class

Classes:   Question

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "Answer.h"

namespace ExamAppModels
{
	/*+===================================================================
	Class:    Question (Abstract)

	Summary:  Data Model for an exam question.
			  Abstract class to be derived from for all exam question types.

	===================================================================+*/
	class Question {
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		Question();

		/*+===================================================================
			Destructor
		===================================================================+*/
		virtual ~Question();

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		int getId() const;
		void setId(int id);
		std::string getQuestionText() const;
		void setQuestionText(std::string text);
		int getPointValue() const;
		void setPointValue(int value);
		int getAnswerValue() const;
		void setAnswerValue(int value) const;
		virtual QuestionTypes getQuestionType();
		virtual std::string getAnswerOptionsDisplay() = 0;
		virtual std::string getAnswerOptions() = 0;
		virtual int getOptionCount() = 0;


	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int id;
		std::string questionText;
		int pointValue;
		Answer *answer;
	};
}
