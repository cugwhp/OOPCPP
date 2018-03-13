#ifndef COLLEGESTU_H
#define COLLEGESTU_H

#include "Student.h"

class CollegeStu : public Student
{
    public:
        CollegeStu(string strName="", int nAge=0, unsigned long ulID=0, int nScore=0, string strMajor="");
        virtual ~CollegeStu();

        string GetMajor() const { return m_strMajor; }
        void Print(ostream& os) const;
    protected:

    private:
        string  m_strMajor;
};

#endif // COLLEGESTU_H
