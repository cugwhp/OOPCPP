#include "StdAfx.h"
#include "Circle.h"
#include <math.h>

CCircle::CCircle(int r, int x0, int y0) : CShape()
{
	m_nRadius = abs(r);
	m_ptCenter.x = x0;
	m_ptCenter.y = y0;

	TRACE0("CCircle::CCircle()");
}

CCircle::~CCircle(void)
{
	TRACE0("CCircle::~CCircle()");
}

double CCircle::GetArea()
{
	return PI*m_nRadius*m_nRadius;
}

double CCircle::GetPerimer()
{
	return 2*PI*m_nRadius;
}

void CCircle::Draw(CDC* pDC)
{
	pDC->Ellipse(m_ptCenter.x-m_nRadius, m_ptCenter.y-m_nRadius, 
		m_ptCenter.x+m_nRadius, m_ptCenter.y+m_nRadius);
}

POINT
CCircle::GetCenter()
{
	return m_ptCenter;
}