#include <iostream>

using namespace std;

/*
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/

int main()
{
    int     i = 1;
    int     sum = 0;

    do
    {
        sum += i++;   //sum = sum + i
    }while(i<=10);
    cout << "Sum = " << sum << endl;

    return 0;
}
