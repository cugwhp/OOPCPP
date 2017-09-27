#include <iostream>
#include "Func.h"
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string  strTxt = "CUG";
    strTxt.c_str();

    int     i = 2349;
    int     j = 23;
    swap(i, j);
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    return 0;

    double  y;
    y = Power(3.0, 3);
    cout << y << endl;

    cout << Power(4.0, 2) << endl;
    return 0;
}
