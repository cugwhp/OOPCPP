#include "Pointer.h"
#include <iostream>
using namespace std;

// 指针变量函数
void TestPointerVariable()
{
    cout << "//------------- Test Pointer Variable --------------//" << endl;
    // 指针变量
    int         i = 3;
    int*        pi = &i;

    cout << pi << ": " << *pi << endl;

    // const 指针变量
    const int*  p1 = &i;
//    *p1 = 4;
    cout << p1 << ": " << *p1 << endl;

    // const 指针变量
    int const* p2 = &i;
//    *p2 = 5;
    cout << p2 << ": " << *p2 << endl;

    // const 指针变量
    int* const p3 = &i;
    //*p3 = i*i;
    cout << p3 << ": " << *p3 << endl;

    // 指针变量的引用
    int* &p4 = pi;
    cout << p4 << ": " << *p4 << endl;

    cout << "====================================================" << endl;
    return;
}

////////////////////////////////////////////////
// 指向数组的指针
////////////////////////////////////////////////
void TestPointer2Array()
{
    cout << "//------------- Test Pointer to Array --------------//" << endl;
    // 指向数组的指针变量
    int     a[5] = {1,2,3,4,5};
    int*    pa = a; //pa = &a[0];
    for (int i=0; i<5; i++)
    {
        cout << a+i << ": " << a[i] << endl;
    }

    for (auto i : a)
    {
        cout << &i << ": " << i << endl;
    }

    for (int i=0; i<5; i++)
    {
        cout << pa+i << ": " << pa[i] << endl;
        cout << pa+i << ": " << *(pa+i) << endl;
    }

    int     a2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int     (*pa2)[4] = a2;
//    int*    pa22 = a2;
    for (auto i : a2)
    {
        cout << i << "\t";
    }
    cout << endl;
    cout << "====================================================" << endl;
}

// 指针数组
void TestPointerArray()
{
    cout << "//------------- Test Pointer Array -----------------//" << endl;
    int     a[3] = {3,6,9};
    int*    pa[3] = {a,a+1,a+2};

    int**    ppa = pa;

    for (auto pt : pa)
    {
        cout << pt << ": " << *pt << endl;
    }

    cout << "====================================================" << endl;
}

template<class T>
void Swap(T* px, T* py)
{
    T    t;
    t = *px;
    *px = *py;
    *py = t;
}

template<class T>
T sum(T* pt, int n)
{
    T       nsum = 0;
    for (int i=0; i<n; i++)
    {
        nsum += pt[i];
    }

    return nsum;
}


// 指针参数传递
void TestPointerParameter()
{
    cout << "//------------- Test Pointer Parameter ------------//" << endl;
    int     a[10] = {1,2,3,4,5,6,7,8,9,10};
    int*    pa = a;
    Swap(pa, pa+1);

    cout << sum(a, 10) << endl;

    int     i = 5;
    int     b[1] = {10};
    cout << sum(&i, 5) << endl;
    sum(b, 1);

    cout << "====================================================" << endl;
}

// 分配内存
void TestPointerAlloc()
{
    cout << "//------------- Test Pointer Alloc -----------------//" << endl;

    int  n;
    cout << "Input count : ";
    cin >> n;

    int*     p = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> p[i];
    }

    cout << sum(p, n) << endl;
    delete[] p;

    int*    p1 = new int;
    delete p1;

    int*     pa = new int[10];


    delete[] pa;

    int**    ppa = nullptr;


    cout << "====================================================" << endl;
}

int Min(int* pt, int n)
{
    int iMin = pt[0];
    for (int i=0; i<n; i++)
    {
        iMin = pt[i] < iMin ? pt[i] : iMin;
    }

    return iMin;
}

int Max(int* pt, int n)
{
    int     iMax = pt[0];
    for (int i=1; i<n; i++)
    {
        iMax = pt[i] > iMax ? pt[i] : iMax;
    }
    return iMax;
}

int Mean(int* pt, int n)
{
    int iMean = 0;
    for (int i=0; i<n; i++)
    {
        iMean += pt[i];
    }
    return iMean/n;
}

// 指向函数的指针
void TestPointer2Function()
{
    cout << "//----------- Test Pointer to Function ------------//" << endl;
    int nType;
    cout << "compute type (0-2):";
    cin >> nType;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    int (*pf[3])(int*, int) = {Min, Max, Mean};
    typedef int INT;    //INT -- int bias name

    typedef int (*PF)(int*, int);   //PF --
    PF pfs[3];


    cout << "Res = " << pf[nType](a, 10) << endl;


    switch(nType)
    {
    case 0:
        cout << "Min= " << Min(a, 10) << endl;
        break;
    case 1:
        cout << "Max= " << Max(a, 10) << endl;
        break;
    case 2:
        cout << "Mean = " << Mean(a, 10) << endl;
        break;
    default:
        break;
    }
    cout << "====================================================" << endl;
}
