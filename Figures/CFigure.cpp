#include "CFigure.h"


CFigure::CFigure()
{
	Selected = false;
	Visible = true;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Visible = true;
	ID = ++FigID;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected()
{	return Selected; }

int CFigure::getID()
{
	return ID;
}

void CFigure::SetVisible(bool v)
{
	Visible = v;
}

bool CFigure::getVisible()
{
	return Visible;
}

void CFigure::SetFigID(int newID)
{
	FigID = newID;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure::getFigColor() const
{
	return FigGfxInfo.FillClr;
}

bool CFigure::getIsFilled()
{
	return FigGfxInfo.isFilled;
}

void CFigure::rotate()
{
}

bool CFigure::operator<(CFigure & figure) const
{
	return ID < figure.ID;
}

bool CFigure::compareID(CFigure * f1, CFigure * f2)
{
	return *f1 < *f2;
}

void CFigure::shiftID(int n)
{
	ID += n;
}

int CFigure::FigID = 0;