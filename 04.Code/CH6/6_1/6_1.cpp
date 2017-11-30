#include <iostream>
using namespace std;

int main()
{
	int		A[10];
	int		B[10];
	int		i;
	
	for (i=0; i<10; i++)
	{
		A[i] = 2*i + 1;
		B[10-i-1] = A[i];
	}

	for (i=0; i<10; i++)
	{
		cout << "A[" << i << "] = " << A[i] << "\t";
		cout << "B[" << i << "]= " << B[i] << endl;
	}
	
	return 0;
}