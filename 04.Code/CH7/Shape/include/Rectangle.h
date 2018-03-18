#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle();
        virtual ~Rectangle();

    virtual double GetArea() const;
   virtual double GetPerimeter() const;


    protected:

    private:
};

#endif // RECTANGLE_H
