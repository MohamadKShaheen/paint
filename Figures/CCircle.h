#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	int Radius;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	virtual void Save(ofstream &OutFile) const;
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure*CopyFigure();
	virtual Point GetCenter();
	virtual void Move(Point);
	virtual string getName() const;
	virtual bool isSame(CFigure* figChoose) const;
};

