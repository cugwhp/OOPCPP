#include "Pool.h"

Pool::Pool() : m_oFenceCircle(10), m_oSwimmingCircle(5)
{
    //ctor
}

Pool::~Pool()
{
    //dtor
}

float
Pool::getPrice()
{
    float   fPrice = 0.0f;

    fPrice = m_oFenceCircle.Perimeter()*m_fFencePrice;
    fPrice += (m_oFenceCircle.Area()-m_oSwimmingCircle.Area())*m_fRoadPrice;

    return fPrice;
}
