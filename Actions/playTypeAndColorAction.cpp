#include "playTypeAndColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "string"


playTypeAndColorAction::playTypeAndColorAction(ApplicationManager* pApp) :Action(pApp)
{
	right = 0;
	wrong = 0;
}


playTypeAndColorAction::~playTypeAndColorAction()
{
}

void playTypeAndColorAction::ReadActionParameters()
{
}

void playTypeAndColorAction::Execute()
{
	pManager->makeVisible();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* RandomFig = pManager->getRandomFig(true);
	if (!RandomFig)
	{
		pOut->PrintMessage("Please draw some filled figures to play this game");
		return;
	}
	color Clr = RandomFig->getFigColor();
	int rightChoices = pManager->count(RandomFig, &Clr);
	Point p;
	CFigure* figchoose = NULL;
	pOut->PrintMessage("Choose all " + Clr.getName() + " " + RandomFig->getName() + "S");
	do {
		pIn->GetPointClicked(p.x, p.y, false);
		if (p.y < UI.ToolBarHeight && p.x < UI.MenuItemWidth * 5) {
			pIn->setQueuePoint(p.x, p.y);
			return;
		}
		figchoose = pManager->GetFigure(p);
		if (figchoose != NULL)
		{
			if (RandomFig->isSame(figchoose) && (figchoose->getIsFilled()) && (figchoose->getFigColor() == Clr))	//make sure that the choosen figure is the required figure
			{
				right++;	//counter for winnig times
				figchoose->SetVisible(false);		//delete the clicked figure
				pManager->UpdateInterface();
				pOut->PrintMessage(("Your choice is correct || right clicks:  ") + (to_string(right)) + (" || wrong clicks:  ") + (to_string(wrong)));
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
