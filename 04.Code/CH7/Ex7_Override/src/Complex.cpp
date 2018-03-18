#include "Complex.h"
#include <cmath>

Complex::Complex(double dR, double dI) : m_dReal(dR), m_dImage(dI)
{
    //ctor
}

Complex::~Complex()
{
    //dtor
}

double Complex::Radius() const
{
    return sqrt(m_dImage*m_dImage + m_dReal*m_dReal);
}

double Complex::Angle() const
{
    return atan2(m_dReal, m_dImage);
}



Complex& Complex::operator++()
{
    m_dReal += 1.0f;
    return *this;
}

const Complex Complex::operator++(int)
{
    Complex c = *this;

    m_dReal += 1.0f;

    return c;
}

Complex& Complex::operator--()
{
    m_dReal -= 1.0f;

    return *this;
}

const Complex Complex::operator--(int)
{
    Complex c = *this;
    m_dReal -= 1.0f;
    return c;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
    return Complex(c1.m_dReal+c2.m_dReal, c1.m_dImage+c2.m_dImage);
}

Complex operator+=(Complex& c1, const Complex& c2)
{
    return (c1 = c1 + c2);
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(c1.m_dReal-c2.m_dReal, c1.m_dImage-c2.m_dImage);
}

Complex operator-=(Complex& c1, const Complex& c2)
{
    return (c1=c1-c2);
}

Complex operator*(const Complex& c1, const Complex& c2)
{
    return Complex(c1.m_dReal*c2.m_dReal-c1.m_dImage*c2.m_dImage,
                   c1.m_dReal*c2.m_dImage+c1.m_dImage*c2.m_dReal);
}

Complex operator*=(Complex& c1, const Complex& c2)
{
    return (c1=c1*c2);
}

Complex operator/(const Complex& c1, const Complex& c2)
{
    double  dR = c2.m_dReal*c2.m_dReal + c2.m_dImage*c2.m_dImage;

    return Complex((c1.m_dReal*c2.m_dReal + c1.m_dImage*c2.m_dImage)/dR,
                   (c2.m_dReal*c1.m_dImage - c2.m_dImage*c1.m_dReal)/dR);
}

Complex operator/=(Complex& c1, const Complex& c2)
{
    return (c1=c1/c2);
}

bool operator==(const Complex& c1, const Complex& c2)
{
    return (c1.Radius()==c1.Radius());
}

bool operator!=(const Complex& c1, const Complex& c2)
{
    return !(c1==c2);
}

bool operator<(const Complex& c1, const Complex& c2)
{
    return (c1.Radius()<c2.Radius());
}

bool operator>(const Complex& c1, const Complex& c2)
{
    return (c1.Radius()>c2.Radius());
}

istream& operator>>(istream& is, Complex& c)
{
    is >> c.m_dReal >> c.m_dImage;

    return is;
}

ostream& operator<<(ostream& os, const Complex& c)
{
    os << c.m_dReal;

    if (c.m_dImage != 0.0f)
    {
        if (c.m_dImage > 0.0f)
            os << "+";

         os << c.m_dImage << "i";
    }

    return os;
}
