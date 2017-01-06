/*+===================================================================
File:      AnswerSheet.cpp

Summary:   Source file for AnswerSheet

Classes:   AnswerSheet

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "AnswerSheet.h"

using namespace std;

namespace ExamGraderAppModels
{
	/*+===================================================================
		Public Members
	===================================================================+*/
	AnswerSheet::AnswerSheet()
	{
		examId = 0;
		questionCount = 0;
		studentId = 0;
		totalPoints = 0;
		pointsScored = 0;
	}

	AnswerSheet::~AnswerSheet()
	{
		clearAnswers();
	}

	int AnswerSheet::getExamId() const
	{
		return examId;
	}

	void AnswerSheet::setExamId(int id)
	{
		this->examId = id;
	}

	std::string AnswerSheet::getExamName() const
	{
		return examName;
	}

	void AnswerSheet::setExamName(std::string name)
	{
		this->examName = name;
	}

	int AnswerSheet::getQuestionCount() const
	{
		return questionCount;
	}

	void AnswerSheet::setQuestionCount(int count)
	{
		this->questionCount = count;
	}

	int AnswerSheet::getStudentId() const
	{
		return studentId;
	}

	void AnswerSheet::setStudentId(int id)
	{
		this->studentId = id;
	}

	int AnswerSheet::getTotalPoints() const
	{
		return totalPoints;
	}

	void AnswerSheet::setTotalPoints(int points)
	{
		this->totalPoints = points;
	}

	int AnswerSheet::getPointsScored() const
	{
		return pointsScored;
	}

	void AnswerSheet::setPointsScored(int points)
	{
		this->pointsScored = points;
	}

	void AnswerSheet::addAnswer(Answer* answer)
	{
		this->answers.push_back(answer);
	}

	int AnswerSheet::getAnswerValue(int index)
	{
		try
		{
			return answers[index]->getOptionValue();
		}
		catch(...)
		{
			return -1; // No answer
		}
	}

	int AnswerSheet::getAnswerQuestionId(int index)
	{
		try
		{
			return answers[index]->getQuestionId();
		}
		catch(...)
		{
			return 0; // Default value for id
		}
	}

	AnswerSheet& AnswerSheet::operator+=(const int pointValue)
	{
		this->setPointsScored(this->getPointsScored() + pointValue);
		return *this;
	}

	void AnswerSheet::gradeAnswerSheet(ExamRubric &examRubric)
	{
		int total = 0;
		try
		{
			for (int i = 0; i < this->questionCount; i++)
			{
				total += examRubric.getAnswerKeyPointValue(i);
				if (this->answers[i]->getOptionValue() == examRubric.getAnswerKeyValue(i))
				{
					// Add points to grade total if answer is correct
					(*this) += examRubric.getAnswerKeyPointValue(i);
				}
			}
		}
		catch (...)
		{
			// answer sheet or exam rubric not in correct format
		}

		this->totalPoints = total;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/

	void AnswerSheet::clearAnswers()
	{
		// Loop over vector to deallocate memory and remove items from vector
		while (!answers.empty())
		{
			delete answers.back();
			answers.pop_back();
		}
	}
}
