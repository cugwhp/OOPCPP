#include <iostream>

using namespace std;

int main()
{
    int     m, n;
    int     tmp;
    int     sum;
    int     r;

    // 输入2个整数
    cout << "Input 2 integer number: ";
    cin >> m >> n;

    // n存大的数，m存小的数
    if (n < m)
    {
        tmp = n;
        n = m;
        m = tmp;
    }

    sum = n * m;    //乘积

    // 约去法求最大公约数
    // 假定n>m, n=k*t, m=l*t,公约数为t. 现在的目的是求t，我假定n=s*m+r，若r=0,则t=m;若r!=0, 则n和m的公约数t等于m和r的公约数。
    while (0 != m)
    {
        r = n % m;
        n = m;
        m = r;
    }

    cout << "HCF = " << n << endl;
    cout << "LCD = " << sum/n << endl;

    return 0;
}
