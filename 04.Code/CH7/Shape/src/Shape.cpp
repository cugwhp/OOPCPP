#include "Shape.h"

Shape::Shape()
{
    //ctor
}

Shape::~Shape()
{
    //dtor
}


ostream& operator<<(ostream& os, const Shape& shp)
{
    os << "Area:      " << shp.GetArea() << endl;
    os << "Perimeter: " << shp.GetPerimeter() << endl;
    return os;
}


