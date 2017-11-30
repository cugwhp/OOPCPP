#include <iostream>
#include "Calendar.h"

using namespace std;


int main()
{
	int		nYear, nMonth;

	cout << "Input Year and Month: ";
	cin >> nYear >> nMonth;

	PrintCalendar(nYear, nMonth);

	return 0;
}