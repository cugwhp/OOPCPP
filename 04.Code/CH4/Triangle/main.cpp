#include <iostream>
#include "Triangle.h"
using namespace std;


int main()
{
    float a, b, c;
    cin >> a >> b >> c;

    Triangle    oTriangle;
    oTriangle.setTriangle(a, b, c);

    if (true)//oTriangle.isTriangle())
    {
        cout << "Primer : " << oTriangle.TriPrimer() << endl;
        cout << "Area : " << oTriangle.TriArea() << endl;
    }
    else
    {
        cerr << "invalidate triangle." << endl;
    }

    return 0;
}
