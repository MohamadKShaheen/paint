#pragma once
#include "Action.h"

//Add Rectangle Action class
class SaveAction : public Action
{
private:
	string fileName;
public:
	SaveAction(ApplicationManager *pApp);

	//Reads save action parameters (filename)
	virtual void ReadActionParameters();

	//Execute save action
	virtual void Execute();

};