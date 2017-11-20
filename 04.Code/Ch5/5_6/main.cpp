#include <iostream>
#include "Point.h"
using namespace std;

class Point;

int main()
{
    Point   pt(10, 20);

    int     a = 10, c = 20;

    int&    b = a;

 //   b = c;  // a=c

    const int& d = a;
 //   a = c;

    a = c;
// error: assignment of read-only reference 'd'|

    cout << pt << endl;

    operator<<(cout, pt);

//    cout << "Hello world!" << endl;
    return 0;
}

// error: 'Test' was not declared in this scope|


void Test()
{
    cout << "Test" << endl;
    return;
}
