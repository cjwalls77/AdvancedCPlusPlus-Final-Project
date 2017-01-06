/*+===================================================================
File:      PointAddOverload.cpp

Summary:   Source file for PointAddOverload

Classes:   PointAddOverload

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#include "stdafx.h"
#include "PointAddOverload.h"

/*+===================================================================
	Operator Overload
===================================================================+*/
int operator+(int sum, ExamGraderAppModels::AnswerKey& answerKey)
{
	return sum + answerKey.getPointValue();
}
