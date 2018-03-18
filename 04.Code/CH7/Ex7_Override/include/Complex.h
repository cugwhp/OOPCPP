#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;


class Complex
{
public:
    Complex(double dR=0.0f, double dI=0.0f);
    virtual ~Complex();

    //Get
    double Radius() const;
    double Angle() const;

    Complex& operator++();
    const Complex operator++(int);
    Complex& operator--();
    const Complex operator--(int);

    //+-*/
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator+=(Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator-=(Complex& c1, const Complex& c2);
    friend Complex operator*(const Complex& c1, const Complex& c2);
    friend Complex operator*=(Complex& c1, const Complex& c2);
    friend Complex operator/(const Complex& c1, const Complex& c2);
    friend Complex operator/=(Complex& c1, const Complex& c2);

    //==,!=,<,>
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend bool operator!=(const Complex& c1, const Complex& c2);
    friend bool operator<(const Complex& c1, const Complex& c2);
    friend bool operator>(const Complex& c1, const Complex& c2);

    // <<, >>
    friend istream& operator>>(istream& is, Complex& c);
    friend ostream& operator<<(ostream& os, const Complex& c);

protected:
    double  m_dReal;
    double  m_dImage;
private:
};

   //+-*/
Complex operator+(const Complex& c1, const Complex& c2);
Complex operator+=(Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator-=(Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator*=(Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);
Complex operator/=(Complex& c1, const Complex& c2);

//in-out
istream& operator>>(istream& is, Complex& c);
ostream& operator<<(ostream& os, const Complex& c);

// logical
bool operator==(const Complex& c1, const Complex& c2);
bool operator!=(const Complex& c1, const Complex& c2);
bool operator<(const Complex& c1, const Complex& c2);
bool operator>(const Complex& c1, const Complex& c2);

#endif // COMPLEX_H
