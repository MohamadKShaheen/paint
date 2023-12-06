#include "DrawModeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawModeAction::DrawModeAction(ApplicationManager * pApp) : Action(pApp)
{
}

void DrawModeAction::ReadActionParameters()
{
}

void DrawModeAction::Execute()
{
	pManager->makeVisible();
	pManager->UpdateInterface();
	pManager->GetOutput()->PrintMessage("you are in DRAW MODE");
	pManager->GetOutput()->CreateDrawToolBar();
}
