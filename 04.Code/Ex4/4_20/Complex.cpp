/*****************************************************************************
 * File：Complex.cpp                                                         *
 * Description：复数类的实现                                                       *
 * Author: Wang hongping 2016.11.14                                          *
 *****************************************************************************/

#include "Complex.h"
#include <cmath>

///构造函数
complex::complex(float r, float i)
{
    m_fr = r;
    m_fi = i;
}

///拷贝构造函数
complex::complex(const complex& c)
{
    m_fr = c.m_fr;
    m_fi = c.m_fi;
}


/**************************************************************************
 *                       运算符重载                                      *
 **************************************************************************/
/// + 重载
complex complex::operator+(const complex& c)
{
    return complex(m_fr+c.m_fr, m_fi+c.m_fi);
}

/// - 重载
complex complex::operator-(const complex& c)
{
    return complex(m_fr-c.m_fr, m_fi-c.m_fi);
}

/// * 重载
complex complex::operator*(const complex& c)
{
    return complex(m_fr*c.m_fr-m_fi*c.m_fi, m_fr*c.m_fi+m_fi*c.m_fr);
}

/// / 重载
complex complex::operator/(const complex& c)
{
    float   t;
    t = c.m_fr*c.m_fr + c.m_fi*c.m_fi; //norm

    return complex((c.m_fr*m_fr + c.m_fi*m_fi)/t, (c.m_fr*m_fi - c.m_fi*m_fr)/t);
}

/// 重载输出操作符
ostream& operator<<(ostream& os, const complex& c)    ///注意参数的定义
{
    os << c.m_fr;

    if (fabs(c.m_fi) > 1e-12)
        os << (c.m_fi>1e-12 ? "+" : "") << c.m_fi << "i";

    return os;
}

/// 重载输出操作符
istream& operator>>(istream& is, const complex& c)
{
    is >> c.m_fr >> c.m_fi;
    return is;
}

