#include "StdAfx.h"
#include "Rectangle.h"
#include "math.h"

CRectangle::CRectangle(int xmin, int ymin, int xmax, int ymax) : CShape()
{
	m_pt1.x = xmin;
	m_pt1.y = ymin;
	m_pt2.x = xmax;
	m_pt2.y = ymax;
	m_dWidth = abs(xmax-xmin);
	m_dHeight = abs(ymax-ymin);
	TRACE0("CRectangle::CRectangle()");
}

CRectangle::~CRectangle(void)
{
	TRACE0("CRectangle::~CRectangle()");
}

double CRectangle::GetArea()	//面积
{
	return m_dWidth*m_dHeight;
}

double CRectangle::GetPerimer()	//周长
{
	return 2*(m_dWidth+m_dHeight);
}

void CRectangle::Draw(CDC* pDC)
{
	pDC->Rectangle(m_pt1.x, m_pt1.y, m_pt2.x, m_pt2.y);
}

POINT
CRectangle::GetCenter()
{
	POINT	pt0;
	pt0.x = (m_pt1.x + m_pt2.x)/2;
	pt0.y = (m_pt1.y + m_pt2.y)/2;

	return pt0;
}