#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    public:
        Circle(double r=0.0f);
        virtual ~Circle();

   virtual double GetArea() const;
   virtual double GetPerimeter() const;

    protected:

    private:
        double  m_dRadius;
};

#endif // CIRCLE_H
