/*+===================================================================
File:      Config.cpp

Summary:   Source file for Config

Classes:   Config

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include  "stdafx.h"
#include "Config.h"

using namespace std;

//TODO: Consider refactoring to parse this from a config file

namespace ExamApp
{
	/*+===================================================================
	Public Members
	===================================================================+*/
	string Config::getStudentRosterFilePath()
	{
		return "C:\\ExamAppFiles\\student_roster\\main_roster.txt";
	}

	string Config::getExamTemplatesIndexFilePath()
	{
		return "C:\\ExamAppFiles\\exam_templates\\exam_templates_index.txt";
	}

	string Config::getExamTemplatesBasePath()
	{
		return "C:\\ExamAppFiles\\exam_templates\\";
	}

	string Config::getPendingExamsIndexFilePath()
	{
		return "C:\\ExamAppFiles\\pending_exams\\pending_exams_index.txt";
	}

	string Config::getPendingExamsBasePath()
	{
		return "C:\\ExamAppFiles\\pending_exams\\";
	}

	string Config::getExamRubricsIndexFilePath()
	{
		return "C:\\ExamAppFiles\\exam_rubrics\\exam_rubrics_index.txt";
	}

	std::string Config::getExamRubricsBasePath()
	{
		return "C:\\ExamAppFiles\\exam_rubrics\\";
	}

	string Config::getGradedExamsIndexFilePath()
	{
		return "C:\\ExamAppFiles\\graded_exams\\graded_exams_index.txt";
	}

	string Config::getGradedExamBasePath()
	{
		return "C:\\ExamAppFiles\\graded_exams\\";
	}
}
