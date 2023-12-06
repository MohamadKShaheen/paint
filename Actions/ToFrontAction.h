#pragma once
#include "Action.h"

class ToFrontAction : public Action
{
private:
	string fileName;
public:
	ToFrontAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};