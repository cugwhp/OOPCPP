#include "Array.h"
#include <iostream>
using namespace std;

int main(void)
{
	int		a[] = {9, 8 ,6, 7, 100, 20, 4, 23, 57, 200};
	int		b[] = {0, 0, 0, 0};

	// 计算一维数组统计值
	StatAry(a, 10, b);

	cout << "Min: " << b[0] << endl;
	cout << "Max: " << b[1] << endl;
	cout << "Mean: " << b[2] << endl;
	cout << "Sum: " << b[3] << endl;

	return 0;

	int Table[3][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};
	int		i;
	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << Table[i][j] << "   ";
		cout << endl;
	}

	RowSum(Table,3);
	
	for (i = 0; i < 3; i++)
     cout << Table[i][0] << "\t";
	 
	 return 0;
}
