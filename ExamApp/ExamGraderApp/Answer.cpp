/*+===================================================================
File:      Answer.cpp

Summary:   Source file for Answer

Classes:   Answer

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "Answer.h"

namespace ExamGraderAppModels
{
	/*+===================================================================
		Public Members
	===================================================================+*/
	Answer::Answer()
	{
	}

	Answer::~Answer()
	{
	}

	int Answer::getQuestionId()
	{
		return questionId;
	}

	void Answer::setQuestionId(int id)
	{
		this->questionId = id;
	}

	int Answer::getOptionValue() const
	{
		return optionValue;
	}

	void Answer::setOptionValue(int value)
	{
		this->optionValue = value;
	}
}
