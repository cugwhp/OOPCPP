#include "Point.h"

Point::Point(int x, int y) : m_x(x), m_y(y)
{
}

Point::Point(const Point& pt) : m_x(pt.m_x), m_y(pt.m_y)
{
}
