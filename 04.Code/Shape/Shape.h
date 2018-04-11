#pragma once

#ifndef PI
	#define PI 3.14159265358979323846
#endif

class CShape
{
public:
	CShape();
	virtual ~CShape();

public:
	virtual double GetArea() = 0;		//面积
	virtual double GetPerimer() = 0;	//周长
	virtual void Draw(CDC* pDC) = 0;	//绘制图形
};

