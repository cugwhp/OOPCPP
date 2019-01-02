#include <iostream>
#include "Calendar.h"

using namespace std;

int main()
{
	// print calendar
	// Input, output
	int		nYear, nMonth;

	cout << "Input Year and Month : ";
	cin >> nYear >> nMonth;
	if (nYear<1918 || nMonth<1 || nMonth>12)
    {
        cerr << nYear << " " << nMonth << "is not validate date." << endl;
    }

	Calendar	cal(nYear, nMonth);
	cal.PrintCalendar();

	return 0;
}
