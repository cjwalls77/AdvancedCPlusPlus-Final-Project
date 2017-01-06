/*+===================================================================
File:      LogOnController.cpp

Summary:   Source file for LogOnController

Classes:   LogOnController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "MCQuestion.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	MCQuestion::MCQuestion()
	{
	}

	MCQuestion::~MCQuestion()
	{
		clearOptions();
	}

	string MCQuestion::getAnswerOptionsDisplay()
	{
		// Variable declaration and initialization
		ostringstream ss;

		// Get string on MC options
		for (vector<MCOption*>::iterator it = options.begin(); it != options.end(); ++it)
		{
			ss << (*it)->getId() << " - " << (*it)->getText() << endl;
		}

		return ss.str();
	}

	std::string MCQuestion::getAnswerOptions()
	{
		// Variable declaration and initialization
		ostringstream ss;

		// Get string on MC options
		for (vector<MCOption*>::iterator it = options.begin(); it != options.end(); ++it)
		{
			ss << (*it)->getText() << endl;
		}

		return ss.str();
	}

	int MCQuestion::getOptionCount()
	{
		return options.size();
	}

	void MCQuestion::addOption(MCOption* option)
	{
		options.push_back(option);
	}

	QuestionTypes MCQuestion::getQuestionType()
	{
		return QuestionTypes::MC;
	}

	void MCQuestion::clearOptions()
	{
		// Loop over vector to deallocate pointers to MCOption objects
		while (!options.empty())
		{
			delete options.back();
			options.pop_back();
		}
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
