#ifndef PLAYTYPEACTION_H
#define PLAYTYPEACTION_H
#include "..\Figures\CFigure.h"
#include "Action.h"
#include <vector>

class playTypeAction :
	public Action
{
	ActionType ActType;
	int right, wrong;

public:
	playTypeAction(ApplicationManager* pApp);
	~playTypeAction();

	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif