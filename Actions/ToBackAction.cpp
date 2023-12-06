#include "ToBackAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ToBackAction::ToBackAction(ApplicationManager * pApp) : Action(pApp)
{}

void ToBackAction::ReadActionParameters()
{
}

//Execute the action
void ToBackAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	vector<CFigure*> selected = pManager->GetSelectedFig();
	int size = selected.size();
	if (size == 0) {
		pOut->PrintMessage("You have to select at least one figure");
		return;
	}
	int diff = pManager->getFirstID() - selected[size - 1]->getID() - 1;
	if (diff == -1) {
		pOut->PrintMessage("Already in back!");
		return;
	}
	for (int i = 0; i < size; i++) {
		selected[i]->shiftID(diff);
	}
	pManager->sortFigList();
	pOut->PrintMessage("Done!");
}
