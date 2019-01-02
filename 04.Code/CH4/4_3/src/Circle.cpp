#include "Circle.h"
#include <iostream>
using namespace std;

const float PI = 3.1415926;

Circle::Circle(float r)
{
	radius = r;
	m_pAry = new int[10];
	cout << this << "::Circle(float)" << endl;
}

Circle::Circle(const Circle& c)
{
    this->radius = c.radius;
    this->m_pAry = new int[10];
    for (int i=0; i<10; ++i)
        this->m_pAry[i] = c.m_pAry[i];

    cout << this << "::Circle(const Circle&)" << endl;
}

Circle::~Circle()
{
    if (this->m_pAry) delete[] this->m_pAry;

    cout << this << "::~Circle()" << endl;
}

float
Circle::Perimeter() const
{
	return 2 * PI * radius;
}

float
Circle::Area() const
{
	return PI * radius * radius;
}
