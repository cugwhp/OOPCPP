#include "Circle.h"
#include <iostream>
using namespace std;

const float PI = 3.1415926;

Circle::Circle(float r)
{
	radius = r;
}

Circle::~Circle()
{
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