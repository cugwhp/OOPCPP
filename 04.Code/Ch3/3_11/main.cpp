#include <iostream>
#include <cmath>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

int a[10];  //a-array name, 10 - size
int sum(int a[], int ncount)
{
    int     isum = 0;
    for (int i=0; i<ncount; ++i)
        isum+= a[i];
    return isum;
}

float sum(float f[][4], int ncount)
{

}

int main()
{
    int A[10]={1,2,3,4,5,6,7,8,9,0};
    float   f[3][4];

    cout << sum(A, 10) << endl;
    cout << sum(A, 5) << endl;
    cout << sum(A+3, 5) << endl;

    cout << f << endl;
    cout << f[0][0] << endl;
    cout << f[1][1] << endl;
    cout << f[2] << endl;
    cout << f[100] << endl;
    return 0;
}
