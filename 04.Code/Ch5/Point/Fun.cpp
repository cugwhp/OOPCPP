#include "Fun.h"
#include <cmath>
#include <iostream>
using namespace std;

int Add(int a, int b)
{
    return a+b;
}

int Sub(int a, int b)
{
    return a-b;
}

int Mul(int a, int b)
{
    return a*b;
}

int Div(int a, int b)
{
    return a/b;
}

int Pwr(int a, int b)
{
    int pwr =1.0;
    while(b-->0)
        pwr *= a;
    return pwr;
}

int Mod(int a, int b)
{
    return a%b;
}

X::X(int i) : m_i(i)
{

}

X::~X()
{

}

void X::show()
{
    cout << m_i << endl;
}

void Y::g(X* px)
{
    if (px != NULL)
        (px->m_i)++;
}
