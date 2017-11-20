#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point
{
    public:
        Point(int x=0, int y=0);
        virtual ~Point();

        friend double Distance(const Point& pt1, const Point& pt2);

        friend ostream& operator<<(ostream& os, const Point& pt);

    protected:
        int     x, y;

    private:
};

//double Distance(const Point& pt1, const Point& pt2);

//ostream& operator<<(ostream& os, const Point& pt);

#endif // POINT_H
