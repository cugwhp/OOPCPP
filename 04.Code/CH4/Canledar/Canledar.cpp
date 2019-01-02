#include "Canledar.h"
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
	// 1900-1-1 Sun;
	const eWeekday	cWeekday1900 = Sun;
	int		nDays = 0;
	int		i;

	// 1900 --> nYear-1
	for (i=1900; i<nYear; ++i)
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

	return eWeekday((nDays + cWeekday1900)%7);
}

int
Calendar::getMonthDays(int year, int month)
{
	static int cnDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		return cnDays[month-1] + 1;

	return cnDays[month-1];
}

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
	cout << "_______________________________" << endl;
	cout << "| Sun Mon Tue Wed Thr Fri Sat |" << endl;
	
	cout << "| ";
	for (i=Sun; i<weekday; ++i)
	{
		cout << "    ";
	}


	for (i=0; i<nMonthDays; ++i)
	{
		if ((weekday+i)%7 == Sun)
		{
			cout << "| ";
		}

		
		cout << setw(2) << (i+1) << "  ";

		if ((weekday+i)%7 == Sat)
		{
			cout << "|" << endl;
		}
	}

	if ((weekday+i)%7 != Sat)
	{
		do
		{
			cout << "    ";
			i++;
		}while((weekday+i)%7 != Sat);
		cout << "|" << endl;
	}
	

	cout << "_______________________________" << endl;
}
