#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account ac1(100000.0f);
    Account ac2 = 1000.0f;
    Account ac3 = ac1;
    Account ac4{1000.0f};

    ac3 = 1000.0f;
    ac3 = ac1;

    return 0;
}
