/*+===================================================================
File:      Exam.cpp

Summary:   Source file for Exam

Classes:   LogOnController

Origin:    New file created for this assignment,
		   code refactored from previous assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "Exam.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	Exam::Exam()
	{
		id = 0;
		currentQuestionIndex = 0; // first question of exam
	}

	Exam::~Exam()
	{
		clearQuestions();
	}

	Question* Exam::getCurrentQuesiton()
	{
		return questions[currentQuestionIndex];
	}

	Question* Exam::nextQuestion()
	{
		// Check if at first question in exam
		if (currentQuestionIndex == (getQuestionCount() - 1))
			return nullptr;

		currentQuestionIndex++;

		return questions[currentQuestionIndex];
	}

	Question* Exam::prevQuestion()
	{
		// Check if at last question in exam
		if (currentQuestionIndex == 0)
			return nullptr;

		currentQuestionIndex--;

		return questions[currentQuestionIndex];
	}

	Question* Exam::goToQuestion(int index)
	{
		// Check if index is in range
		if (index < 0 && index > getQuestionCount())
			return nullptr;

		return questions[index];
	}

	int Exam::getId() const
	{
		return id;
	}

	void Exam::setId(int id)
	{
		this->id = id;
	}

	std::string Exam::getName() const
	{
		return  name;
	}

	void Exam::setName(std::string name)
	{
		this->name = name;
	}

	void Exam::addQuestion(Question* question)
	{
		questions.push_back(question);
	}

	int Exam::getQuestionCount() const
	{
		return questions.size();
	}

	void Exam::setAnswerValueCurrentQuestion(int value)
	{
		questions[currentQuestionIndex]->setAnswerValue(value);
	}

	/*+===================================================================
	Private Members
	===================================================================+*/

	void Exam::clearQuestions()
	{
		// Loop over vector to deallocate memory and remove items from vector
		while (!questions.empty())
		{
			delete questions.back();
			questions.pop_back();
		}
	}
}
