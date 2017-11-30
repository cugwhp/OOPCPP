#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

const double EPLISON = 1.0e-12;
/*
CTriangle::CTriangle()
{
	cout << "CTriangle()" << endl;
}
*/

CTriangle::CTriangle(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

CTriangle::CTriangle(const CTriangle& t)
{
	a = t.a;
	b = t.b;
	c = t.c;
}

CTriangle::~CTriangle()
{

}

double
CTriangle::GetPerimeter()
{
	double	dPerimeter = 0.0f;

	if (IsValidTriangle(a, b, c))
		dPerimeter = a + b + c;
	
	return dPerimeter;
}

double
CTriangle::GetArea()
{
		double		dArea = 0.0f;
	double		dS;
	
	if (IsValidTriangle(a, b, c))
	{
		dS = GetPerimeter()/2;
		dArea = sqrt(dS*(dS-a)*(dS-b)*(dS-c));
	}

	return dArea;
}

bool
CTriangle::Set(double a0 , double b0, double c0)
{
	if (IsValidTriangle(a0, b0, c0))
	{
		a = a0;
		b = b0;
		c = c0;

		return true;
	}

	return false;
}

bool
CTriangle::IsValidTriangle(double a0, double b0, double c0)
{
	if ((a0+b0-c0)<EPLISON || (a0+c0-b0)<EPLISON || (b0+c0-a0)<EPLISON)
		return false;

	return true;
}

bool
CTriangle::IsValidTriangle()
{
	return IsValidTriangle(a, b, c);
}