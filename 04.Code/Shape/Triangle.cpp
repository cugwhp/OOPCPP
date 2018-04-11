#include "StdAfx.h"
#include "Triangle.h"
#include <cmath>
#include <numeric>
using namespace std;

CTriangle::CTriangle(double* dpX, double* dpY)
{
	m_TriNodes[0].m_dX = dpX ? *dpX : 0.0f;
	m_TriNodes[1].m_dX = dpX ? *(dpX+1) : 0.0f;
	m_TriNodes[2].m_dX = dpX ? *(dpX+2) : 0.0f;

	m_TriNodes[0].m_dY = dpY ? *dpY : 0.0f;
	m_TriNodes[1].m_dY = dpY ? *(dpY+1) : 0.0f;
	m_TriNodes[2].m_dY = dpY ? *(dpY+2) : 0.0f;
}


CTriangle::~CTriangle(void)
{
}


double CTriangle::GetArea()		//面积
{
	double		dL[3];
	GetNodeLen(dL);	//边长

	double	dS = accumulate(dL, dL+3, 0.0) / 2.;

	return sqrt(dS*(dS-dL[0])*(dS-dL[1])*(dS-dL[2]));
}

double CTriangle::GetPerimer()	//周长
{
	double		dL[3];
	GetNodeLen(dL);	//边长

	return accumulate(dL, dL+3, 0.0);
}

void CTriangle::Draw(CDC* pDC)	//绘制图形
{
	CPen	pen(0, 2, RGB(255, 0, 0));
	CPen*	pOldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(int(m_TriNodes[0].m_dX), int(m_TriNodes[0].m_dY));

	pDC->LineTo(int(m_TriNodes[1].m_dX), int(m_TriNodes[1].m_dY));	
	pDC->LineTo(int(m_TriNodes[2].m_dX), int(m_TriNodes[2].m_dY));
	pDC->LineTo(int(m_TriNodes[0].m_dX), int(m_TriNodes[0].m_dY));

	pDC->SelectObject(pOldPen);
}

void CTriangle::GetNodeLen(double dL[3])
{
	dL[0] = m_TriNodes[0].Distance(m_TriNodes[1]);
	dL[1] = m_TriNodes[1].Distance(m_TriNodes[2]);
	dL[2] = m_TriNodes[2].Distance(m_TriNodes[0]);
}


istream& operator>>(istream& is, CTriangle& t)
{
	is >> t.m_TriNodes[0].m_dX >> t.m_TriNodes[0].m_dY;
	is >> t.m_TriNodes[1].m_dX >> t.m_TriNodes[1].m_dY;
	is >> t.m_TriNodes[2].m_dX >> t.m_TriNodes[2].m_dY;

	return is;
}

ostream& operator<<(ostream& os, const CTriangle& t)
{
	os << "2\t";
	os << t.m_TriNodes[0].m_dX << "\t" << t.m_TriNodes[0].m_dY << "\t";
	os << t.m_TriNodes[1].m_dX << "\t" << t.m_TriNodes[1].m_dY << "\t";
	os << t.m_TriNodes[2].m_dX << "\t" << t.m_TriNodes[2].m_dY;

	return os;
}