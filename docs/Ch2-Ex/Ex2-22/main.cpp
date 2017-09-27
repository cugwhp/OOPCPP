#include <iostream>

using namespace std;

int main()
{
    int     day = 9, x = 1;
    while(day > 0)
    {
        x = (x+1)*2;
        day--;
    }

    cout << "total = " << x << endl;
    return 0;
}
