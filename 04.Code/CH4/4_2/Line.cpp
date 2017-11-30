#include "Line.h"
#include <iostream>
#include <cmath>

using namespace std;

CLine::CLine() : m_P1(0, 0), m_P2(0, 0)
{
}

CLine::CLine(const CPoint& p1, const CPoint& p2) : m_P1(p1), m_P2(p2)
{
	cout << "CLine constructor is called @" << this << endl;
}

CLine::CLine(const CLine& CLine) : m_P1(CLine.m_P1), m_P2(CLine.m_P2)
{
	cout << "CLine copy constructor is called @" << this << endl;
}

CLine::~CLine()
{
	cout << "CLine deconstructor is called @" << this << endl;
}

double
CLine::Length() const
{
	double		dfLen = 0.0f;
	
	double		dfDeltaX;
	double		dfDeltaY;

	dfDeltaX = m_P1.GetX() - m_P2.GetX();
	dfDeltaY = m_P1.GetY() - m_P2.GetY();
	dfLen = sqrt(dfDeltaX*dfDeltaX + dfDeltaY*dfDeltaY);
	
	return dfLen;
}
