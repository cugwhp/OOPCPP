#include "StdAfx.h"
#include "Triangle.h"
#include "math.h"

CTriangle::CTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	m_pt1.x = x1;
	m_pt1.y = y1;
	m_pt2.x = x2;
	m_pt2.y = y2;
	m_pt3.x = x3;
	m_pt3.y = y3;
}

CTriangle::~CTriangle(void)
{
}


//面积
double CTriangle::GetArea()
{
	double	dAryLen[3];
	double	dP;

	if (!GetLen(dAryLen))
		return 0.0f;

	dP = (dAryLen[0]+dAryLen[1]+dAryLen[2]) / 2;
	
	return sqrt(dP*(dP-dAryLen[0])*(dP-dAryLen[1])*(dP-dAryLen[2]));
}

//周长
double CTriangle::GetPerimer()
{
	double	dAryLen[3];

	if (!GetLen(dAryLen))
		return 0.0f;

	return (dAryLen[0]+dAryLen[1]+dAryLen[2]);
}

//边长
bool 
CTriangle::GetLen(double daryLen[])
{
	if (daryLen == NULL)
		return false;

	daryLen[0] = sqrt(pow(double(m_pt1.x-m_pt2.x), 2) + pow(double(m_pt1.y-m_pt2.y), 2));
	daryLen[1] = sqrt(pow(double(m_pt2.x-m_pt3.x), 2) + pow(double(m_pt2.y-m_pt3.y), 2));
	daryLen[2] = sqrt(pow(double(m_pt3.x-m_pt1.x), 2) + pow(double(m_pt3.y-m_pt1.y), 2));

	if (daryLen[0]+daryLen[1] > daryLen[2] &&
		daryLen[1]+daryLen[2] > daryLen[0] &&
		daryLen[2]+daryLen[0] > daryLen[1])
	{
		return true;
	}

	return false;
}

//绘制图形
void CTriangle::Draw(CDC* pDC)
{
	pDC->MoveTo(m_pt1);
	pDC->LineTo(m_pt2);	
	pDC->LineTo(m_pt3);
	pDC->LineTo(m_pt1);
}

//中心位置
POINT CTriangle::GetCenter()
{
	POINT	pt0;

	pt0.x = (m_pt1.x+m_pt2.x+m_pt3.x)/3;
	pt0.y = (m_pt1.y+m_pt2.y+m_pt3.y)/3;

	return pt0;
}
