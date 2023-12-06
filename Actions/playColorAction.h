#ifndef PLAYCOLORACTION_H
#define PLAYCOLORACTION_H
#include "..\Figures\CFigure.h"
#include "..\Actions\Action.h"

class playColorAction: public Action
{
	ActionType ActType;
	int right;
	int wrong;
public:
	playColorAction(ApplicationManager* pApp);
	~playColorAction();

	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif

