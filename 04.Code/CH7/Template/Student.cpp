#include "Student.h"

int Student::m_gCount = 0;

Student::Student()
{
    m_ID = ++m_gCount;
    m_strName = "RS";
    //ctor
}

Student::~Student()
{
    //dtor
}

bool operator<(const Student&s1, const Student& s2)
{
    if (s1.m_ID<s2.m_ID)
        return true;

    return false;
}

ostream& operator<<(ostream& os, const Student& s)
{
    os << "ID: " << s.m_ID << "    Name: " << s.m_strName;

    return os;
}

void sort(Student* pBeg, Student* pEnd)
{
    return;
}
