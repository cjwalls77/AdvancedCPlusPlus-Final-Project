/*+===================================================================
File:      AnswerSheet.cpp

Summary:   Source file for AnswerSheet

Classes:   AnswerSheet

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "Answer.h"
#include "ExamRubric.h"
#include "AnswerKey.h"
#include <vector>

namespace ExamGraderAppModels
{
	/*+===================================================================
	Class:    AnswerSheet

	Summary:  Data Model for an exam answer sheet.

	===================================================================+*/
	class AnswerSheet
	{
	public:
		/*+===================================================================
		Constructor
		===================================================================+*/
		AnswerSheet();

		/*+===================================================================
		Destructor
		===================================================================+*/
		~AnswerSheet();

		/*+===================================================================
		Getters / Setters
		===================================================================+*/
		int getExamId() const;
		void setExamId(int id);
		std::string getExamName() const;
		void setExamName(std::string name);
		int getQuestionCount() const;
		void setQuestionCount(int count);
		int getStudentId() const;
		void setStudentId(int id);
		int getTotalPoints() const;
		void setTotalPoints(int points);
		int getPointsScored() const;
		void setPointsScored(int points);
		void addAnswer(Answer* answer);
		int getAnswerValue(int index);
		int getAnswerQuestionId(int index);

		/*+===================================================================
			Operator Overloads
		===================================================================+*/
		AnswerSheet& operator+=(const int pointValue);


		/*+===================================================================
		Function: AnswerSheet::gradeAnswerSheet

		Summary:  Grade an answer sheet and update point score.

		Args:     ExamRubric
		Reference to exam rubric for answer sheet.

		Returns:  None
		===================================================================+*/
		void gradeAnswerSheet(ExamRubric &examRubric);

	private:
		/*+===================================================================
		Private Member Variables
		===================================================================+*/
		int examId;
		std::string examName;
		int questionCount;
		int studentId;
		int totalPoints;
		int pointsScored;
		std::vector<Answer*> answers;

		/*+===================================================================
		Function: clearAnswers

		Summary:  Deallocate pointers in answers vector

		Args:     None

		Returns:  None
		===================================================================+*/
		void clearAnswers();
	};
}
