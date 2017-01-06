/*+===================================================================
File:      TFQuestion.h

Summary:   Header file for TFQuestion

Classes:   TFQuestion

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "Question.h"

namespace ExamAppModels
{
	/*+===================================================================
	Class:    TFQuestion

	Summary:  Data Model for an exam TF question.

	===================================================================+*/
	class TFQuestion : public Question
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		TFQuestion();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~TFQuestion() override;

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		std::string getAnswerOptionsDisplay() override;
		std::string getAnswerOptions() override;
		int getOptionCount() override;
		virtual QuestionTypes getQuestionType() override;
	};
}
