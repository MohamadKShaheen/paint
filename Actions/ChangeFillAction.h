#pragma once
#include "Action.h"

class ChangeFillAction : public Action
{
private:
	color color;
public:
	ChangeFillAction(ApplicationManager *pApp);

	//Get color from the user
	virtual void ReadActionParameters();

	//Change draw color
	virtual void Execute();

};