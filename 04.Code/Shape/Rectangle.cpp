#include "StdAfx.h"
#include "Rectangle.h"
#include "math.h"

CRectangle::CRectangle(double dx1, double dy1, double dx2, double dy2) :
	CShape(), m_pt1(dx1, dy1), m_pt2(dx2,dy2)
{
	m_dWidth = fabs(dx1-dx2);
	m_dHeight = fabs(dy1-dy2);
	TRACE0("CRectangle::CRectangle()");
}

CRectangle::~CRectangle(void)
{
	TRACE0("CRectangle::~CRectangle()");
}

double CRectangle::GetArea()		//面积
{
	return m_dWidth*m_dHeight;
}

double CRectangle::GetPerimer()	//周长
{
	return 2*(m_dWidth+m_dHeight);
}

void CRectangle::Draw(CDC* pDC)
{
	pDC->Rectangle(int(m_pt1.m_dX), int(m_pt1.m_dY),
		int(m_pt2.m_dX), int(m_pt2.m_dY));
}

istream& operator>>(istream& is, CRectangle& r)
{
	is >> r.m_pt1.m_dX >> r.m_pt1.m_dY >> r.m_pt2.m_dX >> r.m_pt2.m_dY;

	return is;
}

ostream& operator<<(ostream& os, const CRectangle& r)
{
	os << "1\t" << r.m_pt1.m_dX << "\t" << r.m_pt1.m_dY << "\t";
	os << r.m_pt2.m_dX << "\t" << r.m_pt2.m_dY;
	return os;
}