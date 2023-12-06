#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class SelectAction : public Action
{
private:
	Point P;
public:
	SelectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};