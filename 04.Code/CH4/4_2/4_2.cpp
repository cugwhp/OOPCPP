#include <iostream>
#include "Line.h"

using namespace std;
// Main()
int main()
{
	CPoint		p1(1, 2);
	CPoint		p2(3, 4);
	CLine		l1(p1, p2);

	cout << sizeof(CPoint)<<endl;
	cout << sizeof(p1) << endl;
	cout << "Len is " << l1.Length() << endl;
	return 0;
}
