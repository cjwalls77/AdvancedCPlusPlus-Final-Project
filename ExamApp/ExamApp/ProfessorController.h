/*+===================================================================
File:      ProfessorController.h

Summary:   Header file for ProfessorController

Classes:   ProfessorController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "Repository.h"
#include "Exam.h"

namespace ExamAppControllers
{
	/*+===================================================================
	Class:    ProfessorController

	Summary:  Responsible for managing the UI for the Exam applications
			  professor role.  Uses the ProfessorView to output to console.

	===================================================================+*/
	class ProfessorController
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		ProfessorController(ExamAppModels::Repository *repository);

		/*+===================================================================
			Destructor
		===================================================================+*/
		~ProfessorController();

		/*+===================================================================
		Function: ProfesssorController::logInAsProfessor

		Summary:  Present menu for professor role.

		Args:     None

		Returns:  None
		===================================================================+*/
		void logInAsProfessor() const;

	private:
		ExamAppModels::Repository *repository;

		/*+===================================================================
		Function: createExam

		Summary:  Present menu for professor role.

		Args:     None

		Returns:  None
		===================================================================+*/
		void createExam() const;

		/*+===================================================================
		Function: addTFQuestion

		Summary:  Add TF qustion to exam.

		Args:     examTemplate
					Exam template to add question to.
				  id
					Question id.

		Returns:  None
		===================================================================+*/
		static void addTFQuestion(ExamAppModels::Exam *examTemplate, int id);

		/*+===================================================================
		Function: addMCQuestion

		Summary:  Add MC qustion to exam.

		Args:     examTemplate
					Exam template to add question to.
				  id
					Qustion id.

		Returns:  None
		===================================================================+*/
		static void addMCQuestion(ExamAppModels::Exam *examTemplate, int id);
	};
}
