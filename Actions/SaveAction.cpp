#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SaveAction::SaveAction(ApplicationManager * pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter File Name: ");
	fileName = pIn->GetSrting(pOut);
}

void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream OutFile(fileName);
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (OutFile.is_open()) {
		OutFile << getColorNumber(UI.DrawColor) << "\t" << getColorNumber(UI.FillColor) << endl
			<< pManager->getFigListSize() << endl;
		pManager->saveAll(OutFile);
		OutFile.close();
		pOut->PrintMessage("Saved successfully!");
	}
	else {
		pOut->PrintMessage("Unable to save "+ fileName);
	}
}
