#pragma once

#ifndef PI
	#define PI 3.14159265358979323846
#endif

class CShape
{
public:
	CShape(void);
	virtual ~CShape(void);

public:
	// virtual 接口
	virtual double GetArea() = 0;		//面积
	virtual double GetPerimer() = 0;	//周长
	virtual void Draw(CDC* pDC) = 0;	//绘制图形
	virtual POINT GetCenter() = 0;		//中心位置

	void DrawInfo(CDC* pDC);	
};
