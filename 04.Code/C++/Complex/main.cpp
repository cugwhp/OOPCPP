#include "Complex.h"

void IncrementFunc(int&, int&);

int main(int argc, char* argv[])
{
	IncrementFunc(10, 8);

	CComplex c1(2., 4.);
	CComplex c2(1., 3.);
	CComplex c = c1.Add(c2);	
	c = c1 + c2;	//c1.+(c2);

	c.Display(cout);	//cout << c;

	std::cout << c;	//c.<<(cout);
}

void IncrementFunc(int& a, int& b)
{
	a++ = b;
	++a = b;
}
