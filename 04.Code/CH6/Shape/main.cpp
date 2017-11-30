#include <iostream>	//io stream
#include "Point.h"
#include "Line.h"

#include <fstream>	//file stream

#include <sstream>	//string stream
#include <iomanip>

using namespace std;




int main()
{
	CPoint		pt1(10, 20);
	CPoint		pt2(20, 30);

	 CLine		l1(pt1, pt2);

	return 0;
}