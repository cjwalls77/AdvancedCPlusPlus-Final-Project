/*+===================================================================
File:      ExamRubric.cpp

Summary:   Source file for ExamRubric

Classes:   ExamRubric

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "AnswerKey.h"
#include <vector>

namespace ExamGraderAppModels
{
	/*+===================================================================
	Class:    ExamRubric

	Summary:  Data Model for an exam rubric.

	===================================================================+*/
	class ExamRubric
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		ExamRubric();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~ExamRubric();

		/*+===================================================================
		Getters / Setters
		===================================================================+*/
		int getExamId() const;
		void setExamId(int examId);
		void addAnswerKey(AnswerKey* answerKey);
		int getAnswerKeyValue(int index);
		int getAnswerKeyPointValue(int index);

	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int examId;
		std::vector<AnswerKey*> answerKeys;

		/*+===================================================================
		Function: clearAnswerKeys

		Summary:  Deallocate pointers in answer keys vector

		Args:     None

		Returns:  None
		===================================================================+*/
		void clearAnswerKeys();
	};
}
