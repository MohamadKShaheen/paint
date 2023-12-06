#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected
	bool Visible;	//checks whether the shape is visible for play mode
	GfxInfo FigGfxInfo;	//Figure graphis info

	static int FigID;

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected();	//check whether fig is selected
	void SetVisible(bool v);	//change visibility of figure
	bool getVisible();
	virtual string getName() const = 0;
	virtual bool isSame(CFigure* figChoose) const = 0;

	int getID();	//Returns the figure's ID
	static void SetFigID(int);	//Sets static data member FigID

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	virtual void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual color getFigColor() const;		//to get the filled color 
	bool getIsFilled();		//to know whether the figure is filled or not for play mode

	virtual bool IsInside(Point P) = 0;		//Checks whether a point is inside the figure
	virtual void rotate(); //rotate figures by 90 degrees
	virtual CFigure* CopyFigure() = 0;

	virtual Point GetCenter() = 0;

	virtual void Move(Point) = 0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) const = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	bool operator<(CFigure &figure) const;
	static bool compareID(CFigure * f1, CFigure * f2);
	void shiftID(int n); // Shifts Id by n
};

#endif