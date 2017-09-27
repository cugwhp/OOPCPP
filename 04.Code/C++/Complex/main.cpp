#include "Complex.h"

int main()
{
	int		a = 10, b = 8;
	a++ = b;
	++a = b;

	CComplex	c1(2., 4.);
	CComplex	c2(1., 3.);
	CComplex	c = c1.Add(c2);	
	c=c1+c2;	//c1.+(c2);

	c.Display(cout);	//cout << c;

	cout << c;	//c.<<(cout);

	return 0;
}