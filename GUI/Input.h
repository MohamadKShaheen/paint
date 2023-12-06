#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include <Windows.h>
#include <vector>
#include <string>

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
	Point queuePoint;
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y, bool drawShape = true);//Get coordinate where user clicks
	void GetPointClickedOnToolBar(int &x, int &y);//Get coordinate where user clicks on toolbar
	void setQueuePoint(int x, int y);
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user

	ActionType GetUserAction(); //Read the user click and map to an action

	~Input();
};

#endif