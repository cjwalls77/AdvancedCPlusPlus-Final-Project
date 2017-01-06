/*+===================================================================
File:      GradedExam.h

Summary:   Header file for GradedExam

Classes:   GradedExam

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "Exam.h"
#include "AnswerKey.h"

namespace ExamAppModels
{
	/*+===================================================================
	Class:    Answer

	Summary:  Data Model for a graded exam.

	===================================================================+*/
	class GradedExam : public Exam
	{
	public:
		/*+===================================================================
		Constructor
		===================================================================+*/
		GradedExam();

		/*+===================================================================
		Destructor
		===================================================================+*/
		~GradedExam();

		/*+===================================================================
		Function: GradedExam::getAnswerKeyForCurrentQuestion

		Summary:  Get answer key value for current question

		Args:     None

		Returns:  Integer
					Answer Key value.
		===================================================================+*/
		int getAnswerKeyValueCurrentQuestion();

		/*+===================================================================
		Function: GradedExam::currentQuestionIsCorrect

		Summary:  Check if current question answer matches answer key

		Args:     None

		Returns:  Boolean
					Does answer match answer key value.
		===================================================================+*/
		bool currentQuestionIsCorrect();

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		int getScorePercentage() const;
		char getLetterGrade() const;
		int getTotalPoints() const;
		void setTotalPoints(int points);
		int getPointsScored() const;
		void setPointsScored(int points);
		void setAnswerValueCurrentQuestion(int value) override;
		void addAnswerKey(AnswerKey *key);
		AnswerKey* goToAnswerKey(int index);

	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int totalPoints;
		int pointsScored;
		std::vector<AnswerKey*> answerKeys;

		/*+===================================================================
		Function: clearAnswerKeys

		Summary:  Deallocate pointers in answerKey vector

		Args:     None

		Returns:  None
		===================================================================+*/
		void clearAnswerKeys();
	};
}
