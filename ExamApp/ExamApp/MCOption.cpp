/*+===================================================================
File:      MCOption.cpp

Summary:   Source file for MCOption

Classes:   LogOnController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "MCOption.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	MCOption::MCOption()
	{
		id = 0;
	}

	MCOption::~MCOption()
	{
	}

	int MCOption::getId() const
	{
		return id;
	}

	void MCOption::setId(int id)
	{
		this->id = id;
	}

	string MCOption::getText() const
	{
		return text;
	}

	void MCOption::setText(std::string text)
	{
		this->text = text;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
