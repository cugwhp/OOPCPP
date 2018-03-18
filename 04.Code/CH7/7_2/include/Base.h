#ifndef BASE_H
#define BASE_H

#include <iostream>
using namespace std;

class Base
{
public:
    Base(int i=0);
    explicit Base(istream& is);
    Base(const Base& b);
    virtual ~Base();

    virtual void Print();

protected:
    int     m;

private:
};

#endif // BASE_H
