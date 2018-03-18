#include "Base.h"
#include <iostream>
using namespace std;


Base::Base(int i) : m(i)
{
    m = i;
    //ctor
}

Base::Base(istream& is)
{
    is >> m;
}

Base::Base(const Base& b) : m(b.m)
{
    m = b.m;
}

Base::~Base()
{
    //dtor
}

void Base::Print()
{
    cout << m << endl;
}
