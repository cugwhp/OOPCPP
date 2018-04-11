#pragma once

#include "Shape.h"
#include "MyPoint.h"
#include <iostream>
using namespace std;

class CCircle : public CShape
{
public:
	CCircle(double r = 0.0f, double x0=0.0f, double yo=0.0f);
	~CCircle(void);

	friend istream& operator>>(istream& is, CCircle& c);
	friend ostream& operator<<(ostream& os, const CCircle& c);
public:
	virtual void Draw(CDC* pDC);	//绘制
	double GetArea();				//面积
	double GetPerimer();			//周长

	const CMyPoint& GetCenter();
	
private:
	double		m_dRadius;
	CMyPoint	m_ptCenter;	
};


istream& operator>>(istream& is, CCircle& c);
ostream& operator<<(ostream& os, const CCircle& c);