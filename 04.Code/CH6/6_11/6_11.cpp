#include <iostream>
#include "Fun.h"

using namespace std;

int main()
{
	int		a[10] = {1, 3, 5, 7, 8, 9, 20, 10, 20, 30};
	int		ncount = 10;

	int (*pfn)(int[], int) = 0L;

	cout << "Menu: 1-min, 2-max, 3-mean, 4-sum, 5-std,E/e-Exit" << endl;
	char	ch;
	do
	{
		cin >> ch;
		switch(ch)
		{	// 1-min, 2-max, 3-mean, 4-sum, 5-std
		case '1':
			pfn = Min;
			break;
		case '2':
			pfn = Max;
			break;
		case '3':
			pfn = Mean;
			break;
		case '4':
			pfn = Sum;
			break;
		case '5':
			pfn = Std;
			break;
		default:
			pfn = 0L;
			cout << "Menu: 1-min, 2-max, 3-mean, 4-sum, 5-std,E/e-Exit" << endl;
			break;			
		}

		if (0L != pfn)
		{
			cout << "Result is : " << (*pfn)(a, ncount) << endl;
		}

	}while(ch!='E' && ch!='e');

	return 0;
}