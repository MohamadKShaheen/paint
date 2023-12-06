#pragma once
#include "Action.h"

class AddTriangleAction :
	public Action
{
private:
	Point P1, P2, P3; //Triangle Vertices
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);
	
	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();
};

