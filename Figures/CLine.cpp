#include "CLine.h"



CLine::CLine()
{
}

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
	FigGfxInfo.isFilled = true;
}

void CLine::Draw(Output* pOut) const
{
	if (Visible)
		pOut->DrawLine(Start, End, FigGfxInfo, Selected);
}

bool CLine::IsInside(Point P)
{
	const int space = 8;
	if (!Visible)
		return false;
	int x = End.x - Start.x;
	int y = End.y - Start.y;
	int X_min = min(Start.x, End.x) - space;
	int X_max = max(Start.x, End.x) + space;
	int Y_min = min(Start.y, End.y) - space;
	int Y_max = max(Start.y, End.y) + space;

	if ((fabs((x*P.y - y*P.x + y*Start.x - x*Start.y) / sqrt(pow(x, 2) + pow(y, 2))) <= space) && P.x >= X_min && P.x <= X_max && P.y >= Y_min && P.y <= Y_max) {
		return true;
	}
	return false;
}

void CLine::Save(ofstream & OutFile) const
{
	OutFile << "LINE\t" << ID << "\t"
		<< Start.x << "\t" << Start.y << "\t" << End.x << "\t" << End.y << "\t"
		<< getColorNumber(FigGfxInfo.DrawClr) << endl;
}

void CLine::Load(ifstream & Infile)
{
	int color;
	Infile >> ID >> Start.x >> Start.y >> End.x >> End.y >> color;
	FigGfxInfo.DrawClr = getColorByNumber(color);
	FigGfxInfo.isFilled = true;
	Infile.ignore();
}

void CLine::PrintInfo(Output* pOut)
{
	string strID = to_string(ID);
	string strStart = "(" + to_string(Start.x) + "," + to_string(Start.y) + ")";
	string strEnd = "(" + to_string(End.x) + "," + to_string(End.y) + ")";
	int Length = round(sqrt(pow(Start.x - End.x, 2) + pow(Start.y - End.y, 2)));
	string strLength = to_string(Length);
	pOut->PrintMessage("Line  |  ID : " + to_string(ID) + "  |  Start : " + strStart + ", End : " + strEnd + "  |  Length : " + strLength
		+ "  |  Draw Color : " + FigGfxInfo.DrawClr.getName());
}

void CLine::ChngFillClr(color Fclr)
{}

CFigure* CLine::CopyFigure()
{
	CFigure* Line=new CLine(Start,End,FigGfxInfo);
	return Line;
}

Point CLine::GetCenter()
{
	Point MiddlePoint;
	MiddlePoint=Start+End;
	MiddlePoint/=2;
	return MiddlePoint;
}

void CLine::Move(Point NewCenter)
{
	Start+=NewCenter;
	End+=NewCenter;
}

color CLine::getFigColor() const
{
	return FigGfxInfo.DrawClr;
}

string CLine::getName() const
{
	return "LINE";
}

void CLine::rotate()
{
	Point center = GetCenter();
	Start.rotate(center);
	End.rotate(center);
}

bool CLine::isSame(CFigure* figChoose) const
{
	return (dynamic_cast<CLine*>(figChoose));
}
