#include "playColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include <string>


playColorAction::playColorAction(ApplicationManager * pApp) :Action(pApp)
{
	right = 0;
	wrong = 0;
}

playColorAction::~playColorAction()
{
}

void playColorAction::ReadActionParameters()
{
}

void playColorAction::Execute()
{
	pManager->makeVisible();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Random = pManager->getRandomFig(true);
	if (!Random) {
		pOut->PrintMessage("Please draw some filled figures to play this game");
		return;
	}
	color Clr = Random->getFigColor();
	int rightChoices = pManager->count(NULL, &Clr);
	Point p;
	CFigure* figchoose = NULL;
	pOut->PrintMessage("Choose all " + Clr.getName() + " figures");
	do {
		pIn->GetPointClicked(p.x, p.y, false);
		if (p.y < UI.ToolBarHeight && p.x < UI.MenuItemWidth * 5) {
			pIn->setQueuePoint(p.x, p.y);
			return;
		}
		figchoose = pManager->GetFigure(p);
		if (figchoose != NULL)
		{
			if (figchoose->getIsFilled() && figchoose->getFigColor() == Clr)
			{
				right++;	//counter for winnig times
				figchoose->SetVisible(false);		//hide the clicked figure
				pManager->UpdateInterface();
				pOut->PrintMessage("Your choice is correct || right clicks:  " + to_string(right) + " || wrong clicks:  " + to_string(wrong));
			}
			else
			{
				wrong++;	//counter for wrong choice times
				pOut->PrintMessage("Your choice is incorrect || right clicks:  " + to_string(right) + " || wrong clicks:  " + to_string(wrong));
				figchoose->SetVisible(false);		//delete the clicked figure
				pManager->UpdateInterface();
			}
		}
	} while (right < rightChoices);
	pOut->PrintMessage("The game is over || right clicks:  " + to_string(right) + " ||  wrong clicks:  " + to_string(wrong));
}

