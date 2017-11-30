// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "Line.h"
#include <cmath>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine() : m_pt1(), m_pt2()
{
	cout << "Line Constructor." << endl;
}

CLine::CLine(const CPoint& pt1, const CPoint& pt2) : m_pt1(pt1), m_pt2(pt2)
{
	cout << "Line Constructor." << endl;
}

CLine::CLine(const CLine& line) : m_pt1(line.m_pt1), m_pt2(line.m_pt2)
{
	cout << "Line Constructor." << endl;
}

CLine::~CLine()
{
	cout << "Line Deconstructor." << endl;
}

double CLine::Distance()
{
	int		dx = m_pt1.GetX() - m_pt2.GetX();
	int		dy = m_pt1.GetY() - m_pt2.GetY();

	return sqrt(dx*dx+dy*dy);
}