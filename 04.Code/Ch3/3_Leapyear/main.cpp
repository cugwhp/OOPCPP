#include <iostream>
#include <cmath>

using namespace std;

bool isLeapYear(int);

int main()
{
    cout << "char size :" << sizeof(char) << endl;
    cout << "short size :" << sizeof(short) << endl;
    cout << "int size :" << sizeof(int) << endl;
    cout << "long size :" << sizeof(long) << endl;
    cout << "float size :" << sizeof(float) << endl;
    cout << "double size :" << sizeof(double) << endl;
    cout << "long double size :" << sizeof(long double) << endl;
    return 0;

    int     nYear;
    do
    {
        cout << "Input a Year:";
        cin >> nYear;
//main.cpp: 'isLeapYear' was not declared in this scope|
//        if ((nYear%4==0 && nYear%100!=0) || nYear%400==0)
        if (isLeapYear(nYear))
            cout << nYear << " is leap year." << endl;
        else
            cout << nYear << " is not leap year." << endl;

    }while(nYear!=0);

    return 0;
}

bool isLeapYear(int y)
{
    return ((y%4==0 && y%100!=0) || y%400==0);
}

double arctan(double x)
{
    // arctan(x) = x - x^3/3 + x^5/5 + ...
    double  dRes = 0.0;
    double  de = x;
    int     i = 1;

    while(fabs(de/i) > 1e-15)
    {
        dRes += de/i;
        i += 2;

        de = -de*x*x;
    }

    return dRes;
}
