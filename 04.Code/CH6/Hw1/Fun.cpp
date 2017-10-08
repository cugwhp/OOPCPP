#include "Fun.h"
/*
// 1D Matrix
int Sum(int a[], int ncount)
{
	int		sum = 0;
	int		i;
	for (i=0; i<ncount; ++i)
	{
		sum += a[i];
	}

	return sum;
}
*/

// Pointer -> 1D Matrix
int Sum(int *pAry, int ncount)
{
	int		sum = 0;
	int		i;
	for (i=0; i<ncount; ++i)
	{
		sum += pAry[i];
	}

	return sum;
}

// 2D Matrix
int Sum(int a[][3], int ncount)
{
	int		sum = 0;
	int		i;
	int		j;
	for (i=0; i<ncount; ++i)
	{
		for (j=0; j<3; ++j)
		{
			sum += a[i][j];
		}
	}

	return sum;
}

/*
// Point -> 2D Matrix
int Sum(int (*pAry)[3], int ncount)
{
	int		sum = 0;
	int		i;
	int		j;
	for (i=0; i<ncount; ++i)
	{
		for (j=0; j<3; ++j)
		{
			sum += pAry[i][j];
		}
	}

	return sum;
}
*/