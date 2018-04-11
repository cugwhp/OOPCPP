#include "StdAfx.h"
#include "MyPoint.h"
#include <cmath>

CMyPoint::CMyPoint(double x, double y) : m_dX(x), m_dY(y)
{
}

CMyPoint::~CMyPoint(void)
{
}

double CMyPoint::Distance(CMyPoint& pt2)
{
	double	dX = m_dX-pt2.m_dX;
	double	dY = m_dY-pt2.m_dY;

	return sqrt(dX*dX + dY*dY);
}
