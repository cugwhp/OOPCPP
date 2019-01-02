#include "Calendar.h"
#include <iostream>
#include <iomanip>
using namespace std;

Calendar::Calendar(int year, int month)
{
	nYear = year;
	nMonth = month;
}

Calendar::~Calendar()
{
}

void
Calendar::PrintCalendar()
{
	//1.
	eWeekday	weekday;
	weekday = getWeekday();

	//2.
	int			nMonthDays;
	nMonthDays = getMonthDays();

	//3.
	FormatCalendar(weekday, nMonthDays);

	return;
}

bool
Calendar::isLeapYear(int year)
{
	return ((year%4==0 && year%100!=0) || year%400==0);
}

eWeekday
Calendar::getWeekday()
{
	// 1918-1-1 Tue;
	const eWeekday	cWeekday1918 = Tue;
	int		nDays = 0;
	int		i;

	// 1918 --> nYear-1
	for (i=1918; i<nYear; ++i)
	{
		if (isLeapYear(i))
			nDays += 366%7;
		else
			nDays += 365%7;
	}

	for (i=1; i<nMonth; ++i)
	{
		nDays += getMonthDays(nYear, i)%7;
	}

	return eWeekday((nDays + cWeekday1918)%7);
}

/*
 * getMonthDays : get the number of day in one month
 * parameters   :
 *      int year - >0 year
 *      int month - 1--12 month
 * return       : int - days in month.year
 */
int
Calendar::getMonthDays(int year, int month)
{
	static int cnDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		return cnDays[month-1] + 1;

	return cnDays[month-1];
}

/*
 * Override getMonthDays in nYear, nMonth
*/
int
Calendar::getMonthDays()
{
	return getMonthDays(nYear, nMonth);
}

void
Calendar::FormatCalendar(eWeekday weekday, int nMonthDays)
{
	int		i;

	//1. Print Header
	cout << " ----------------------------- " << endl;
	cout << "| Sun Mon Tue Wed Thr Fri Sat |" << endl;
	cout << "|-----------------------------|" << endl;

	// Fill bland from Sunday to start weekday of month
	cout << "| ";
	for (i=Sun; i<weekday; ++i)
	{
		cout << "    ";
	}

    // Loop print calendar from 1st month to end month
	for (i=0; i<nMonthDays; ++i)
	{
	    // print the begin of one week
		if ((weekday+i)%7 == Sun)
		{
			cout << "| ";
		}

		// print one day
		cout << setw(2) << (i+1) << "  ";

		// print the end of one week
		if ((weekday+i)%7 == Sat)
		{
			cout << "|" << endl;
		}
	}

	// End of Month day is not Saturday, align to line
	if ((weekday+nMonthDays-1)%7 != Sat)
    {
        for (i = (weekday+nMonthDays-1)%7; i<Sat; ++i)
        {
            cout << "    ";
        }

        cout << "|" << endl;
	}

	// Print the bottom of Calendar
	cout << " ----------------------------- " << endl;
}
