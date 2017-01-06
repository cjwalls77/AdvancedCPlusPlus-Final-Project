/*+===================================================================
File:      TFQuestion.cpp

Summary:   Source file for TFQuestion

Classes:   TFQuestion

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "TFQuestion.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	TFQuestion::TFQuestion()
	{
	}

	TFQuestion::~TFQuestion()
	{
	}

	string TFQuestion::getAnswerOptionsDisplay()
	{
		// Variable declaration and initialization
		stringstream ss;

		// Provide T/F options
		ss << "1 - True" << endl << "2 - False" << endl;

		return ss.str();
	}

	std::string TFQuestion::getAnswerOptions()
	{
		// Variable declaration and initialization
		stringstream ss;

		// Provide T/F options
		ss << "True" << endl << "False" << endl;

		return ss.str();
	}

	int TFQuestion::getOptionCount()
	{
		return 2; // True/False
	}

	QuestionTypes TFQuestion::getQuestionType()
	{
		return QuestionTypes::TF;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
