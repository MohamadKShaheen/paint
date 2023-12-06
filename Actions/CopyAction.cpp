#include "CopyAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include <vector>

CopyAction::CopyAction(ApplicationManager *pApp):Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{

}

void CopyAction::Execute()
{
	vector <CFigure*> &SelectedFigs = pManager->GetSelectedFig();
	int size = SelectedFigs.size();
	if (!size)
		return;
	// Clear The Clipboard Before Copying (objects and clipboard pointers)
	pManager->clearClipboard();
	for(int i=0;i<size;i++)
	{
		pManager->SetClipboard(SelectedFigs[i]->CopyFigure()); //Send The New Figure to The Clipboard
	}

}