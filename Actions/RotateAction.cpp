#include "RotateAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RotateAction::RotateAction(ApplicationManager * pApp) :Action(pApp)
{}

void RotateAction::ReadActionParameters()
{
}

//Execute the action
void RotateAction::Execute()
{
	vector<CFigure*> selectedFigs = pManager->GetSelectedFig();
	int size = selectedFigs.size();
	if (size == 0) {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("You have to select at least one figure first");
	}
	for (int i = 0; i < size; i++) {
		selectedFigs[i]->rotate();
	}
}
