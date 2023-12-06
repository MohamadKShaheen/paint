#include "ToFrontAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ToFrontAction::ToFrontAction(ApplicationManager * pApp) : Action(pApp)
{}

void ToFrontAction::ReadActionParameters()
{
}

//Execute the action
void ToFrontAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	vector<CFigure*> selected = pManager->GetSelectedFig();
	int size = selected.size();
	if (size == 0) {
		pOut->PrintMessage("You have to select at least one figure");
		return;
	}
	int diff = pManager->getLastID() - selected[0]->getID() + 1;
	if (diff == 1) {
		pOut->PrintMessage("Already in front!");
		return;
	}
	for (int i = 0; i < size; i++) {
		selected[i]->shiftID(diff);
	}
	CFigure::SetFigID(selected[size - 1]->getID());
	pManager->sortFigList();
	pOut->PrintMessage("Done!");
}
