/*+===================================================================
File:      AnswerKey.cpp

Summary:   Source file for AnswerKey

Classes:   AnswerKey

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "AnswerKey.h"

namespace ExamGraderAppModels
{
	/*+===================================================================
		Public Members
	===================================================================+*/
	AnswerKey::AnswerKey()
	{
		questionId = 0;
		pointValue = 0;
		keyOptionValue = 0;
	}

	AnswerKey::~AnswerKey()
	{
	}

	int AnswerKey::getQuestionId() const
	{
		return questionId;
	}

	void AnswerKey::setQuestionId(int id)
	{
		this->questionId = id;
	}

	int AnswerKey::getKeyOptionValue() const
	{
		return keyOptionValue;
	}

	void AnswerKey::setKeyOptionValue(int value)
	{
		this->keyOptionValue = value;
	}

	int AnswerKey::getPointValue() const
	{
		return pointValue;
	}

	void AnswerKey::setPointValue(int value)
	{
		this->pointValue = value;
	}
}
