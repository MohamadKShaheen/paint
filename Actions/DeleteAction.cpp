#include "DeleteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"



DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{}

void DeleteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
}

void DeleteAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	vector <CFigure*> &FigDelete = pManager->GetSelectedFig();

	if (!FigDelete.size())
		return;
	int i = FigDelete.size() - 1;
	do {
		pManager->DeleteFig(FigDelete[i]);
		FigDelete.erase(FigDelete.begin() + i);
		i--;
	} while (FigDelete.size());

	pManager->UpdateInterface();
}