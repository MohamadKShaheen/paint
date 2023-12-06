#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	string status;
	window* pWind;	//Pointer to the Graphics Window
	void drawToolBar(string dir, int i = 0) const;
	void clearToolBar() const;
	void read_directory(string, vector<string> &) const;
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void drawCurrentToolBar() const;
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawLine(Point p1, Point p2, GfxInfo linegfxinfo, bool selsected = false) const;
	void DrawTriangle(Point p1, Point p2, Point p3, GfxInfo trianglegfxinfo, bool selected = false) const;
	void DrawCircle(Point P1, int R, GfxInfo circleGfxInfo, bool selected = false) const;
	///Make similar functions for drawing all other figures.

	void PrintMessage(string msg);	//Print a message on Status bar
	void refreshStatus();

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void drawColorPalette();

	~Output();
};

#endif