#include <iostream>
using namespace std;

void RowSum(int A[][4], int nrow)
{	int sum;
	for (int i = 0; i < nrow; i++)
	{
		sum = 0;
		for(int j = 0; j < 4; j++)
			sum += A[i][j];
		cout << "Sum of row " << i           << " is " << sum << endl;
    A[i][0]=sum;
	}
} 

int StatAry(int a[], int n, int stat[])
{
	int			i;
	int			min = 0x7FFFFFFF;
	int			max =0xFFFFFFF;
	int			sum = 0;
	int			mean;
	
	max = -max;
	for (i=0; i<n; ++i)
	{
		min = a[i] < min ? a[i] : min;
		max = a[i] > max ? a[i] : max;
		sum += a[i];
	}
	mean = sum / n;

	stat[0] = min;
	stat[1] = max;
	stat[2] = mean;
	stat[3] = sum;

	return 0;
}