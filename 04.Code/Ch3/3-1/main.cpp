#include <iostream>

using namespace std;

double power(double, int);  //声明

int main()
{
    cout << " 5 to the power 2 is " << power(5, 2) << endl;
    return 0;
}

// 计算x的n次方
double power(double x, int n)
{
	double val = 1.0;
	while(n>0)
	{
		val *= x;
		n--;
	}

	return val;
}
