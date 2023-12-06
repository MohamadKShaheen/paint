#pragma once
#include "Action.h"

class PlayModeAction : public Action
{
public:
	PlayModeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};