#pragma once
#include "Action.h"

class ModeAction : public Action
{
public:
	ModeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};