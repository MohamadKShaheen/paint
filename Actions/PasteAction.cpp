#include "PasteAction.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include <vector>
#include <Algorithm>
#include "..\Figures\CFigure.h"

PasteAction::PasteAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	if (pManager->GetClipboard().size() == 0)
		return;
	Output *pOut = pManager->GetOutput();  // pointer pOut to Print Message 
	Input *pIn = pManager->GetInput();  // pointer pIn to Get User Action (Moving Center)

	pOut->PrintMessage("Click At Center To Paste");  //Printing The Message

	pIn->GetPointClicked(MovingCenter.x, MovingCenter.y);  //Get The User Action (Moving Center) 

	pOut->ClearStatusBar();

}

void PasteAction::Execute()
{

	ReadActionParameters();  //Get The Moving Center From The User  
	vector <CFigure*> &clipboard = pManager->GetClipboard();
	int size = clipboard.size();
	if (size == 0)
		return;
	Point SumPoints; //To Get The Center of All Pasted Figures ToGether 
	SumPoints.x = 0;
	SumPoints.y = 0;
	for (int i = 0; i < size; i++)
		SumPoints += clipboard[i]->GetCenter();  //Get The Sum of All Figures Center

	SumPoints /= size;  // To Get The Center of The Figures We Divide into The Number of Figures

	MovingCenter -= SumPoints;  //Subtract The Center of The Figures From The Clicked Point
	for (int i = 0; i < size; i++)
	{
		clipboard[i]->Move(MovingCenter);  //Moving The Figure To The Exact Place
		pManager->AddFigure(clipboard[i]->CopyFigure());  //Add The Figure To The Figure List
	} 
}
