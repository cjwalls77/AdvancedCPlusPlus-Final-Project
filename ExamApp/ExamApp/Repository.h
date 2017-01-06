/*+===================================================================
File:      Repository.h

Summary:   Header file for Repository interface

Classes:   Repository

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include <vector>
#include "Exam.h"
#include "GradedExam.h"
#include "Student.h"
#include "IndexItem.h"

namespace ExamAppModels
{
	/*+===================================================================
	Class:    Repository (Interface)

	Summary:  Interface for data repository.

	===================================================================+*/
	class Repository
	{
	public:
		/*+===================================================================
			Destructor
		===================================================================+*/
		virtual ~Repository() {};

		/*+===================================================================
		Function: Repository::getStudent

		Summary:  Get Student from roster.

		Args:     studentId
					Id for student to be found in roster.

		Returns:  Student*
					Pointer to Student object matching id.
		===================================================================+*/
		virtual Student* getStudent(int studentId) = 0;

		/*+===================================================================
		Function: Repository::getNewExam

		Summary:  Get new exam from exam template.

		Args:     item
					Pointer for IndexItem of exam template.

		Returns:  Exam*
					Pointer to Exam object of new exam created from template.
		===================================================================+*/
		virtual Exam* getNewExam(IndexItem *item) = 0;

		/*+===================================================================
		Function: Repository::getGradedExam

		Summary:  Get graded exam.

		Args:     None

		Returns:  Exam*
					Pointer to graded Exam object.
		===================================================================+*/
		virtual GradedExam* getGradedExam(IndexItem *item) = 0;

		/*+===================================================================
		Function: Repository::getExamTemplateIndex

		Summary:  Get index items for exam templates directory.

		Args:     None

		Returns:  vector<IndexItem*>*
					Pointer to vector of IndexItem object pointers for
					exam template directory.
		===================================================================+*/
		virtual std::vector<IndexItem*>* getExamTemplateIndex() = 0;

		/*+===================================================================
		Function: Repository::getGradedExamIndex

		Summary:  Get index items for graded exam directory.

		Args:     studentId
					Id for student to get graded exams for.

		Returns:  vector<IndexItem*>*
					Pointer to vector of IndexItem object pointers for
					graded exams directory.
		===================================================================+*/
		virtual std::vector<IndexItem*>* getGradedExamIndex(int studentId) = 0;

		/*+===================================================================
		Function: Repository::saveExamTemplate

		Summary:  Save exam template to application file directories.

		Args:     exam
					Pointer to Exam object to be saved.

		Returns:  Boolean
					Is success.
		===================================================================+*/
		virtual bool saveExamTemplate(Exam *exam) = 0;

		/*+===================================================================
		Function: Repository::savePendingExam

		Summary:  Save answer sheet to pending exams directory.

		Args:     exam
					Pointer to Exam object to be saved.
				  student
					Pointer to Student current authenticated student.

		Returns:  Boolean
					Is success.
		===================================================================+*/
		virtual bool savePendingExam(Exam *exam, Student *student) = 0;
	};
}
