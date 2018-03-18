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

bool Student::operator<(const Student& s)
{
    if (m_ID<s.m_ID)
        return true;

    return false;
}
