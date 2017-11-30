#include <iostream>
#include "e4-9  03.h"
using namespace std;

//你定义的Point::i是静态变量，要初始化一次，初始化的方法是：
int point::i = 0;


point::point(int xx, int yy)
{
	a = xx;
	b = yy;
	i = 0;
	i++;
}


point::point(point &p)
{
	a = p.a;
	b = p.b;
}

void point::print(int a, int b)
{
	cout << "(" << a << "," << b << ")";
}

rectangle::rectangle(point mright, point mleft)
{
	a = mright;
	b = mleft;
}


int rectangle::getarea()
{
	int width=a.geta()-a.getb();
	int height=b.geta()-b.getb();
	int s=width*height;

	return s;
}
