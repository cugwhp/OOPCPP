#include "Base.h"

Base::Base()
{
    //ctor
}

Base::~Base()
{
    //dtor
}

B1::B1() : Base()
{

}

B2::B2() : Base()
{

}

C::C() : B1(), B2()
{

}
