#include <iostream>
#include "Fun.h"

using namespace std;

template<class T>
void Swap(T& a, T& b)
{
    a = a+b;
    b = a-b;
    a = a-b;
    return;
}
int main()
{
    int     a=10, b=100;

    cout << a << "\t" << b << endl;
    Swap(a, b);
    cout << a << "\t" << b << endl;
    return 0;

    X       x;
    Y       y;
    y.g(&x);

//    int a;
//    int b;
    char    cOper;
    int (*pFun)(int, int);


    cout <<"Input an Expression: ";

    do
    {

    cin >> a >> cOper >> b;

    switch(cOper)
    {
    case '+':
        pFun = Add;
        break;
    case '-':
        pFun = Sub;
        break;
    case '*':
        pFun = Mul;
        break;
    case '/':
        pFun = Div;
        break;
    case '^':
        pFun = Pwr;
        break;
    case '%':
        pFun = Mod;
        break;
    default:
        pFun = NULL;
        break;
    }

    if (pFun != NULL)
        cout << a << cOper << b << "=" << pFun(a, b) << endl;
    else
        cerr << "Expression is invalidate" << endl;

    }while(cOper != 'q');

    return 0;
}
