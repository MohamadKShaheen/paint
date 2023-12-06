#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class DeleteAction : public Action
{
public:
	//DeleteAction(ApplicationManager* pApp);
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};