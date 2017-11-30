#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line
{
    public:
        Line(Point pt1, Point pt2);
        virtual ~Line();

    protected:
    Point   m_pt1, m_pt2;

    private:
};

#endif // LINE_H
