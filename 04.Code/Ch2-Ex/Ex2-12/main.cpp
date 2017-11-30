/******************************************************************************
// 输入一个整数，1）求数的位数；2）求每个位上的数；3）顺序和逆序输出
******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    long     num;
    int      indiv = 0;
    long     t;
    int     pDig[100];
    int     i;

    cout << "Input a Integer: ";
    cin >> num;

    // 位数
    t = num;
    while (t>0)
    {
        pDig[indiv++] = t%10;
        t /= 10;
    }
    cout << num << " is a " << indiv << " number." << endl;

    // 顺序打印
    for (i=indiv-1; i>=0; i--)
        cout << pDig[i];
    cout << endl;

    // 逆序打印
    for (i=0; i<indiv; i++)
        cout << pDig[i];
    cout << endl;

    return 0;
}
