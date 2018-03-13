#include <iostream>
#include "Base.h"

using namespace std;

void PrintObjSize(Base& b)
{
    cout << sizeof(b) << endl;
}

int main()
{
    Base    b;
    B1      b1;
    B2      b2;
    C       c;

    PrintObjSize(b);
    PrintObjSize(b1);
    cout << sizeof(b1) << endl;
    PrintObjSize(b2);
    cout << sizeof(b2) << endl;
//    PrintObjSize(c);
    cout << sizeof(C) << endl;

    return 0;
}
