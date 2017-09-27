#pragma once
#include "shape.h"

class CRectangle : public CShape
{
public:
	CRectangle(int xmin=0, int ymin=0, int xmax=0, int ymax=0);
	~CRectangle(void);

public:
	double GetArea();		//面积
	double GetPerimer();	//周长
	POINT GetCenter();	//中心位置
	virtual void Draw(CDC* pDC);	//绘制

private:
	double	m_dWidth;	//宽度
	double	m_dHeight;	//高度
	POINT	m_pt1, m_pt2;
};
