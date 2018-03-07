#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>

using namespace std;

////////////////////////////////////////////////////
// class Point
///////////////////////////////////////////////////
class Point
{
public:
    Point(float x=0.0, float y=0.0) : X(x), Y(y) {}
    ~Point() {};

    friend ostream& operator<<(ostream&os, const Point& pt);

    void Move(float xoff, float yoff) {X+=xoff; Y+=yoff;}

    float GetX() const { return X;}
    float GetY() const { return Y;}

private:
    float   X, Y;
};

/////////////////////////////////////////////////
// class Point3D derived from Point
/////////////////////////////////////////////////
class Point3D : public Point
{
public:
    Point3D(float x, float y, float z) : Point(x, y), Z(z) {}
    ~Point3D() {}

    float GetZ() const {return Z;}

private:
    float   Z;
};


#endif // POINT_H_INCLUDED
