#include <iostream>
#include <fstream>
using namespace std;

int Max(int* pData, int n);
int Min(int* pData, int n);

int main()
{
    int szHist[] = {10, 20, 30, 30,20,15,2,4,7,32,4,5,2,5,23,30,10};

    int iMax = Max(szHist, 17);
    int iMin = Min(szHist, 17);

    cout  << endl;
    cout << endl;
    for (int i=iMin; i<=iMax; i++)
    {
        for (int j=0; j<17; j++)
        {
            if (szHist[j] == (iMax-i))
                cout << "___";
            else if (szHist[j] > (iMax-i))
                cout << "| |";
            else
                cout << "   ";//(iMax==i ? "___" : "  ");
        }

        cout << endl;
    }
    return 0;
}

int Max(int* pData, int n)
{
    int     iMax = 0;
    for (int i=0; i<n; ++i)
        iMax = pData[i]>iMax ? pData[i] : iMax;

    return iMax;
}

int Min(int* pData, int n)
{
    int     iMin = 0;
    for (int i=0; i<n; ++i)
        iMin = pData[i]<iMin ? pData[i] : iMin;
    return iMin;
}
