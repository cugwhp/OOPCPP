#pragma once
#include "shape.h"
#include "MyPoint.h"
#include <iostream>
using namespace std;

class CRectangle : public CShape
{
public:
	CRectangle(double dx1=0.0f, double dy1=0.0f, double dx2=0.0f, double dy2=0.0f);
	~CRectangle(void);

	friend istream& operator>>(istream& is, CRectangle& r);
	friend ostream& operator<<(ostream& os, const CRectangle& r);

public:
	double GetArea();				//面积
	double GetPerimer();			//周长
	virtual void Draw(CDC* pDC);	//绘制

private:
	double	m_dWidth;	//宽度
	double	m_dHeight;	//高度
	CMyPoint	m_pt1, m_pt2;
};

istream& operator>>(istream& is, CRectangle& r);
ostream& operator<<(ostream& os, const CRectangle& r);