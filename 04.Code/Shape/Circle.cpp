#include "StdAfx.h"
#include "Circle.h"
#include <math.h>

CCircle::CCircle(double r, double x0, double y0) : CShape(), m_ptCenter(x0, y0)
{
	m_dRadius = fabs(r);

	TRACE0("CCircle::CCircle()");
}

CCircle::~CCircle(void)
{
	TRACE0("CCircle::~CCircle()");
}

double CCircle::GetArea()
{
	return PI*m_dRadius*m_dRadius;
}

double CCircle::GetPerimer()
{
	return 2*PI*m_dRadius;
}

void CCircle::Draw(CDC* pDC)
{
	pDC->Ellipse(int(m_ptCenter.m_dX-m_dRadius), int(m_ptCenter.m_dY-m_dRadius), 
		int(m_ptCenter.m_dX+m_dRadius), int(m_ptCenter.m_dY+m_dRadius));
}

// << >> ²Ù×÷·ûÖØÔØ
istream& operator>>(istream& is, CCircle& c)
{
	is >> c.m_ptCenter.m_dX >> c.m_ptCenter.m_dY >> c.m_dRadius;
	return is;
}

ostream& operator<<(ostream& os, const CCircle& c)
{
	os << "0\t" << c.m_ptCenter.m_dX << "\t" << c.m_ptCenter.m_dY << "\t" << c.m_dRadius;
	return os;
}