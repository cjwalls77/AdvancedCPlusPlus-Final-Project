/*+===================================================================
File:      StudentController.h

Summary:   Header file for StudentController

Classes:   StudentController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

#include "Repository.h"

namespace ExamAppControllers
{
	/*+===================================================================
	Class:    StudentController

	Summary:  Responsible for managing the UI for the Exam applications
			  student role.  Uses the StudentView to output to console.

	===================================================================+*/
	class StudentController
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		StudentController(ExamAppModels::Repository *repository);

		/*+===================================================================
			Destructor
		===================================================================+*/
		~StudentController();

		/*+===================================================================
		Function: StudentController::setStudent

		Summary:  Set current authenticated user for exam application.

		Args:     student
					Pointer to student object.

		Returns:  None
		===================================================================+*/
		void setStudent(ExamAppModels::Student* student);

		/*+===================================================================
		Function: StudentController::logInAsStudent

		Summary:  Present main menu for student role.

		Args:     None

		Returns:  None
		===================================================================+*/
		void logInAsStudent() const;

	private:
		ExamAppModels::Repository* repository;
		ExamAppModels::Student* student;

		/*+===================================================================
		Function: selectExam

		Summary:  Show list of available exam templtes, prompts user to select
				  an exam.  Starts exam once a valid choice is provided.

		Args:     None

		Returns:  None
		===================================================================+*/
		void selectExam() const;

		/*+===================================================================
		Function: startExam

		Summary:  Manages UI for taking an exam and providing answers to questions.

		Args:     exam
					Pointer to an Exam object to be started by student.

		Returns:  None
		===================================================================+*/
		void startExam(ExamAppModels::Exam *exam) const;

		/*+===================================================================
		Function: getAuthenticatedStudent

		Summary:  Save exam to file and notify student on UI.

		Args:     exam
					Pointer to an Exam object to be ended
					and saved to answer sheet file.

		Returns:  None
		===================================================================+*/
		void endExam(ExamAppModels::Exam *exam) const;

		/*+===================================================================
		Function: selectGradedExam

		Summary:  Show list of available graded exams for the student, prompts user to select
		an exam.

		Args:     None

		Returns:  None
		===================================================================+*/
		void selectGradedExam() const;

		/*+===================================================================
		Function: viewGradedExam

		Summary:  Manages UI for viewing a graded exam.

		Args:     gradedExam
					Pointer to an GradedExam object selected by student.

		Returns:  None
		===================================================================+*/
		static void viewGradedExam(ExamAppModels::GradedExam *gradedExam);

		/*+===================================================================
		Function: viewGradedExamQuestions

		Summary:  Manages UI for viewing graded exam questions.

		Args:     gradedExam
					Pointer to an GradedExam object selected by student.

		Returns:  None
		===================================================================+*/
		static void viewGradedExamQuestions(ExamAppModels::GradedExam *gradedExam);

		/*+===================================================================
		Function: clearIndexItems

		Summary:  Deallocates memory for IndexItem pointers held in vector.

		Args:     items
					Pointer to a vector of IndexItem pointers to be deallocated.

		Returns:  None
		===================================================================+*/
		static void clearIndexItems(std::vector<ExamAppModels::IndexItem*>* items);
	};
}
