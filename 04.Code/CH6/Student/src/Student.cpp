#include "Student.h"
#include <stdexcept>
#include <iostream>
using std::logic_error;
using std::cerr;
using std::endl;

Student::Student(const string& strName) : m_strName(strName), m_aryAttendance{0,0,0}
{
    //ctor
}

Student::~Student()
{
    //dtor
}

string Student::getName() const
{
    return m_strName;
}

unsigned int
Student::getAttendanceCount(eAttendState eAs) const
{
    switch(eAs)
    {
    case AS_Attendance:
        return m_aryAttendance[0];
        break;
    case AS_Late:
        return m_aryAttendance[1];
        break;
    case AS_Absence:
        return m_aryAttendance[2];
        break;
    default:
        return 0;
        break;
    }
}

float
Student::getAttendanceRate() const
{
    unsigned int nTotal = m_aryAttendance[0]+m_aryAttendance[1]+m_aryAttendance[2];
    if (nTotal < 1)
        throw(logic_error("The total of attendance is zero."));
    return float(m_aryAttendance[0])/nTotal;
}

void
Student::addOneRecord(eAttendState eAs)
{
    switch(eAs)
    {
    case AS_Attendance:
        m_aryAttendance[0]++;
        break;
    case AS_Late:
        m_aryAttendance[1]++;
        break;
    case AS_Absence:
        m_aryAttendance[2]++;
        break;
    default:
        return;
        break;
    }
}
