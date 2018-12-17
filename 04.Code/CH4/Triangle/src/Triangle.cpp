#include "Triangle.h"
#include <cmath>
bool
Triangle::setTriangle(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;

    return isTriangle();
}

bool
Triangle::isTriangle()
{
    if (a+b>c && a+c>b && b+c>a && a>0.0 && b>0.0 && c>0.0)
        return true;

    return false;
}

float
Triangle::TriPrimer()
{
    if (isTriangle())
    {
        return this->a+this->b+this->c;
    }
    else
    {
        return 0.0f;
    }
}

float
Triangle::TriArea()
{
    if (isTriangle())
    {
        float   Primer = TriPrimer()/2.0;
        return sqrt(Primer*(Primer-a)*(Primer-b)*(Primer-c));
    }
    else
    {
        return 0.0f;
    }
}
