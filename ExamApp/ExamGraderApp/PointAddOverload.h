/*+===================================================================
File:      PointAddOverload.h

Summary:   Operator Overloads for exam answer sheet point score.

Classes:   None

Origin:    New file created for this assignment.

Author:    Charles "C.J." Walls
===================================================================+*/
#pragma once
#include "AnswerKey.h"

/*+===================================================================
	Operator Overloads
===================================================================+*/
int operator+ (int sum, ExamGraderAppModels::AnswerKey& answerKey);
