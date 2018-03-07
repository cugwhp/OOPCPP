#include <iostream>
#include "Point.h"

using namespace std;

ostream& operator<<(ostream& os, const Point& pt)
{
    os << pt.GetX() << ","
       << pt.GetY();

    return os;
}

int main()
{
    Point3D pt3d(2.,3.,20.);

    pt3d.Move(3., 2.);

    Point&  pt = pt3d;
    cout << pt << endl;

    cout << pt3d << endl;

    return 0;
}
