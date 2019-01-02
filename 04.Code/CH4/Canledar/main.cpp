#include <iostream>
#include "Canledar.h"

using namespace std;

int main()
{
	// print canledar
	// Input, output
	int		nYear, nMonth;
	cin >> nYear >> nMonth;

	Calendar	cal(nYear, nMonth);
	cal.PrintCalendar();

	return 0;
}