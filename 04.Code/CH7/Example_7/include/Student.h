#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
    public:
        Student(string strName="", int nAge=0, unsigned long ulID=0, int nScore=0);
        virtual ~Student();

        unsigned long   GetID() const { return m_ulID; }
        int GetScore() const { return m_nScore; }

        void Print(ostream& os) const;
    protected:

    private:
        unsigned long   m_ulID;
        int     m_nScore;
};

#endif // STUDENT_H
