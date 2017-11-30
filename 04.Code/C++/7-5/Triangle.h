#pragma once
#include "shape.h"

class CTriangle : public CShape
{
public:
	CTriangle(int x1=0, int y1=0, int x2=0, int y2=0, int x3=0, int y3=0);
	~CTriangle(void);

	virtual double GetArea();		//面积
	virtual double GetPerimer();	//周长
	virtual void Draw(CDC* pDC);	//绘制图形

	virtual POINT GetCenter();		//中心位置

	bool GetLen(double daryLen[]);	//边长
private:
	POINT	m_pt1, m_pt2, m_pt3;
};
