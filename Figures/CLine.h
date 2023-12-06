#pragma once
#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Start;
	Point End;
public:
	CLine();
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	virtual void Save(ofstream &OutFile) const;
	virtual void Load(ifstream &Infile);
	virtual void ChngFillClr(color Fclr);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* CopyFigure(); 
	virtual Point GetCenter();
	virtual void Move(Point);
	virtual color getFigColor() const;
	virtual string getName() const;
	virtual void rotate();
	virtual bool isSame(CFigure* figChoose) const;
};
