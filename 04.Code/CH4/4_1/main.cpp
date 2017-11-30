#include <iostream>
using namespace std;
#include "TriFunc.h"
#include "Triangle.h"

int main()
{
	double	a;
	double	b;
	double	c;
	
	CTriangle	oTriangle;
	CTriangle	t1(3.,4.,5.);
	CTriangle	t2;
	CTriangle	t3(t1);

	t2 = t1;


	cout << "Input 3 length of triangle : " << endl;
	cin >> a >> b >> c;

	cout << "Perimeter is : " << GetPerimeter(a, b, c) << endl;

	cout << "Area is : " << GetArea(a, b, c) << endl;

	oTriangle.Set(a, b, c);
	cout << "Perimeter is : " << oTriangle.GetPerimeter() << endl;
	cout << "Area is : " << oTriangle.GetArea() << endl;

	CShape*		pShape = NULL;
	pShape = new CTriangle();


	return 0;
}