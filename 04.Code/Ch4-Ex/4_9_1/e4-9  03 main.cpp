// e4-9  03.cpp : 定义控制台应用程序的入口点。
//

#include"e4-9  03.h"	//文件路径最好不要都空格。。。
#include<iostream>
using namespace std;

//extern int i;	//extern int i是说明i是一个全局变量，而i是吗？？？

int main()
{


	point r(20, 10);
	point l(50, 10);

	r.print(20,10);
	l.print(50,10);

	rectangle area(r, l);

	cout << "s=" << area.getarea()<<"   ";
//	cout << point::i;	//i能这么访问吗？？应该是Point::i,若i是private变量，最好用static函数访问
    return 0;
}

