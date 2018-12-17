#include<iostream>
using namespace std;

int main()
{
    // 1. 指针 -> 变量
    int     i = 10;
    int*    pi = &i;
    cout << pi << ":\t" << *pi << endl;

    // constant pointer
    int     j = 100;
    const int*  cpi = &i;
//    *cpi = j;
    cpi = &j;
    cout << cpi << ":\t" << *cpi << endl;

    int* const pci = &i;
    *pci = j;
//    pci = &j;
    cout << pci << ":\t" << *pci << endl;

    // 2. 数组指针
    int ary[5] = {1,2,3,4,5};
    int*    pary = ary;
    pary = &ary[0];

    for (int i=0; i<5; i++)
    {
        cout << pary[i] << "\t";
    }
    cout << endl;

    for (int i=0; i<5; i++)
    {
        cout << *(pary+i) << "\t";
    }
    cout << endl;

    //-------------- 2维数组 ------------//
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int (*pa)[4];
	pa = a;

    for (int j=0; j<3; j++)
    {
        cout << pa[j] << ":\t";
        for (int k=0; k<4; k++)
        {
            cout << pa[j][k] << "\t";
        }
        cout << endl;
    }

    cout << *(*(pa+2)+2) << endl;

    // 3. 指针引用
    int* &ptr = pi;

    // 4. 指针 -> 数组
    int*    pp[5];

    // 5. 指针 -> 函数
    int (*f)(int&);

	return 0;
}
