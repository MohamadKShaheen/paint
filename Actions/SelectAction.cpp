#include "SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"



SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select: Click on a drawn figure to select/unselect it");

	//Read and store a point P
	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	CFigure* CrntFig = pManager->GetFigure(P);

	if (CrntFig) {
		if (!CrntFig->IsSelected()) {
			pManager->SelectFig(CrntFig);
			CrntFig->SetSelected(true);
		}
		else {
			pManager->UnSelectFig(CrntFig);
			CrntFig->SetSelected(false);
		}
	}
}