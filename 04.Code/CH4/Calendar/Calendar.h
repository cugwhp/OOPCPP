//
#ifndef _CANLEDAR_H_
#define _CANLEDAR_H_

enum eWeekday {Sun, Mon, Tue, Wed, Thr, Fri, Sat};

class Calendar
{
public:
	Calendar(int year, int month);
	~Calendar();

	void PrintCalendar();

protected:
	bool isLeapYear(int year);
	eWeekday getWeekday();
	int getMonthDays(int year, int month);
	int getMonthDays();
	void FormatCalendar(eWeekday weekday, int nMonthDays);

private:
	int		nYear;
	int		nMonth;
};

#endif	//#ifndef _CANLEDAR_H_
