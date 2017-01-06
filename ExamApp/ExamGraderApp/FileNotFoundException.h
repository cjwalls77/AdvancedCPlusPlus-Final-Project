/*+===================================================================
File:      FileNotFoundException.h

Summary:   Header file for FileNotFoundException

Classes:   FileNotFoundException

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include <stdexcept>

namespace CustomExceptions
{
	/*+===================================================================
	Class:    FileNotFoundException

	Summary:  Exception thrown when file could not be loaded

	===================================================================+*/
	class FileNotFoundException : public std::runtime_error
	{
	public:
		/*+===================================================================
		Constructor
		===================================================================+*/
		explicit FileNotFoundException()
			: runtime_error("Error: File Not Found")
		{}
	};
}
