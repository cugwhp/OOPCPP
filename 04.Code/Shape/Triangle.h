#pragma once
#include "shape.h"
#include "MyPoint.h"
#include <iostream>
using namespace std;

class CTriangle : public CShape
{
public:
	CTriangle(double* dpX=NULL, double* dpY=NULL);	
	~CTriangle(void);
	
	friend istream& operator>>(istream& is, CTriangle& t);
	friend ostream& operator<<(ostream& os, const CTriangle& t);

public:
	virtual double GetArea();		//面积
	virtual double GetPerimer();	//周长
	virtual void Draw(CDC* pDC);	//绘制图形

protected:
	void GetNodeLen(double dL[3]);
private:
	CMyPoint	m_TriNodes[3];
};

istream& operator>>(istream& is, CTriangle& t);
ostream& operator<<(ostream& os, const CTriangle& t);