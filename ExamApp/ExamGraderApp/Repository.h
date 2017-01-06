/*+===================================================================
File:      Repository.h

Summary:   Header file for Repository interface

Classes:   Repository

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include <vector>
#include "AnswerSheet.h"
#include "IndexItem.h"
#include "ExamRubric.h"

namespace ExamGraderAppModels
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
		Function: Repository::getAnswerSheetIndex

		Summary:  Get index for pending_exams directory.

		Args:     None

		Returns:  vector<IndexItem*>
					IndexItem collection for pending_exams directory.
		===================================================================+*/
		virtual std::vector<IndexItem*>* getAnswerSheetIndex() =0;

		/*+===================================================================
		Function: Repository::getAnswerSheet

		Summary:  Get new exam from exam template.

		Args:     item
					IndexItem for item in pending_exams directory.

		Returns:  AnswerSheet*
					Pointer to AnswerSheet loaded from index item in directory.
		===================================================================+*/
		virtual AnswerSheet* getAnswerSheet(IndexItem *item) =0;

		/*+===================================================================
		Function: Repository::getExamRubricIndex

		Summary:  Get index for exam_rubrics directory.

		Args:     None

		Returns:  vector<IndexItem*>
					IndexItem collection for exam_rubrics directory.
		===================================================================+*/
		virtual std::vector<IndexItem*>* getExamRubricIndex() =0;

		/*+===================================================================
		Function: Repository::getExamRubric

		Summary:  Load an exam rubric from an exam template.

		Args:     item
					IndexItem for item in exam_rubric directory.

		Returns:  ExamRubric*
					Pointer to exam rubric.
		===================================================================+*/
		virtual ExamRubric* getExamRubric(IndexItem *item) =0;

		/*+===================================================================
		Function: Repository::getExamRubricForExam

		Summary:  Load an exam rubric from an exam template for provided exam id.

		Args:     examId
					Id for exam.

		Returns:  ExamRubric*
					Pointer to exam rubric.
		===================================================================+*/
		virtual ExamRubric* getExamRubricForExam(int examId) = 0;

		/*+===================================================================
		Function: Repository::saveGradedAnswerSheet

		Summary:  Save graded answer sheet to graded_exams directory.

		Args:     answerSheet
					Reference to graded answer sheet.
				  examRubric
					Reference to exam rubric for exam answer sheet.

		Returns:  None
		===================================================================+*/
		virtual void saveGradedAnswerSheet(AnswerSheet &answersheet, ExamRubric &examRubric) =0;

		/*+===================================================================
		Function: Repository::removeAnswerSheetFromPending

		Summary:  Remove answer sheet file from pending_exam index

		Args:     indexId
					Id for answer sheet file index in directory.

		Returns:  None
		===================================================================+*/
		virtual void removeAnswerSheetFromPending(int indexId) =0;
	};
}

