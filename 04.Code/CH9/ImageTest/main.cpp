#include <iostream>
using namespace std;

class A
{
public:
    virtual int f(){return 0;}
    int m_a;
};

class B : public A
{
public:
    virtual int f(){return 1;}
    int m_b;
};

int main()
{
    A   a1,a2;
    B   b1,b2;
    a2 = b1;

    A*  pA = &b1;
    A&  ar = b1;

//    b2 = a1;

    return 0;
}
