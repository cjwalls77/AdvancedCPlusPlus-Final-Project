/*+===================================================================
File:      Exam.cpp

Summary:   Source file for Exam

Classes:   LogOnController

Origin:    New file created for this assignment,
code refactored from previous assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "GradedExam.h"
#include "AnswerChangeException.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	GradedExam::GradedExam()
	{
		totalPoints = 0;
		pointsScored = 0;
	}

	GradedExam::~GradedExam()
	{
		clearAnswerKeys();
	}

	int GradedExam::getAnswerKeyValueCurrentQuestion()
	{
		// Answer keys will be in same order as questions
		return answerKeys[currentQuestionIndex]->getAnswerKeyValue();
	}

	bool GradedExam::currentQuestionIsCorrect()
	{
		if (questions[currentQuestionIndex]->getAnswerValue() == answerKeys[currentQuestionIndex]->getAnswerKeyValue())
			return true;
		else
			return false;
	}

	int GradedExam::getScorePercentage() const
	{
		// Calcualte score precentage from exam points
		try
		{
			// Convert to integer for display of score from 0-100 no decimals (loss of precision ok)
			int scorePercentage = (static_cast<double>(pointsScored) / static_cast<double>(totalPoints)) * 100;
			return scorePercentage;
		}
		catch (...)
		{
			return 0;
		}
	}

	char GradedExam::getLetterGrade() const
	{
		double score = getScorePercentage();

		// Taken from example in course powerpoint by Dr. B
		if (score > 89)
			return 'A';
		else if (score > 79)
			return 'B';
		else if (score > 69)
			return 'C';
		else if (score > 59)
			return 'D';
		else
			return 'F';
	}

	int GradedExam::getTotalPoints() const
	{
		return totalPoints;
	}

	void GradedExam::setTotalPoints(int points)
	{
		this->totalPoints = points;
	}

	int GradedExam::getPointsScored() const
	{
		return pointsScored;
	}

	void GradedExam::setPointsScored(int points)
	{
		this->pointsScored = points;
	}

	void GradedExam::setAnswerValueCurrentQuestion(int value)
	{

		// Throw exception if answer value is trying to be changed on graded exam
		throw CustomExceptions::AnswerChangeException();
	}

	void GradedExam::addAnswerKey(AnswerKey* key)
	{
		this->answerKeys.push_back(key);
	}

	AnswerKey* GradedExam::goToAnswerKey(int index)
	{
		return answerKeys[index];
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
	void GradedExam::clearAnswerKeys()
	{
		// Loop over vector to deallocate memory and remove items from vector
		while (!answerKeys.empty())
		{
			delete answerKeys.back();
			answerKeys.pop_back();
		}
	}
}
