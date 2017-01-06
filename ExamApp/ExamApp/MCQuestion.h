/*+===================================================================
File:      MCQuestion.h

Summary:   Header file for MCQuestion

Classes:   MCQuestion

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include <vector>
#include "Question.h"
#include "MCOption.h"

namespace ExamAppModels
{
	/*+===================================================================
	Class:    MCQuestion

	Summary:  Data Model for an exam MC question.

	===================================================================+*/
	class MCQuestion : public Question
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		MCQuestion();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~MCQuestion() override;

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		std::string getAnswerOptionsDisplay() override;
		std::string getAnswerOptions() override;
		int getOptionCount() override;
		void addOption(MCOption *option);
		virtual QuestionTypes getQuestionType() override;

	private:
		/*+===================================================================
		Private Member Variables
		===================================================================+*/
		std::vector<MCOption*> options;

		/*+===================================================================
		Function: clearOptions

		Summary:  Deallocate MCOption object pointers in options vector.

		Args:     None

		Returns:  None
		===================================================================+*/
		void clearOptions();

	};
}
