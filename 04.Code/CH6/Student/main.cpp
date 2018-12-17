#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
    Student s1("Whp");
    Student s2("Wang");

    s1.addOneRecord(AS_Attendance);
    s1.addOneRecord(AS_Late);
    s1.addOneRecord(AS_Absence);

    try
    {
        cout << s1.getAttendanceRate() << endl;
        cout << s2.getAttendanceRate() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
