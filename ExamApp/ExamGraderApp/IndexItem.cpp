/*+===================================================================
File:      IndexItem.cpp

Summary:   Source file for IndexItem

Classes:   IndexItem

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "IndexItem.h"

using namespace std;

namespace ExamGraderAppModels
{
	/*+===================================================================
	Public Members
	===================================================================+*/

	IndexItem::IndexItem()
	{
		id = 0;
		studentId = 0;
		examId = 0;
		indexItemName = "";
		fileName = "";
	}

	IndexItem::~IndexItem()
	{
	}

	int IndexItem::getId() const
	{
		return id;
	}

	void IndexItem::setId(int id)
	{
		this->id = id;
	}

	int IndexItem::getStudentId() const
	{
		return studentId;
	}

	void IndexItem::setStudentId(int id)
	{
		this->studentId = id;
	}

	int IndexItem::getExamId() const
	{
		return examId;
	}

	void IndexItem::setExamId(int id)
	{
		this->examId = id;
	}

	string IndexItem::getIndexItemName() const
	{
		return indexItemName;
	}

	void IndexItem::setIndexItemName(std::string name)
	{
		this->indexItemName = name;
	}

	string IndexItem::getFileName() const
	{
		return fileName;
	}

	void IndexItem::setFileName(std::string name)
	{
		this->fileName = name;
	}

	/*+===================================================================
	Private Members
	===================================================================+*/
}
