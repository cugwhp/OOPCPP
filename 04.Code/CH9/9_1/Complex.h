/************************************************************************/
/* 复数类                                                               */
/* 重载运算符、输入输出符												*/
/* Wang Hongping 2017.3.7												*/
/************************************************************************/
#pragma once

#include <iostream>
using namespace std;

class CComplex
{
public:
	// 构造函数、析构函数
	CComplex(double r=0.0f, double i=0.0f);
	~CComplex(void);

	// 运算符重载
	CComplex operator-();	//负号重载
	bool operator<(const CComplex& c);	//小于负号重载

	// 输入、输出符重载
	friend ostream& operator<<(ostream& os, const CComplex& c);
	friend istream& operator>>(istream& is, CComplex& c);

private:
	// 成员变量，实部+虚部i
	double	m_dblReal;
	double	m_dblImage;
};


// 输入、输出符接口定义
ostream& operator<<(ostream& os, const CComplex& c);
istream& operator>>(istream& is, CComplex& c);