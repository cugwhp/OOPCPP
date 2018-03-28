#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
    Student();
    virtual ~Student();

    friend bool operator<(const Student& s1, const Student& s2);
    friend ostream& operator<<(ostream& os, const Student& s);

protected:
    int             m_ID;
    string          m_strName;

    static int m_gCount;
};

bool operator<(const Student& s1, const Student& s2);
ostream& operator<<(ostream& os, const Student& s);

void sort(Student* pBeg, Student* pEnd);

#endif // STUDENT_H
