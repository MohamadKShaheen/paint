#pragma once
#include "Action.h"

class RotateAction : public Action
{
public:
	RotateAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	//Rotate selected figures
	virtual void Execute();

};