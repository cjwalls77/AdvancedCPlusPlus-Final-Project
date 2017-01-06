/*+===================================================================
File:      Question.cpp

Summary:   Source file for Question

Classes:   Question

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "Question.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	Question::Question()
	{
		id = 0;
		pointValue = 0;
		questionText = "";
		answer = new Answer();
	}

	Question::~Question()
	{
		delete answer;
	}

	int Question::getId() const
	{
		return id;
	}

	void Question::setId(int id)
	{
		this->id = id;
	}

	string Question::getQuestionText() const
	{
		return questionText;
	}

	void Question::setQuestionText(std::string text)
	{
		this->questionText = text;
	}

	int Question::getPointValue() const
	{
		return pointValue;
	}

	void Question::setPointValue(int value)
	{
		this->pointValue = value;
	}

	int Question::getAnswerValue() const
	{
		return answer->getOptionValue();
	}

	void Question::setAnswerValue(int value) const
	{
		answer->setOptionValue(value);
	}

	QuestionTypes Question::getQuestionType()
	{
		return QuestionTypes::Unknown;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
