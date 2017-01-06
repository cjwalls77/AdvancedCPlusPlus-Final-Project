/*+===================================================================
File:      Answer.cpp

Summary:   Source file for Answer

Classes:   Answer

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "Answer.h"

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	Answer::Answer()
	{
		optionValue = -1; // No Answer
	}

	Answer::~Answer()
	{
	}

	int Answer::getOptionValue() const
	{
		return optionValue;
	}

	void Answer::setOptionValue(int value)
	{
		this->optionValue = value;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
