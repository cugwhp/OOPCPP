 #include "Func.h"
 #include <iostream>
 using namespace std;

double Power(double x, int n)
{
    double  y=1.0;

    while(n>0)
    {
        y *= x;
        n--;
    }

///    y += Add(n, n);

    return y;
}

int Add(int a, int b)
{
    return a+b;
}

/*
void PrintMsg(int n)
{
    cout << n << endl;

    while(n>0)
    {
        cout << n%10 << "\t";
        n /= 10;
    }

  return;
}
*/

void PrintMsg(int& n)
{
    cout << n << endl;

    while(n>0)
    {
        cout << n%10 << "\t";
        n /= 10;
    }

  return;
}

void swap(int& a, int& b)
{
    int     t;

    t = a;
    a = b;
    b = t;

   return;
}
