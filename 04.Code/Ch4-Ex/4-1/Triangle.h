#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

class CTriangle
{
public:
    double GetArea();
    double GetPerimeter();
    double GetAngle(int which);

private:
    double  a, b, c;
};


#endif // TRIANGLE_H_INCLUDED
