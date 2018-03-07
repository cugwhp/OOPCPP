#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
    public:
        Person(string strName="", int nAge=0);
        virtual ~Person();

        string  GetName() const {return m_strName; }
        int GetAge() const { return m_nAge; }

        void Print(ostream& os);
    protected:

    private:
        string  m_strName;
        int     m_nAge;
};


#endif // PERSON_H
