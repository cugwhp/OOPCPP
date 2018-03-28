#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(2.0, 3.0);
    Complex c3;
    double  d = 1.0f;

    c3 = c2+d;
    c3 = d+c2;


    c3 = operator+(c1,c2);  //ok?
    c3 = c1+c2; //==>operator+(c1,c2);

//    c3 = c1.operator+(c2);  //

    cout << c3 << endl;

    c3 = c1-c2;
    cout << c3 << endl;

    c3 = c1*c2;
    cout << c3 << endl;

    c3 = c3/c1;
    cout << c3 << endl;

    return 0;
}
