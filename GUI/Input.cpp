#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
	queuePoint.x = -1;
	queuePoint.y = -1;
}

void Input::GetPointClicked(int &x, int &y, bool drawShape)
{
	do {
		if (queuePoint.x != -1) {
			x = queuePoint.x;
			y = queuePoint.y;
			queuePoint.x = -1;
			queuePoint.y = -1;
		}
		else {
			pWind->WaitMouseClick(x, y);	//Wait for mouse click
		}
	} while (drawShape &&  (y < UI.ToolBarHeight || y>(UI.height-UI.StatusBarHeight)));
}

void Input::GetPointClickedOnToolBar(int &x, int &y)
{
	do {
		GetPointClicked(x, y, false);	//Wait for mouse click
	} while (y > UI.ToolBarHeight);
}

void Input::setQueuePoint(int x, int y)
{
	queuePoint.x = x;
	queuePoint.y = y;
}

string Input::GetSrting(Output *pO) const
{
	pWind->FlushKeyQueue();
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27) {//ESCAPE key is pressed
			pWind->FlushMouseQueue();
			return "";	//returns nothing as user has cancelled label
		}
		if (Key == 13) {	//ENTER key is pressed
			pWind->FlushMouseQueue();
			return Label;
		}
		if (Key == 8) {	//BackSpace is pressed
			if (Label.size() >= 1)
				Label.resize(Label.size() - 1);
		}
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction()
{
	int x, y;
	//pWind->WaitMouseClick(x, y);
	GetPointClicked(x, y, false);
	//Get the coordinates of the user click
	//Check whick Menu item was clicked
	//==> This assumes that menu items are lined up horizontally <==
	int ClickedItemOrder = (x / UI.MenuItemWidth);
	//Divide x coord of the point clicked by the menu item width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			switch (ClickedItemOrder)
			{
			case ITM_MODE: return MODE;
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_LINE: return DRAW_LINE;
			case ITM_TRI: return DRAW_TRI;
			case ITM_CHNG_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_CHNG_FILL_CLR: return CHNG_FILL_CLR;
			case ITM_SELECT: return SELECT;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_ROTATE: return ROTATE;
			case ITM_TO_BACK: return TO_BACK;
			case ITM_TO_FRONT: return TO_FRONT;
			case ITM_DEL: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_TO_PLAY: return TO_PLAY;
			case ITM_EXIT_DRAW: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			switch (ClickedItemOrder)
			{
			case ITM_TYPE:return PICK_TYPE;										//~~~~~~~~~~~~~~~~~~~~~~~~~//
			case ITM_FILL:return PICK_FILL;
			case ITM_TYPE_AND_FILL:return PICK_TYPE_AND_FILL;
			case ITM_TO_DRAW:return TO_DRAW;
			case ITM_EXIT_PLAY:return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return TO_PLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
