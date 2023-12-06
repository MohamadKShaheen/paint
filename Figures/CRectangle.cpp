#include "CRectangle.h"
#include <string>

CRectangle::CRectangle()
{
}


CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	if (Visible)
		pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInside(Point P)
{
	if (!Visible)
		return false;
	int x1 = min(Corner1.x, Corner2.x);
	int x2 = max(Corner1.x, Corner2.x);
	int y1 = min(Corner1.y, Corner2.y);
	int y2 = max(Corner1.y, Corner2.y);

	if (P.x >= x1 && P.x <= x2 && P.y >= y1 && P.y <= y2) {
		return true;
	}
	return false;
}

void CRectangle::Save(ofstream & OutFile) const
{
	OutFile << "RECT\t" << ID << "\t"
		<< Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t"
		<< getColorNumber(FigGfxInfo.DrawClr) << "\t"
		<< (FigGfxInfo.isFilled ? getColorNumber(FigGfxInfo.FillClr) : -1) << endl;
}

void CRectangle::Load(ifstream & Infile)
{
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	int color;
	Infile >> color;
	FigGfxInfo.DrawClr = getColorByNumber(color);
	Infile >> color;
	if (color == -1) {
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByNumber(color);
	}
	Infile.ignore();
}

void CRectangle::PrintInfo(Output* pOut)
{
	string strID = to_string(ID);
	string strCorner1 = "(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
	string strCorner2 = "(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	string strCorner3 = "(" + to_string(Corner1.x) + "," + to_string(Corner2.y) + ")";
	string strCorner4 = "(" + to_string(Corner2.x) + "," + to_string(Corner1.y) + ")";
	string strLength = to_string(abs(Corner1.x - Corner2.x));
	string strWidth = to_string(abs(Corner1.y - Corner2.y));

	string FillColor = FigGfxInfo.isFilled ? FigGfxInfo.FillClr.getName() : "Not Filled";

	pOut->PrintMessage("Rectangle  |  ID : " + to_string(ID) + "  |  Corners : " + strCorner1 + ", " + strCorner3 + ", " + strCorner4+ ", " + strCorner2
		+ "  |  Dimensions : " + strLength + " × " + strWidth + "  |  Draw Color : " + FigGfxInfo.DrawClr.getName() + ", Fill Color : " + FillColor);
}

CFigure* CRectangle::CopyFigure()
{
	CFigure* Rectangle=new CRectangle(Corner1,Corner2,FigGfxInfo);
	return Rectangle;
}

Point CRectangle::GetCenter()
{
	Point MiddlePoint;
	MiddlePoint=Corner1+Corner2;
	MiddlePoint/=2;
	return MiddlePoint;
}

void CRectangle::Move(Point NewCenter)
{
	Corner1+=NewCenter;
	Corner2+=NewCenter;
}

string CRectangle::getName() const
{
	return "RECTANGLE";
}

void CRectangle::rotate()
{
	Point center = GetCenter();
	Corner1.rotate(center);
	Corner2.rotate(center);
}

bool CRectangle::isSame(CFigure* figChoose) const
{
	return (dynamic_cast<CRectangle*>(figChoose));
}