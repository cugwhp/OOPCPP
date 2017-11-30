#include <iostream>

using namespace std;

bool IsSymmetrNum(int);

int main()
{
    int     n;
    int     i;

    cout << "Input a integer : ";
    cin >> n;

    for (i=10; i<=n; ++i)
    {
        if (IsSymmetrNum(i))
            cout << i << "\t";
    }
    cout << endl;

    return 0;
}

bool IsSymmetrNum(int num)
{
    int     n;
    int     s = 0;

    n = num;
    while(n>0)
    {
        s = 10 * s + n%10;
        n /= 10;
    }

    return (s == num);
}
