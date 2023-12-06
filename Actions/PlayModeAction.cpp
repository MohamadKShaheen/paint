#include "PlayModeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PlayModeAction::PlayModeAction(ApplicationManager * pApp) : Action(pApp)
{}

void PlayModeAction::ReadActionParameters()
{
}

//Execute the action
void PlayModeAction::Execute()
{
	pManager->GetOutput()->PrintMessage("you are in PLAY MODE");
	pManager->GetOutput()->CreatePlayToolBar();
}