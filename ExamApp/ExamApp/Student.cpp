/*+===================================================================
File:      Student.cpp

Summary:   Source file for Student

Classes:   Student

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "Student.h"

using namespace std;

namespace ExamAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	Student::Student()
	{
		id = 0;
		firstName = "";
		lastName = "";
	}

	Student::~Student()
	{
	}

	int Student::getId() const
	{
		return id;
	}

	void Student::setId(int id)
	{
		this->id = id;
	}

	std::string Student::getFirstName() const
	{
		return firstName;
	}

	void Student::setFirstName(std::string name)
	{
		this->firstName = name;
	}

	std::string Student::getLastName() const
	{
		return lastName;
	}

	void Student::setLastName(std::string name)
	{
		this->lastName = name;
	}

	std::string Student::getFullName() const
	{
		// Variable declaration and initialization
		ostringstream stream;

		// Combine first and last names
		stream << firstName << " " << lastName;

		return stream.str();
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
