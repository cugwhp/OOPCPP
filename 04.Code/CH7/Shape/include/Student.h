#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
public:
    Student();
    virtual ~Student();

    bool operator<(const Student& s) const;

protected:
    int             m_ID;
    string          m_strName;

    static int m_gCount;
};

#endif // STUDENT_H
