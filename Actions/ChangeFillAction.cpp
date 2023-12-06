#include "ChangeFillAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>

ChangeFillAction::ChangeFillAction(ApplicationManager * pApp) :Action(pApp)
{}

void ChangeFillAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->drawColorPalette();
	pOut->PrintMessage("Choose a color");
	int x, y, colorOrder;
	do {
		pIn->GetPointClickedOnToolBar(x, y);
		colorOrder = x / UI.colorSide;
	} while (colorOrder > UI.numberOfColors - 1);
	pOut->drawCurrentToolBar();
	color = UI.colors[colorOrder];
	pOut->PrintMessage("Fill color is now " + color.getName());

}

//Execute the action
void ChangeFillAction::Execute()
{
	ReadActionParameters();
	vector<CFigure*> selectedFigs = pManager->GetSelectedFig();
	int size = selectedFigs.size();
	for (int i = 0; i < size; i++) {
		selectedFigs[i]->ChngFillClr(color);
	}
	if (size == 0)
		UI.FillColor = color;
}
