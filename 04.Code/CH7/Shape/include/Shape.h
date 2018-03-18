#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape
{
public:
   Shape();
   virtual ~Shape();

   virtual double GetArea() const = 0;
   virtual double GetPerimeter() const = 0;

protected:

private:
};

ostream& operator<<(ostream& os, const Shape& shp);


#endif // SHAPE_H
