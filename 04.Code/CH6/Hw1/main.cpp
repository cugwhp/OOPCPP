#include <iostream>

#include "Fun.h"
using namespace std;

int main()
{
	int		a[3][3] = {1,0,0,0,1,0,0,0,1};
	int		b[3] = {1, 2, 3	};
	int		*p1 = 0L;
	int		*p2[3];
	int		(*p3)[3];

	double		d;
	void	*ptr = &d;

	int		i;
	int		*ptr_i = &i;
	int		**pptr = &ptr_i;
	int		***ppptr = &pptr;

	cout << &i << "\t" << i << endl;
	cout << &ptr_i << "\t" << ptr_i << endl;
	cout << &pptr << "\t" << pptr << endl;
	cout << &ppptr << "\t" << ppptr << endl;
	

	Sum(b, 3);
	
	cout << a << endl;
	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;

	return 0;
}
