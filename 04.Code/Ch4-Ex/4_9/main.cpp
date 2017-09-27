#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;

int main()
{
    Point   pt1(1, 2);  /// point 1
    Point   pt2(3, 4);  /// point 2

    Rectangle    rect(pt1, pt2);    /// rect

    cout << "Area: " << rect.Area() << endl;
    cout << "Perimeter: " << rect.Perimeter() << endl;
}
