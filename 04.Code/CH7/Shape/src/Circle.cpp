#include "Circle.h"
#include <cmath>

Circle::Circle(double r) : Shape(), m_dRadius(r)
{
    //ctor
}

Circle::~Circle()
{
    //dtor
}

double Circle::GetArea() const
{
    return atan(1.0)*4.0*m_dRadius*m_dRadius;
}

double Circle::GetPerimeter() const
{
    return 8.8*atan(1.0)*m_dRadius;
}
