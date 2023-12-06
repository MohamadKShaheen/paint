
#ifndef PLAYTYPEANDCOLORACTION_H
#define PLAYTYPEANDCOLORACTION_H
#include "..\Figures\CFigure.h"
#include "..\Actions\Action.h"

class playTypeAndColorAction : public Action
{
	ActionType ActType;
	int right;
	int wrong;
public:
	playTypeAndColorAction(ApplicationManager* pApp);
	~playTypeAndColorAction();

	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif
