/******************************************************************************
 * Description：复数类，用于复数的简单运算                                  *
 * File：complex.h                                                            *
 * Author: Wang hongping 2016.11.14                                           *
 ******************************************************************************/

#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <iostream>
using namespace std;

/// 复数
class complex
{
public:
    complex(float r=0.0f, float i=0.0f);    ///构造函数
    complex(const complex& c);              ///复制构造函数
public:
    complex operator+(const complex& c);    ///运算符重载
    complex operator-(const complex& c);
    complex operator*(const complex& c);
    complex operator/(const complex& c);

    friend ostream& operator<<(ostream& os, const complex& c);    ///重载输出操作符
    friend istream& operator>>(istream& is, const complex& c);

private:
    float   m_fr;   ///实部
    float   m_fi;   ///虚部
};


#endif // COMPLEX_H_INCLUDED
