#include "Calendar.h"
#include <iostream>
#include <iomanip>
using namespace std;

/*
        2017-11 Calendar
|-----------------------------|
| Sun Mon Tue Wed Thu Fri Sat |
|             01  02  03  04  |
| 05  06  07  08  09  10  11  |
| 12  13  14  15  16  17  18  |
| 19  20  21  22  23  24  25  |
| 26  27  26  27  28  29  30  |
|-----------------------------|
*/
void PrintCalendar(int nYear, int nMonth)
{
	cout << "\t\t"<< nYear << "-" << nMonth << endl;
	cout << "|-----------------------------|" << endl;
	cout << "| Sun Mon Tue Wed Thu Fri Sat |" << endl;

	int		nDays = GetMonthDays(nYear, nMonth);
	eWeekday	WeekdayMonthHead = GetWeekday(nYear, nMonth, 1);

	if (WeekdayMonthHead != SUN)
	{
		cout << "| ";
		for (int i=SUN; i<WeekdayMonthHead; ++i)
			cout << "    ";
	}

	for (int i=0; i<nDays; ++i)
	{
		if ((WeekdayMonthHead+i)%7 == SUN)
			cout << "| ";

		cout << setw(2) << (i+1) << "  ";

		if ((WeekdayMonthHead+i)%7 == SAT)
			cout << "|" << endl;
	}

	int i = (WeekdayMonthHead + nDays-1)%7;
	if (i != SAT)
	{
		while(i++<6)
			cout << "    ";
		cout << "|" << endl;
	}

	cout << "|-----------------------------|" << endl;
}

eWeekday GetWeekday(int nYear, int nMonth, int nDay)
{
	//1-1-1 SUN
	//1-1-1 ~ nYear-1-1 365*(nYear-1)+...;
	//nYear-1~nYear-Month
	
	return SUN;
}

int GetMonthDays(int nYear, int nMonth)
{
	switch(nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		return IsLeapYear(nYear) ? 29 : 28;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	}
}