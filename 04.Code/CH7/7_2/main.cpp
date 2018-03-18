#include <iostream>
#include "Base.h"

using namespace std;

int main()
{
    Base    b(10);
    Base    b2(cin);

    Base    b3 = 30;    //ÒşÊ½×ª»»
    Base    b4 = cin;

    cout << sizeof(b) << endl;

    b.Print();
    b2.Print();

    return 0;
}
