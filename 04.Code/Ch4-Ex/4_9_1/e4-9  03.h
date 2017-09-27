#pragma once	//这个宏定义的意思就是只包含一次，与#ifnde ... #define ... #endif 等价
#ifndef E4_9_H_INCLUDE
#define E4_9_H_INCLUDE

class point
{
public:

	point(int xx = 0, int yy = 0);

	// 修改为 point(const point& p);
	point(point &p);

	int geta()
	{
		return a;
	}

	int getb()
	{
		return b;
	}

	// int a, int b 是什么意思？类的成员函数，可以直接访问类的成员变量
	void print(int a, int b);

private:
	// 变量的名称要有实际的意义，a,b,i代表什么意思？？
	int a, b;
	static int i;
};


class rectangle
{
public:
	rectangle(point mright,point mleft);	//传值和传引用有什么区别？？此处用const point& 比较好
	~rectangle() {}

	int getarea();


private:
	point a,b;	//名字能否取得有意义一点？

};




#endif