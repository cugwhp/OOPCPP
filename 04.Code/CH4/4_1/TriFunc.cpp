#include "TriFunc.h"
#include <iostream>
#include <cmath>

using namespace std;

// 定义一个接近0的小值
const double	EPLISON = 1.0E-10;

// 三角形周长
double GetPerimeter(double a, double b, double c)
{
	double	dPerimeter = 0.0f;

	if (IsValidTriangle(a, b, c))
		dPerimeter = a + b + c;
	
	return dPerimeter;
}

// 三角形面积
double GetArea(double a, double b, double c)
{
	double		dArea = 0.0f;
	double		dS;
	
	if (IsValidTriangle(a, b, c))
	{
		dS = GetPerimeter(a, b, c)/2;
		dArea = sqrt(dS*(dS-a)*(dS-b)*(dS-c));
	}

	return dArea;
}


// 三角形角度
double GetAngle(double a, double b, double c)
{
	double		dAngle = 0.0f;

	return dAngle;
}

// 三角形是否合法
bool IsValidTriangle(double a, double b, double c)
{
	if ((a+b-c)<EPLISON || (a+c-b)<EPLISON || (b+c-a)<EPLISON)
		return false;

	return true;
}