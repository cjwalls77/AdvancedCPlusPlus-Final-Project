/*+===================================================================
File:      MCOption.h

Summary:   Header file for MCOption

Classes:   MCOption

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamAppModels
{
	/*+===================================================================
	Class:    MCOption

	Summary:  Data Model for an MC question option.

	===================================================================+*/
	class MCOption
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		MCOption();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~MCOption();

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		int getId() const;
		void setId(int id);
		std::string getText() const;
		void setText(std::string text);

	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int id;
		std::string text;

	};
}
