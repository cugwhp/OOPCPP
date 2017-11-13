#ifndef CALENDAR_H
#define CALENDAR_H

/////////////////////////////////////////////////////////
// 定义星期
enum eWeekday
{
    SUN, MON, TUE, WED, THU, FRI, SAT, WEEK
};

const int   MAX_MONTH = 12;     //最大月份
const eWeekday WD_ERA = SAT;    //公元元年星期一


/*          输出日历
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
void PrintCalendar(int nYear, int nMonth);


// 获取某年某月的天数
int GetMonthDays(int nYear, int nMonth);

// 判断某年是否为闰年
inline bool IsLeapYear(int nYear)
{
    return ((nYear%400==0) || (nYear%4==0 && nYear%100!=0));
}

// 获取某天是星期几
eWeekday GetWeekday(int nYear, int nMonth, int nDay=1);


//

#endif // CALENDAR_H
