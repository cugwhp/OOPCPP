#include <iostream>
#include "Func.h"
#include <cmath>
#include <string>

using namespace std;

// ½»»»2¸öÊý
void swap2(int a, int b)
{
    int t = a;

    a = b;
    b = t;

    for (int i=0, int sum=0; i<9; i++)
    {
        sum += i;
    }
    cout << sum << endl;

    return;
}

int main()
{
    int     m,n;

    m = 10;
    n = 100;

    {
        int m = n;
        cout << m << endl;
    }
    cout << m << endl;

    swap2(m, n);
    cout << m << "\t" << n << endl;

    return 0;


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
