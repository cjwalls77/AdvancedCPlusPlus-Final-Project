/*+===================================================================
File:      IndexItem.h

Summary:   Header file for IndexItem

Classes:   IndexItem

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once

namespace ExamAppModels
{
	/*+===================================================================
	Class:    IndexItem

	Summary:  Data Model for an index item.

	===================================================================+*/
	class IndexItem
	{
	public:
		/*+===================================================================
			Constructor
		===================================================================+*/
		IndexItem();

		/*+===================================================================
			Destructor
		===================================================================+*/
		~IndexItem();

		/*+===================================================================
			Getters / Setters
		===================================================================+*/
		int getId() const;
		void setId(int id);
		int getStudentId() const;
		void setStudentId(int id);
		int getExamId() const;
		void setExamId(int id);
		std::string getIndexItemName() const;
		void setIndexItemName(std::string name);
		std::string getFileName() const;
		void setFileName(std::string name);

	private:
		/*+===================================================================
			Private Member Variables
		===================================================================+*/
		int id;
		int studentId;
		int examId;
		std::string indexItemName;
		std::string fileName;

	};
}
