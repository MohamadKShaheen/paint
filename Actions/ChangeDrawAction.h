#pragma once
#include "Action.h"

class ChangeDrawAction : public Action
{
private:
	color color;
public:
	ChangeDrawAction(ApplicationManager *pApp);

	//Get color from the user
	virtual void ReadActionParameters();

	//Change draw color
	virtual void Execute();

};