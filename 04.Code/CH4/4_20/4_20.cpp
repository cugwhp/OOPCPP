#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
	complex		c1(1., 2.);
	complex		c2(3., 4.);

	complex		c;

	c = c1+c2;
	c = c1 - c2;
	c = c1*c2;
	c = c1/c2;

	cout << c << endl;

    cin >> c;

	return 0;
}
