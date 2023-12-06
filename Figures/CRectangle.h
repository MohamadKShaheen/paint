#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P);
	virtual void Save(ofstream &OutFile) const;
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure*CopyFigure();
	virtual Point GetCenter();
	virtual void Move(Point);
	virtual string getName() const;
	virtual void rotate();
	virtual bool isSame(CFigure* figChoose) const;
};

#endif