#include "Person.h"

Person::Person(string strName, int nAge) : m_strName(strName), m_nAge(nAge)
{
    cout << "Person constructor..." << endl;
    //ctor
}

Person::~Person()
{
    cout << "Person deconstructor..." << endl;
    //dtor
}

void Person::Print(ostream& os) const
{
    os << "Name:  " << m_strName << endl;
    os << "Age:   " << m_nAge << endl;
}

ostream& operator<<(ostream&os, const Person& onePerson)
{
    onePerson.Print(os);

    return os;
}
