#ifndef BASE_H
#define BASE_H


class Base
{
public:
    Base();
    ~Base();

protected:
    int     m;
private:
};

class B1 : public Base
{
public:
    B1();
};

class B2 : virtual public Base
{
public:
    B2();
};

class C : public B1, public B2
{
public:
    C();
};

#endif // BASE_H
