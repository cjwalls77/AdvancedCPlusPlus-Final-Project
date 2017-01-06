/*+===================================================================
File:      Config.h

Summary:   Header file for LogOnController

Classes:   Config

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamGraderApp
{
	/*+===================================================================
	Class:    Config

	Summary:  Holds file path values,
			  the application needs to read/write to files.

	===================================================================+*/
	struct Config
	{
	public:
		/*+===================================================================
		Function: Config::getExamTemplatesIndexFilePath

		Summary:  Get file path for exam templates index.

		Args:     None

		Returns:  string
					File path for file.
		===================================================================+*/
		static std::string getExamTemplatesIndexFilePath();

		/*+===================================================================
		Function: Config::getExamTemplatesBasePath

		Summary:  Get base file path for exam templates.

		Args:     None

		Returns:  string
					File path for file.
		===================================================================+*/
		static std::string getExamTemplatesBasePath();

		/*+===================================================================
		Function: Config::getPendingExamsIndexFilePath

		Summary:  Get file path for pending exams index.

		Args:     None

		Returns:  string
					File path for file.
		===================================================================+*/
		static std::string getPendingExamsIndexFilePath();

		/*+===================================================================
		Function: Config::getPendingExamsBasePath

		Summary:  Get base file path for pending exams path.

		Args:     None

		Returns:  string
					File path for file.
		===================================================================+*/
		static std::string getPendingExamsBasePath();

		/*+===================================================================
		Function: Config::getExamRubricsIndexFilePath

		Summary:  Get file path for exam rubrics index.

		Args:     None

		Returns:  string
					File path for file.
		===================================================================+*/
		static std::string getExamRubricsIndexFilePath();

		/*+===================================================================
		Function: Config::getExamRubricsIndexFilePath

		Summary:  Get base file path for exam rubrics.

		Args:     None

		Returns:  string
		File path for file.
		===================================================================+*/
		static std::string getExamRubricsBasePath();

		/*+===================================================================
		Function: Config::getGradedExamsIndexFilePath

		Summary:  Get file path for graded exam index.

		Args:     None

		Returns:  string
					File path for file.
		===================================================================+*/
		static std::string getGradedExamsIndexFilePath();

		/*+===================================================================
		Function: Config::getGradedExamBasePath

		Summary:  Get base file path for graded exams.

		Args:     None

		Returns:  string
					File path for file.
		===================================================================+*/
		static std::string getGradedExamBasePath();
	};
}
