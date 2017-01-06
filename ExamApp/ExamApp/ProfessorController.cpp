/*+===================================================================
File:      ProfessorController.cpp

Summary:   Source file for ProfessorController

Classes:   ProfessorController

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "ProfessorController.h"
#include "ProfessorView.h"
#include "Exam.h"
#include "TFQuestion.h"
#include "MCQuestion.h"

using namespace std;

namespace ExamAppControllers
{
	/*+===================================================================
	Public Members
	===================================================================+*/
	ProfessorController::ProfessorController(ExamAppModels::Repository* repository)
	{
		this->repository = repository;
	}

	ProfessorController::~ProfessorController()
	{
		// No managed items to clean-up
	}

	void ProfessorController::logInAsProfessor() const
	{
		// Variable declaration and initialization
		bool isExit = false;

		// Menu loop
		do
		{
			// Display menu and get user menu selection
			switch (ExamAppViews::ProfessorView::displayMenu())
			{
			case ExamAppModels::ProfessorMenuItems::Unkown: break;
			case ExamAppModels::ProfessorMenuItems::CreateExam:
				createExam();
				break;
			case ExamAppModels::ProfessorMenuItems::Logout:
				isExit = true;
				break;
			default: break;
			};
		} while (!isExit);
	}

	/*+===================================================================
		Private Members
	===================================================================+*/

	void ProfessorController::createExam() const
	{
		// Variable declaration and initialization
		ExamAppModels::Exam *examTemplate = new ExamAppModels::Exam();

		try
		{
			// Set exam name
			examTemplate->setName(ExamAppViews::ProfessorView::displayExamNameInput());

			// Add questions to exam
			int questionCount = ExamAppViews::ProfessorView::displayQuestionCountInput();

			int questionId = 1;
			for(int i = 0; i < questionCount; ++i, ++questionId)
			{
				// Display question number
				ExamAppViews::ProfessorView::displayQuestionNumber(questionId);

				// Select qustion type, ensures valid type
				ExamAppModels::QuestionTypes type = ExamAppViews::ProfessorView::displayQuestionTypeInput();

				// Add question to exam
				switch(type)
				{
				case ExamAppModels::QuestionTypes::TF:
					addTFQuestion(examTemplate, questionId);
					break;
				case ExamAppModels::QuestionTypes::MC:
					addMCQuestion(examTemplate, questionId);
					break;
				case ExamAppModels::QuestionTypes::Unknown:
					break;
				}
			}

			if (repository->saveExamTemplate(examTemplate))
				ExamAppViews::ProfessorView::displayExamTemplateCreatedConfirmation(examTemplate->getName());
			else
				cout << endl << "Error: Exam could not be created" << endl;
		}
		catch(...)
		{
			cout << endl << "Error: Exam could not be created." << endl;
		}

		// Clean-up
		delete examTemplate;
	}

	void ProfessorController::addTFQuestion(ExamAppModels::Exam* examTemplate, int id)
	{
		ExamAppModels::TFQuestion *tfQuestion = new ExamAppModels::TFQuestion();
		tfQuestion->setId(id);
		tfQuestion->setQuestionText(ExamAppViews::ProfessorView::displayQuestionTextInput());
		tfQuestion->setPointValue(ExamAppViews::ProfessorView::displayQuestionPointValueInput());
		tfQuestion->setAnswerValue(ExamAppViews::ProfessorView::displayAnswerKeyInput(tfQuestion));

		// Add question to exam template
		examTemplate->addQuestion(tfQuestion);
	}

	void ProfessorController::addMCQuestion(ExamAppModels::Exam* examTemplate, int id)
	{
		ExamAppModels::MCQuestion *mcQuestion = new ExamAppModels::MCQuestion();
		mcQuestion->setId(id);
		mcQuestion->setQuestionText(ExamAppViews::ProfessorView::displayQuestionTextInput());
		mcQuestion->setPointValue(ExamAppViews::ProfessorView::displayQuestionPointValueInput());

		// Add MC options
		int optionCount = ExamAppViews::ProfessorView::displayMCOptionsCountInput();

		int optionId = 1;
		for(int i = 0; i < optionCount; ++i, ++optionId)
		{
			ExamAppModels::MCOption *option = new ExamAppModels::MCOption();
			option->setId(optionId);
			option->setText(ExamAppViews::ProfessorView::displayMCOptionTextInput(optionId));
			mcQuestion->addOption(option);
		}

		mcQuestion->setAnswerValue(ExamAppViews::ProfessorView::displayAnswerKeyInput(mcQuestion));

		// Add question to exam template
		examTemplate->addQuestion(mcQuestion);
	}
}
