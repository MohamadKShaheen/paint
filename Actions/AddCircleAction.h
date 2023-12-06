#pragma once
#include "Action.h"

class AddCircleAction : public Action
{
private:
	Point P1, P2; //Circlele center and a point on it
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager *pApp);

	//Reads Circlele parameters
	virtual void ReadActionParameters();

	//Add Circlele to the ApplicationManager
	virtual void Execute();
};

