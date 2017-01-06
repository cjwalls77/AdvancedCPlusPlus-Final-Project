/*+===================================================================
File:      Exam.h

Summary:   Header file for Exam

Classes:   Exam

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include <vector>
#include "Question.h"

namespace ExamAppModels
{
	/*+===================================================================
	Class:    Exam

	Summary:  Data Model for an exam.

	===================================================================+*/
	class Exam {
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		Exam();

		/*+===================================================================
			Destructor
		===================================================================+*/
		virtual ~Exam();

		/*+===================================================================
		Function: Exam::getCurrentQuesiton

		Summary:  Get current question based on current question index.

		Args:     None

		Returns:  Question
					Pointer to current Question object.
		===================================================================+*/
		Question* getCurrentQuesiton();

		/*+===================================================================
		Function: Exam::nextQuestion

		Summary:  Get next question in exam.

		Args:     None

		Returns:  Question
					Pointer to next Question object,
					null pointer if at end of exam.
		===================================================================+*/
		Question* nextQuestion();

		/*+===================================================================
		Function: Exam::prevQuestion

		Summary:  Get previous question in exam.

		Args:     None

		Returns:  Question
					Pointer to previous Question object,
					null pointer if at begining of exam.
		===================================================================+*/
		Question* prevQuestion();

		/*+===================================================================
		Function: Exam::goToQuestion

		Summary:  Get question at specific index.

		Args:     index
					Index of question to go to.

		Returns:  Question
					Pointer to Question object at index provided,
					null pointer if not a valid index.
		===================================================================+*/
		Question* goToQuestion(int index);

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		int getId() const;
		void setId(int id);
		std::string getName() const;
		void setName(std::string name);
		void addQuestion(Question *question);
		int getQuestionCount() const;
		virtual void setAnswerValueCurrentQuestion(int value);

	protected:
		/*+===================================================================
			Protected Member Variables
		===================================================================+*/
		int currentQuestionIndex;
		std::vector<Question*> questions;

	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int id;
		std::string name;

		/*+===================================================================
		Function: clearQuestions

		Summary:  Deallocate pointers in quesitons vector

		Args:     None

		Returns:  None
		===================================================================+*/
		void clearQuestions();
	};
}
