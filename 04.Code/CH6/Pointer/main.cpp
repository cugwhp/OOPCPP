#include <iostream>
#include "Pointer.h"

using namespace std;

int Pear(int n)
{
    if (n==10)
        return 1;
    else
        return 2*Pear(n+1)+2;
}

int Pear2(int n)
{
    int pear = 1;
    for (int nday=1; nday<n; ++nday)
        pear = 2*pear+2;
    return pear;
}

int main()
{
    cout << Pear(1) << endl;
    cout << Pear2(10) << endl;
    return 0;

    int     n;
    cout << "Test Type 1-6: ";
    while(cin >> n)
    {
        switch(n)
        {
        case 1:// 指针变量
            TestPointerVariable();
            break;

        case 2:
            // 指向数组的指针
            TestPointer2Array();
            break;
        case 3:
            // 指针数组
            TestPointerArray();
            break;
        case 4:
            // 指针参数传递
            TestPointerParameter();
            break;
        case 5:
            // 分配内存
            TestPointerAlloc();
            break;
        case 6:
            // 指向函数的指针
            TestPointer2Function();
            break;
        default:
            break;
        }
    }

    return 0;
}
