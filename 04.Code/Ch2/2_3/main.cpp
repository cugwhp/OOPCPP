#include <iostream>

using namespace std;

int main()
{
    cout << "Input a Year: " << endl;
    int     nYear;
    int     nReverse = 0;
    int     nSum = 0;

    cin >> nYear;
    for (int i=1; i<=nYear; ++i)
    {
        if (i%2 == 1)
            nSum += i;

        if (nYear % i == 0)
            cout << i << "\t";
    }
    return 0;

    while(nYear>0)
    {
        nReverse = 10*nReverse + nYear%10;
        cout << nYear%10;
        nYear /= 10;
    }
    return 0;

    while (cin >> nYear)
    {
        if (nYear%4==0 && (nYear%100!=0 || nYear%400==0))
        {
            cout << nYear << " is a leap year." << endl;
        }
        else
        {
            cout << nYear << " is not a leap year." << endl;
        }


    }

    return 0;
}
