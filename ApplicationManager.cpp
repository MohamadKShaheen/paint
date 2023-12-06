#include "ApplicationManager.h"
#include "Actions\ModeAction.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\ChangeDrawAction.h"
#include "Actions\ChangeFillAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\PlayModeAction.h"
#include "Figures\CCircle.h"
#include "Actions\DeleteAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\CopyAction.h"
#include "Actions\CutAction.h"
#include "Actions\PasteAction.h"
#include "Actions\RotateAction.h"
#include "Actions\ToBackAction.h"
#include "Actions\ToFrontAction.h"
#include "Figures\CFigure.h"
#include "Figures\CCircle.h"
#include "Figures\CLine.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"
#include "Actions\playTypeAction.h"
#include "Actions\playColorAction.h"
#include "Actions\playTypeAndColorAction.h"
#include "Actions\DrawModeAction.h"
#include <Algorithm>
#include <stdlib.h>
#include <time.h>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	if (UI.InterfaceMode == MODE_DRAW)
	{
		switch (ActType)
		{
		case MODE:
			pAct = new ModeAction(this);
			break;
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawAction(this);
			break;
		case CHNG_FILL_CLR:
			pAct = new ChangeFillAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case ROTATE:
			pAct = new RotateAction(this);
			break;
		case TO_BACK:
			pAct = new ToBackAction(this);
			break;
		case TO_FRONT:
			pAct = new ToFrontAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case TO_PLAY:
			pAct = new PlayModeAction(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case COPY:
			pAct = new CopyAction(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case EXIT:
			/// Nothing to do
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;

		}
	}
	else {
		switch (ActType)
		{

		case STATUS:
			return;

		case EMPTY:
			return;

		case PICK_TYPE:
			pAct = new playTypeAction(this);
			break;

		case PICK_FILL:
			pAct = new playColorAction(this);
			break;

		case PICK_TYPE_AND_FILL:
			pAct = new playTypeAndColorAction(this);
			break;

		case TO_DRAW:
			pAct = new DrawModeAction(this);
			break;

		default:
			break;
		}
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//


//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigList.size() < MaxFigCount) {
		//FigList[FigCount++] = pFig;	
		FigList.push_back(pFig);
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigList.size() - 1; i >= 0; i--) {
		if (FigList[i]->IsInside(P)) {
			return FigList[i];
		}
	}

	return NULL;
}

void ApplicationManager::SelectFig(CFigure* pFig)
{
	SelectedFig.push_back(pFig);
	sort(SelectedFig.begin(), SelectedFig.end(), CFigure::compareID); // Sorting selected figures in order to copy/cut/paste correctly
	pFig->PrintInfo(pOut);
}

vector <CFigure*>& ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}

void ApplicationManager::SetClipboard(CFigure* CopyFigure)
{
	Clipboard.push_back(CopyFigure);
}

vector <CFigure*>& ApplicationManager::GetClipboard()
{
	return Clipboard;
}

void ApplicationManager::UnSelectFig(CFigure* pFig)
{
	vector<CFigure*>::iterator UnSelect = find(SelectedFig.begin(), SelectedFig.end(), pFig);
	SelectedFig.erase(UnSelect);
}

void ApplicationManager::DeleteFig(CFigure* pFig, bool unSelect)
{
	delete pFig;
	vector<CFigure*>::iterator Delete = find(FigList.begin(), FigList.end(), pFig);
	if (unSelect)
		UnSelectFig(pFig);
	FigList.erase(Delete);
}

int ApplicationManager::count(const CFigure* fig, const color* color) {
	int size = FigList.size();
	int count = 0;
	if (!fig && !color)
		return count;
	for (int i = 0; i < size; i++) {
		if (fig && color)
			count += FigList[i]->getIsFilled() && fig->isSame(FigList[i]) && FigList[i]->getFigColor() == *color;
		else if (fig)
			count += fig->isSame(FigList[i]);
		else
			count += FigList[i]->getIsFilled() && FigList[i]->getFigColor() == *color;
	}
	return count;
}

CFigure * ApplicationManager::getRandomFig(bool filled)
{
	int size = FigList.size();
	if (size == 0)
		return NULL;
	srand(time(NULL));
	vector<int> filledInd;
	int x;
	if (filled) {
		for (int i = 0; i < size; i++)
			if (FigList[i]->getIsFilled())
				filledInd.push_back(i);
		if (filledInd.size() == 0)
			return NULL;
		x = filledInd[rand() % filledInd.size()];
	}
	else {
		x = rand() % size;
	}
	return FigList[x];
}

void ApplicationManager::makeVisible()
{
	int n = FigList.size();
	for (int i = 0; i < n; i++)
		FigList[i]->SetVisible(true);
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	int size = FigList.size();
	pOut->ClearDrawArea();
	for (int i = 0; i < size; i++) {
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
	// Draw a toolbar again if FigList contains a circle
	pOut->drawCurrentToolBar();
	pOut->refreshStatus();
}
void ApplicationManager::saveAll(ofstream &OutFile) const
{
	int size = FigList.size();
	for (int i = 0; i < size; i++) {
		FigList[i]->Save(OutFile);
	}
}
int ApplicationManager::getFigListSize() const
{
	return FigList.size();
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::clean() {
	int size = FigList.size();
	SelectedFig.clear();
	for (int i = 0; i < size; i++) {
		delete FigList[i];
	}
	FigList.clear();
}

void ApplicationManager::clearClipboard()
{
	int size = Clipboard.size();
	for (int i = 0; i < size; i++) {
		delete Clipboard[i];
	}
	Clipboard.clear();
}
void ApplicationManager::sortFigList()
{
	sort(FigList.begin(), FigList.end(), CFigure::compareID);
}
int ApplicationManager::getFirstID()
{
	if (FigList.size() == 0)
		return -1;
	return FigList[0]->getID();
}
int ApplicationManager::getLastID()
{
	if (FigList.size() == 0)
		return -1;
	return FigList[FigList.size() - 1]->getID();
}
//Destructor
ApplicationManager::~ApplicationManager()
{
	clearClipboard();
	clean();
	delete pIn;
	delete pOut;

}