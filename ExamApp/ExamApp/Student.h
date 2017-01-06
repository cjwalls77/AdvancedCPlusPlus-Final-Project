/*+===================================================================
File:      Student.h

Summary:   Header file for Student

Classes:   Student

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamAppModels
{
	/*+===================================================================
	Class:    Student

	Summary:  Data Model for a student.

	===================================================================+*/
	class Student
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		Student();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~Student();

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		int getId() const;
		void setId(int id);
		std::string getFirstName() const;
		void setFirstName(std::string name);
		std::string getLastName() const;
		void setLastName(std::string name);
		std::string getFullName() const;


	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int id;
		std::string firstName;
		std::string lastName;
	};
}
