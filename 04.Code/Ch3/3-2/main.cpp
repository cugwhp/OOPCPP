#include <iostream>

using namespace std;

//
int Bin2Dec(int);
double Power(double, int);

int main()
{
    int     nBin;

    cout << "Input a binary number: " << endl;
    cin >> nBin;

    cout << "\t" << Bin2Dec(nBin) << endl;

    return 0;
}

//二进制->十进制
int Bin2Dec(int nBin)
{
    int     nDec = 0;
    int     nDig;

    while(nBin > 0)
    {
        nDig = nBin%10;
        nDec = 2*nDec + nDig;
        nBin /= 10;
    }

    return nDec;
}

// 求f的n次方
double Power(double f, int n)
{
    double      dVal = 1.;
    while (n>0)
    {
        dVal *= f;
        n--;
    }

    return dVal;
}
