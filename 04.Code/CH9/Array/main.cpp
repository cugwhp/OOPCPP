#include <iostream>
#include "Array.h"
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
struct Mul : public binary_function<T, T, T>
{
    T operator()(T t1, T t2)
    {
        return t1*t2;
    }
};

int main()
{
    int b[] = {0, 1, 2, 3, 4};
    Array<int>  a(&b[0], 1);
    Array<int>  a2 = a;
    Array<int>  a3(&b[0],3);

//    a2 = a;
//    a2 = a3 = a;
    a2 = a3;
    a2.operator=(a3);

    accumulate(&b[0], &b[4], 1, Mul<int>());

    return 0;
}


