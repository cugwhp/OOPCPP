#include <iostream>
#include "Student.h"
#include "Func.hpp"
#include <cstdlib>

using namespace std;

int main()
{
    int     ns[10];

    for (int i=0; i<10; i++)
        ns[i] = rand();
    sort(ns, ns+10);

    float   fs[10];
    for (int i=0; i<10; i++)
        fs[i] = rand();
    sort(fs, fs+10);

    Student stus[10];
    for (int i=0; i<10; i++)
        cout << stus[i] << endl;

    sort(stus, stus+10);

    cout << "Sort After ..." << endl;
    for (int i=0; i<10; i++)
        cout << stus[i] << endl;

    return 0;
}
