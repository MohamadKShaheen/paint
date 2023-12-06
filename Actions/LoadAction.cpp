#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"
#include <iostream>

LoadAction::LoadAction(ApplicationManager * pApp) : Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter File Name: ");
	fileName = pIn->GetSrting(pOut);
}

//Execute the action
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (fileName == "") {
		pOut->PrintMessage("Quit loading operation");
		return;
	}
	ifstream Infile(fileName);
	if (Infile.is_open()) {
		pManager->clean();
		int tmp;
		Infile >> tmp;
		UI.DrawColor = getColorByNumber(tmp);
		Infile >> tmp;
		UI.FillColor = getColorByNumber(tmp);
		int size;
		Infile >> size;
		Infile.ignore();
		char type[10];
		for (int i = 0; i < size; i++) {
			CFigure* figure;
			Infile.getline(type, 10, '\t');
			if (strcmp(type, "LINE") == 0)
				figure = new CLine();
			else if (strcmp(type, "RECT") == 0)
				figure = new CRectangle();
			else if (strcmp(type, "TRIANG") == 0)
				figure = new CTriangle();
			else if (strcmp(type, "CIRCLE") == 0)
				figure = new CCircle();
			figure->Load(Infile);
			if (i == size - 1)
				CFigure::SetFigID(figure->getID());
			pManager->AddFigure(figure);
		}
		pOut->PrintMessage(fileName + " loaded successfully!");
	}
	else {
		pOut->PrintMessage("Error loading " + fileName);
	}
}
