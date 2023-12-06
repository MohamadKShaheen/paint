#pragma once
#include "Action.h"

class DrawModeAction : public Action
{
public:
	DrawModeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
