// 动态生存期

#include <iostream>
using namespace std;

int		i = 1;	//全局变量，具有静态生存期

void fun();

void Test()
{
	// 静态局部变量，具有全局生存期，局部可见，只有第一次进入函数时被初始化
	static int	a = 2;
	static int	b;
	
	int		c = 10;	//局部变量，具有动态生存期，每次进入函数时被初始化
	
	a += 2;
	i += 32;
	c += 5;

	cout << "Variable is : " << endl;
	cout << "i: " << i << "\t";
	cout << "a: " << a << "\t";
	cout << "b: " << b << "\t";
	cout << "c: " << c << endl;

	b = a;
}

int main()
{
	static int a;	//静态局部变量，全局生存期，局部可见
	int		b = -10;
	int		c = 0;
	
	cout << "---MAIN ---" << endl;
	cout << "i: " << i << "\t";
	cout << "a: " << a << "\t";
	cout << "b: " << b << "\t";
	cout << "c: " << c << endl;

	c += 8;
	Test();	
	cout << "---MAIN ---" << endl;
	cout << "i: " << i << "\t";
	cout << "a: " << a << "\t";
	cout << "b: " << b << "\t";
	cout << "c: " << c << endl;

	i += 10;
	Test();

	return 0;
}