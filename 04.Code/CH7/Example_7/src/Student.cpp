#include "Student.h"

Student::Student(string strName, int nAge,
                 unsigned long ulID, int nScore) :
    Person(strName, nAge), m_ulID(ulID), m_nScore(nScore)
{
    cout << "Student constructor..." << endl;
    //ctor
}

Student::~Student()
{
    cout << "Student deconstructor..." << endl;
    //dtor
}

void Student::Print(ostream& os) const
{
    Person::Print(os);
//    os << "Name:  " << GetName() << endl;
//    os << "Age:   " << GetAge() << endl;
    os << "ID:    " << m_ulID << endl;
    os << "Score: " << m_nScore << endl;
}
