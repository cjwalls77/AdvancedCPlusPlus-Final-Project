/*+===================================================================
File:      ExamRubric.cpp

Summary:   Source file for ExamRubric

Classes:   ExamRubric

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "ExamRubric.h"

namespace ExamGraderAppModels
{
	/*+===================================================================
		Public Members
	===================================================================+*/
	ExamGraderAppModels::ExamRubric::ExamRubric()
	{
		this->examId = 0;
	}

	ExamGraderAppModels::ExamRubric::~ExamRubric()
	{
		clearAnswerKeys();
	}

	int ExamRubric::getExamId() const
	{
		return examId;
	}

	void ExamRubric::setExamId(int examId)
	{
		this->examId = examId;
	}

	void ExamGraderAppModels::ExamRubric::addAnswerKey(AnswerKey* answerKey)
	{
		this->answerKeys.push_back(answerKey);
	}

	int ExamRubric::getAnswerKeyValue(int index)
	{
		try
		{
			return this->answerKeys[index]->getKeyOptionValue();
		}
		catch (...)
		{
			return -1; // No answer
		}
	}

	int ExamRubric::getAnswerKeyPointValue(int index)
	{
		try
		{
			return answerKeys[index]->getPointValue();
		}
		catch(...)
		{
			return 0;  // defalut value no points
		}
	}

	/*+===================================================================
	Private Members
	===================================================================+*/

	void ExamRubric::clearAnswerKeys()
	{
		// Loop over vector to deallocate memory and remove items from vector
		while (!answerKeys.empty())
		{
			delete answerKeys.back();
			answerKeys.pop_back();
		}
	}
}
