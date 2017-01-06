/*+===================================================================
File:      StudentController.cpp

Summary:   Source file for StudentController

Classes:   StudentController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "StudentController.h"
#include "StudentView.h"

using namespace std;

namespace ExamAppControllers
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	StudentController::StudentController(ExamAppModels::Repository* repository)
	{
		this->repository = repository;
		this->student = nullptr;
	}

	StudentController::~StudentController()
	{
	}

	void StudentController::setStudent(ExamAppModels::Student* student)
	{
		this->student = student;
	}

	void StudentController::logInAsStudent() const
	{
		// Variable declaration and initialization
		bool isExit = false;

		// Menu loop
		do
		{
			// Display menu items and get user menu selection
			switch (ExamAppViews::StudentView::displayMenu(student->getFullName()))
			{
			case ExamAppModels::StudentMenuItems::Unkown: break;
			case ExamAppModels::StudentMenuItems::TakeExam:
				selectExam();
				break;
			case ExamAppModels::StudentMenuItems::ViewExam:
				selectGradedExam();
				break;
			case ExamAppModels::StudentMenuItems::Logout:
				isExit = true;
				break;
			default: break;
			};
		} while (!isExit);
	}

	/*+===================================================================
	Private Members
	===================================================================+*/

	void StudentController::selectExam() const
	{
		// Variable declaration and initialization
		vector<ExamAppModels::IndexItem*> *items = repository->getExamTemplateIndex();

		// If index file is empty
		if (items->empty())
		{
			ExamAppViews::StudentView::displayNoExamsAvailableMessage();
			return;
		}

		// Get Index item based on user selection from user input
		ExamAppModels::IndexItem* item = (*items)[ExamAppViews::StudentView::displayExamItemsToSelect(items, "Which exam do you want to take?")];

		// Loead exam from selected template
		ExamAppModels::Exam* exam = repository->getNewExam(item);

		// Null check for exam
		if (exam != nullptr)
		{
			startExam(exam);
		}
		else
		{
			ExamAppViews::StudentView::displayErrorOpeningExamMessage();
		}

		// Clean-up
		clearIndexItems(items);
		delete items;
		delete exam;
	}

	void StudentController::startExam(ExamAppModels::Exam *exam) const
	{
		// Variable declaration and initialization
		bool isExit = false;

		// Display exam start on UI
		ExamAppViews::StudentView::displayExamStart(exam);

		// Get first question for exam
		ExamAppModels::Question *currentQuestion = exam->getCurrentQuesiton();

		// Question display and answer input loop
		do {

			//TODO: Add question navigation input checks to perform differnt actions

			// Get valid answer for question
			exam->setAnswerValueCurrentQuestion(ExamAppViews::StudentView::displayExamQuestion(currentQuestion));

			// Move to next question in exam
			currentQuestion = exam->nextQuestion();

			// Check if end of exam reached
			if (currentQuestion == nullptr)
				isExit = true;

		} while (!isExit);

		// Save exam to answer sheet and notify student on UI
		endExam(exam);
	}

	void StudentController::endExam(ExamAppModels::Exam *exam) const
	{
		// Save exam to answer sheet
		repository->savePendingExam(exam, student);
		// Display confirmation on UI
		ExamAppViews::StudentView::displayExamSavedMessage(exam->getName());
	}

	void StudentController::selectGradedExam() const
	{
		// Variable declaration and initialization
		vector<ExamAppModels::IndexItem*> *items = repository->getGradedExamIndex(student->getId());

		// If index file is empty
		if (items->empty())
		{
			ExamAppViews::StudentView::displayNoExamsAvailableMessage();
			return;
		}

		// Get Index item based on user selection from user input
		ExamAppModels::IndexItem* item = (*items)[ExamAppViews::StudentView::displayExamItemsToSelect(items, "Which graded exam do you want to view?")];

		// Loead exam from selected template
		ExamAppModels::GradedExam* gradedExam = repository->getGradedExam(item);

		// Null check for exam
		if (gradedExam != nullptr)
		{
			viewGradedExam(gradedExam);
		}
		else
		{
			ExamAppViews::StudentView::displayErrorOpeningExamMessage();
		}

		// Clean-up
		clearIndexItems(items);
		delete items;
		delete gradedExam;
	}

	void StudentController::viewGradedExam(ExamAppModels::GradedExam* gradedExam)
	{
		// Variable declaration and initialization
		bool isExit = false;

		do
		{
			// Display graded exam results
			ExamAppViews::StudentView::displayGradedExam(gradedExam);

			// Display menu items and get user menu selection
			switch (ExamAppViews::StudentView::displayGradedExamMenu())
			{
			case ExamAppModels::StudentGradedExamMenuItems::Unkown: break;
			case ExamAppModels::StudentGradedExamMenuItems::ViewQuestions:
				viewGradedExamQuestions(gradedExam);
				break;
			case ExamAppModels::StudentGradedExamMenuItems::GoBack:
				isExit = true;
				break;
			default: break;
			};
		} while (!isExit);		
	}

	void StudentController::viewGradedExamQuestions(ExamAppModels::GradedExam* gradedExam)
	{
		// Iterate over exam questions and display results for each question
		try
		{
			int questionCount = gradedExam->getQuestionCount();

			for(int i = 0; i < questionCount; ++i)
			{
				ExamAppViews::StudentView::displayGradedExamQuestion(gradedExam->goToQuestion(i), gradedExam->goToAnswerKey(i));
			}

			// Notify user that end of exam questions has been reached
			ExamAppViews::StudentView::displayEndofGradedQuestionsReached();

		}
		catch(...)
		{
			cout << endl << "Error: Reading graded exam data." << endl;
		}
	}

	void StudentController::clearIndexItems(std::vector<ExamAppModels::IndexItem*> *items)
	{
		// Loop through vector deallocating memory and removing item from vector
		while (!items->empty())
		{
			delete items->back();
			items->pop_back();
		}
	}
}
