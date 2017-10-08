#include <iostream>

using namespace std;

bool IsNarcissusNum(int);   //声明水仙花数判断函数

int main()
{
    int     i;
    for (i=100; i<1000; ++i)
    {
        if (IsNarcissusNum(i))
        {
            cout << i << "\t";
        }
    }   //for

    return 0;
}

//-------------------------------------------//
// 水仙花数判断函数
//------------------------------------------//
bool IsNarcissusNum(int num)
{
    int     digital;
    int     sum = 0;
    int     org = num;
    while(org > 0)
    {
        digital = org % 10; //最末尾数字

        sum += digital * digital * digital; //计算3次方
        org /= 10;  //舍弃末尾数字
    }

    //判断sum是否等于输入数
    return (sum == num);
}
