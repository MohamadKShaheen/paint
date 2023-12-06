#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
int getColorNumber(color color);
color getColorByNumber(int n);
enum ActionType //The actions supported (you can add more if needed)
{
	MODE,
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	SELECT,
	COPY,
	CUT,
	PASTE,
	ROTATE,
	TO_BACK,
	TO_FRONT,
	DEL,			//Delete a figure(s)
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	PICK_TYPE,
	PICK_FILL,
	PICK_TYPE_AND_FILL,

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	int x, y;
	bool operator==(const Point& P)
	{
		return (x == P.x && y == P.y);
	}
	void operator+=(const Point& add)
	{
		x += add.x;
		y += add.y;
	}
	void operator-=(const Point& Sub)
	{
		x -= Sub.x;
		y -= Sub.y;
	}
	void operator=(const Point&P)
	{
		x = P.x;
		y = P.y;
	}
	Point operator+(const Point&P)
	{
		Point P1;
		P1.x = x + P.x;
		P1.y = y + P.y;
		return P1;
	}
	void operator/=(int Number)
	{
		x = rint((float) x / Number);
		y = rint((float)y / Number);
	}

	void rotate(const Point &around) //rotates the point by 90 degrees
	{
		*this -= around;
		int tmp = this->x;
		this->x = -this->y;
		this->y = tmp;
		*this += around;
	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif