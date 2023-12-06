#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class PasteAction:public Action
{
private:
	Point MovingCenter;

public:
	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};