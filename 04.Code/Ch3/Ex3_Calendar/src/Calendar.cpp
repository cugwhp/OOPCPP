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

// 输出日历
void PrintCalendar(int nYear, int nMonth)
{
    cout << "        " << setw(4) << nYear << "-" << setw(2) << nMonth << " Calendar " << endl;
    cout << "|-----------------------------|" << endl;
    cout << "| Sun Mon Tue Wed Thu Fri Sat |" << endl;

    int         nMonthDays;
    int         weekday;
    eWeekday    weekdayMonthHead;

    // 月首行的开头
    weekdayMonthHead = GetWeekday(nYear, nMonth, 1);
    if (weekdayMonthHead != SUN)
        cout << "| ";
    for (weekday=SUN; weekday<weekdayMonthHead; weekday++)
    {
        cout << "    ";
    }

    // 月内的日期
    weekday = weekdayMonthHead;
    nMonthDays = GetMonthDays(nYear, nMonth);
    for (int i=0; i<nMonthDays; i++)
    {
         // 一行的开头
        if (weekday == SUN)
           cout << "| ";

        // 输出日期
        cout << setw(2) << (i+1) << "  ";

        // 一行的结束
        if (weekday == SAT)
            cout << "|" << endl;

        weekday++;
        weekday %= WEEK;
    }

    // 月尾行的结尾
    if (weekday != SUN) //如果一个月的最后一天不是SAT，则补齐空格
    {
        for(; weekday<WEEK; ++weekday)
            cout << "    ";
         cout << "|" << endl;
    }

    // 结束边框
    cout << "|-----------------------------|" << endl;
}

///////////////////////////////////////////////////////////
//                  获取某年某月的天数                   //
///////////////////////////////////////////////////////////
int GetMonthDays(int nYear, int nMonth)
{
    switch(nMonth)
    {
        // 大月，31天
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 32;

        // 2月，考虑闰年
        case 2:
            return (IsLeapYear(nYear) ? 29 : 28);

        // 小月，30天
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        default:
            return 0;
    }
}

// 获取某天是星期几
eWeekday GetWeekday(int nYear, int nMonth, int nDay)
{
    // 公元1年1月1日，星期一
    int     nDayCounts = 0;

    // 计算从公元1年到nYear-1年的天数，余7
    nDayCounts = (nYear-1)%WEEK;//365*(nYear-1) % 7 = (52*7+1)*(nYear-1) %7 = (nYear-1)%7;

    // 计算从公元1年到nYear-1年的闰年天数
    for (int i=1; i<nYear; i++)
    {
        if (IsLeapYear(nYear))
            nDayCounts++;
    }

    // 计算nYear年，从1月到nMonth-1月的天数，余7
    for (int i=1; i<nMonth; ++i)
    {
        nDayCounts += GetMonthDays(nYear, i) % WEEK;
    }

    // 计算nYear年nMonth月1日到当前日期的天数
    nDayCounts += nDay-1;

    nDayCounts += WD_ERA;   //公元元年
    nDayCounts %= WEEK;

    return (eWeekday)nDayCounts;
}
