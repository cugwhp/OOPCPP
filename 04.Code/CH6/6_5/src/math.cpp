#include "math.h"
#include <cmath>
using std::sqrt;

int max(int a[], int ncount)
{
    if (ncount < 1) return 0;

    int imax = a[0];
    for (int i=0; i<ncount; ++i)
        imax = a[i]>imax ? a[i] : imax;

    return imax;
}

int min(int a[], int ncount)
{
    if (ncount < 1) return 0;

    int imin = a[0];
    for (int i=0; i<ncount; ++i)
        imin = a[i] < imin ? a[i] : imin;

    return imin;
}

float mean(int a[], int ncount)
{
    if (ncount < 1) return 0.0f;

    float   fmean = 0.0;
    for (int i=0; i<ncount; i++)
        fmean += a[i];
    fmean /= ncount;

    return fmean;
}

float stdv(int a[], int ncount)
{
    if (ncount < 2) return 0.0;

    float   fmean = mean(a, ncount);
    float   fstdv = 0.0;

    for (int i=0; i<ncount; ++i)
        fstdv += (a[i]-fstdv)*(a[i]-fstdv);
    fstdv = sqrt(fstdv/n-1);

    return 0;
}

