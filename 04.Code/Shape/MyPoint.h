#pragma once

class CMyPoint
{
public:
	CMyPoint(double x=0.0f, double y=0.0f);
	~CMyPoint(void);

	double Distance(CMyPoint& pt2);

public:
	double	m_dX;
	double	m_dY;
};
