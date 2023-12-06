#include "CCircle.h"


CCircle::CCircle()
{
}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = rint(sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)));
}

void CCircle::Draw(Output* pOut) const
{
	if(Visible)
		pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}

bool CCircle::IsInside(Point P)
{
	if (!Visible)
		return false;
	if (pow(P.x - Center.x, 2) + pow(P.y - Center.y, 2) <= pow(Radius, 2)) {
		return true;
	}
	return false;
}

void CCircle::Save(ofstream & OutFile) const
{
	OutFile << "CIRCLE\t" << ID << "\t"
		<< Center.x << "\t" << Center.y << "\t" << Radius << "\t"
		<< getColorNumber(FigGfxInfo.DrawClr) << "\t"
		<< (FigGfxInfo.isFilled ? getColorNumber(FigGfxInfo.FillClr) : -1) << endl;

}

void CCircle::Load(ifstream & Infile)
{
	Infile >> ID >> Center.x >> Center.y >> Radius;
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

void CCircle::PrintInfo(Output* pOut)
{
	string strID = to_string(ID);
	string strCenter = "(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
	string strRadius = to_string(Radius);

	string FillColor = FigGfxInfo.isFilled ? FigGfxInfo.FillClr.getName() : "Not Filled";

	pOut->PrintMessage("Circle  |  ID : " + to_string(ID) + "  |  Center : " + strCenter + ", Radius : " + strRadius
		+ "  |  Draw Color : " + FigGfxInfo.DrawClr.getName() + ", Fill Color : " + FillColor);
}

CFigure* CCircle::CopyFigure()
{
	Point P2=Center;
	P2.y+=Radius;
	CFigure *Circle=new CCircle(Center,P2,FigGfxInfo);
	return Circle;
}

Point CCircle::GetCenter()
{
	return Center;
}

void CCircle::Move(Point NewCenter)
{
	Center+=NewCenter;
}

string CCircle::getName() const
{
	return "CIRCLE";
}

bool CCircle::isSame(CFigure* figChoose) const
{
	return dynamic_cast<CCircle*>(figChoose);
}
