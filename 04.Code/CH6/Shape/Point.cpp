// Point.cpp: implementation of the CPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "Point.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int CPoint::m_nPointCount = 0;

CPoint::CPoint(int x, int y) : m_x(x), m_y(y)
{
	cout << "Construct " << ++m_nPointCount << " Point Object." << endl;
}

CPoint::CPoint(const CPoint& pt) : m_x(pt.m_x), m_y(pt.m_y)
{
	cout << "Construct " << ++m_nPointCount << " Point Object." << endl;
}


CPoint::~CPoint()
{
	cout << "Deconstruct " << m_nPointCount-- << " Point Object." << endl;
}
