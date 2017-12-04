#include <iostream>	//io stream
#include "Point.h"
#include "Line.h"

#include <fstream>	//file stream

#include <sstream>	//string stream
#include <iomanip>

#include "PolyLine.h"

using namespace std;

int main()
{
	CPoint		pt1(10, 20);
	CPoint		pt2(20, 30);	
	CLine		l1(pt1, pt2);


	CPoint		pts[] = {CPoint(10, 20), CPoint(30, 40), CPoint(30, 50)};
	int			nCount = 3;

	CPolyLine	pl(pts, nCount);
	cout << pl.GetLineLen() << endl;

	CPolyLine	pl2(pl);

	return 0;
}