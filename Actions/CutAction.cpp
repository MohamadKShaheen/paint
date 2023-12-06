#include "CutAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include <vector>

CutAction::CutAction(ApplicationManager *pApp) :Action(pApp)
{

}

void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{
	vector <CFigure*> &SelectedFigs = pManager->GetSelectedFig();
	int size = SelectedFigs.size();
	if (!size)
		return;
	// Clear The Clipboard Before Cutting (objects and clipboard pointers)
	pManager->clearClipboard();
	for (int i = 0; i < size; i++)
	{
		pManager->SetClipboard(SelectedFigs[0]->CopyFigure());  //Send The New Figure to The Clipboard
		pManager->DeleteFig(SelectedFigs[0]);
		SelectedFigs.erase(SelectedFigs.begin());
	}
}