#include "playTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include <string>

playTypeAction::playTypeAction(ApplicationManager* pApp) : Action(pApp)
{
	wrong = 0;
	right = 0;
}


playTypeAction::~playTypeAction()
{
}

void playTypeAction::ReadActionParameters()
{
}

void playTypeAction::Execute()
{
	pManager->makeVisible();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Random = pManager->getRandomFig();
	if (!Random) {
		pOut->PrintMessage("Please draw some figure to play this game");
		return;
	}
	int rightChoices = pManager->count(Random, NULL);
	Point p;
	CFigure* figchoose;
	pOut->PrintMessage("Choose all " + Random->getName() + "S");
	do {
		pIn->GetPointClicked(p.x, p.y, false);
		if (p.y < UI.ToolBarHeight && p.x < UI.MenuItemWidth * 5)
		{
			pIn->setQueuePoint(p.x, p.y);
			return;
		}
		figchoose = pManager->GetFigure(p);
		if (figchoose != NULL)
		{
			if (Random->isSame(figchoose))	//make sure that the choosen figure is the required figure
			{
				right++;	//counter for winnig times
				figchoose->SetVisible(false);		//delete the clicked figure
				pManager->UpdateInterface();
				pOut->PrintMessage(("Your chioce is correct || right clicks:  ") + (to_string(right)) + (" || wrong clicks:  ") + (to_string(wrong)));
			}
			else
			{
				wrong++;	//counter for wrong choise times
				pOut->PrintMessage(("Your choice is incorrect || right clicks:  ") + (to_string(right)) + (" || wrong clicks:  ") + (to_string(wrong)));
				figchoose->SetVisible(false);		//delete the clicked figure
				pManager->UpdateInterface();
			}
		}
	} while (right < rightChoices);
	pOut->PrintMessage("The game is over || right clicks:  " + (to_string(right)) + (" ||  wrong clicks:  ") + (to_string(wrong)));
}