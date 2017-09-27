#include "Fun.h"
#include <iostream>
#include <cmath>

using namespace std;

int Min(int a[], int ncount)
{
	int		i;
	int		min = a[0];
	for (i=1; i<ncount; ++i)
	{
		min = a[i]<min ? a[i] : min;
	}

	return min;
}

int Max(int a[], int ncount)
{
	int		i;
	int		max = a[0];
	for (i=1; i<ncount; ++i)
	{
		max = a[i]>max ? a[i] : max;
	}

	return max;
}


int	Mean(int a[], int ncount)
{
	int		i;
	int		mean = 0;
	for (i=0; i<ncount; ++i)
	{
		mean += a[i];
	}
	mean /= ncount;
	
	return mean;
}

int Sum(int a[], int ncount)
{
	int		i;
	int		sum = 0;
	for (i=0; i<ncount; ++i)
	{
		sum += a[i];
	}
		
	return sum;
}

int Std(int a[], int ncount)
{
	if (ncount < 2)
		return 0;
	
	int		i;
	int		mean = 0;
	int		std = 0;
	for (i=0; i<ncount; ++i)
	{
		mean += a[i];
	}
	mean /= ncount;
	
	for (i=0; i<ncount; ++i)
	{
		std += (a[i]-mean)*(a[i]-mean);
	}
	std = sqrt(std*1.0) / (ncount-1);
	
	return mean;
}