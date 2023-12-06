#include "ModeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ModeAction::ModeAction(ApplicationManager * pApp) : Action(pApp)
{}

void ModeAction::ReadActionParameters()
{
}

//Execute the action
void ModeAction::Execute()
{
	UI.filled = !UI.filled;
}
