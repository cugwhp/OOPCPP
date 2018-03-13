#include "Person.h"

Person::Person(string strName, int nAge) : m_strName(strName), m_nAge(nAge)
{
    //ctor
}

Person::~Person()
{
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
