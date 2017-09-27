#include "Point.h"

int Point::m_nCount = 0;

Point::Point(int x, int y) : m_x(x), m_y(y)
{
	m_nCount ++;
}

Point::Point(const Point& pt) : m_x(pt.m_x), m_y(pt.m_y)
{
}

int
Point::GetCount()
{
	return Point::m_nCount;
}
