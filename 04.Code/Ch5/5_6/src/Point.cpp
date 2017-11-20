#include "Point.h"
#include <cmath>

Point::Point(int x, int y)
{
    //ctor
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    //dtor
}

double Distance(const Point& pt1, const Point& pt2)
{
    double  dDis = 0.0f;

    dDis = sqrt(pow(pt1.x-pt2.x, 2) + pow(pt1.y-pt2.y, 2));

    return dDis;
}

ostream& operator<<(ostream& os, const Point& pt)
{
    os << pt.x << "\t" << pt.y;

    return os;
}
