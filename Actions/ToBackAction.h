#pragma once
#include "Action.h"

class ToBackAction : public Action
{
private:
	string fileName;
public:
	ToBackAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};