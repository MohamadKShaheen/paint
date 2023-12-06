#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include <vector>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	//int FigCount;		//Actual number of figures
	//CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	vector <CFigure*> FigList;
	//CFigure* SelectedFig; //Pointer to the selected figure
	vector <CFigure*> SelectedFig;
	//CFigure* Clipboard;   //Pointer to the copied/cut figure
	vector <CFigure*> Clipboard;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void SetClipboard(CFigure*); // Add The Cut/copy Figure To The Clipboard
	vector <CFigure*>& GetClipboard();  //Get The Figures From The Clipboard To Paste them
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(Point P) const;	//Search for a figure given a point inside the figure
	void SelectFig(CFigure* pFig);	//Adds a figure to the list of selected figures
	void UnSelectFig(CFigure* pFig);	//Removes a figure from the list of selected figures
	vector <CFigure*>& GetSelectedFig();	//returns a vector of all selected figures
	void DeleteFig(CFigure* pFig, bool unSelect = false);	//Removes a figures
	int count(const CFigure* fig, const color* color); // returns number of the passed figure or color
	CFigure* getRandomFig(bool filled = false);	//get random figure for play mode
	void makeVisible();		//make all the figure visible

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	//save figure list into a file
	void saveAll(ofstream &OutFile) const;
	int getFigListSize() const;
	void clean();
	void clearClipboard();
	void sortFigList();
	int getFirstID();
	int getLastID();
};

#endif