#pragma once

#include "Shape.h"

class CCircle : public CShape
{
public:
	CCircle(int r = 0, int x0=0, int yo=0);
	~CCircle(void);

public:
	virtual void Draw(CDC* pDC);	//绘制
	double GetArea();		//面积
	double GetPerimer();	//周长

	POINT GetCenter();	
private:
	int			m_nRadius;
	POINT		m_ptCenter;	
};
