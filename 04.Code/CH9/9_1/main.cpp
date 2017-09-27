#include <iostream>
#include "MyTemplate.h"
#include "Complex.h"
#include "MyArray.h"
#include "TArray.h"
#include "TStack.h"

using namespace std;

int main()
{
	int		a = -120;
	float	f = -120.;
	double	d = -1200.;

	// 分别调用int、float、double类型的函数
	cout << "Abs(" << a << ") = " << Abs(a) << endl;
	cout << "Abs(" << f << ") = " << Abs(f) << endl;
	cout << "Abs(" << d << ") = " << Abs(d) << endl;

	// 测试复数的函数
	CComplex	c(-1.,-10.);
	cout << "Input a Complex: ";
//	cin >> c;
	cout << "Abs(" << c << ") = " << Abs(c) << endl;


	// 测试数组类
	CMyArray	ary;
	int			i;
	for (i =0; i<15; i++)
	{
		ary.Add(i*i+1.);
	}
	cout << ary << endl;

	CTArray<double>	tAry;
	for (i =0; i<15; i++)
	{
		tAry.Add(i*i);
	}
	cout << tAry << endl;

	CTArray<CComplex> cAry;
	for (i=0; i<15; i++)
	{
		cAry.Add(CComplex(i+1., i*i+1.));
	}
	cout << cAry;

	return 0;

	CTStack<int>	iStack;
	iStack.Push(10);
	cout << iStack;

	return 0;
}