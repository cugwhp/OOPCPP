#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	Point		aryPts[10];
	Point		aryPts2[] = { Point(1,1), Point(1, 2), Point(1,3) };

	cout << Point::GetCount() << endl;

	Point*		ptPts[2];

	cout << Point::GetCount() << endl;
	
    const Point   pt1(1, 2);  /// point 1
    const Point   pt2(3, 4);  /// point 2

    Rectangle    rect(pt1, pt2);    /// rect

    cout << "Area: " << rect.Area() << endl;
    cout << "Perimeter: " << rect.Perimeter() << endl;

	return 0;
}
