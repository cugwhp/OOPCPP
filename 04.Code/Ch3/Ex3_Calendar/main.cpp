/****************************************************************************
 *              万年历显示程序                                             *
 * 功能：输入年月日，打印当前月的日历，包括星期和年月日                  *
 ****************************************************************************/
#include <iostream>
#include "Calendar.h"

using namespace std;

void Usage()
{
    //
    cout << "Usage: Input a date with yyyy-mm, print the calender of month." << endl;
    cout << "       Validate Parameter : yyyy (1-2020), mm (1-12)" << endl;
    cout << "       Exit - input year<=0 && mm<=0" << endl;
}

int main()
{
    Usage();

    int     nYear, nMonth;
    do
    {
        // 初始值
        nYear = nMonth = 0;

        // 输入年、月、日
        cout << "Input a date yyyy mm：";
        cin >> nYear >> nMonth;

        // 合法，则打印年日历
        if (nYear>0 && nMonth>0 && nMonth<=MAX_MONTH)
        {
            PrintCalendar(nYear, nMonth);
        }
        else
        {   // 输入不合法，打印要求
            Usage();
        }
    }while(nYear>0 || nMonth>0);   //年月合法继续输入

    return 0;
}
