#include "CollegeStu.h"

CollegeStu::CollegeStu(string strName, int nAge, unsigned long ulID, int nScore, string strMajor) :
    Student(strName, nAge, ulID, nScore), m_strMajor(strMajor)
{
    //ctor
}

CollegeStu::~CollegeStu()
{
    //dtor
}
