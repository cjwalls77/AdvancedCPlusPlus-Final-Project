/*+===================================================================
File:      AnswerKey.cpp

Summary:   Source file for AnswerKey

Classes:   AnswerKey

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "AnswerKey.h"

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	AnswerKey::AnswerKey()
	{
		questionId = 0;
		answerKeyValue = -1; // No Answer
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

	int AnswerKey::getAnswerKeyValue() const
	{
		return  answerKeyValue;
	}

	void AnswerKey::setAnswerKeyValue(int value)
	{
		this->answerKeyValue = value;
	}

	int AnswerKey::getStudentAnswerValue() const
	{
		return studentAnswerValue;
	}

	void AnswerKey::setStudentAnswerValue(int value)
	{
		this->studentAnswerValue = value;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
