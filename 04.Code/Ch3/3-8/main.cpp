#include <iostream>

using namespace std;

int Fac(int);

int main()
{
    int     n;
    cout << "Input a Integer number : " << endl;
    cin >> n;

    cout << n << "! = " << Fac(n) << endl;

    return 0;
}

// µÝ¹éº¯ÊýÇón!
int Fac(int n)
{
    return (0 == n) ? 1 : n*Fac(n-1);
}
