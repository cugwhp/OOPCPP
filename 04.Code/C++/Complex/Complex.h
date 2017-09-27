#pragma once

#include <iostream>
using namespace std;

class CComplex
{
public:
	CComplex(double dR=0.0f, double dI=0.0f);
	CComplex(const CComplex& c);
	~CComplex(void);

public:
	CComplex Add(const CComplex& c);
	void Display(ostream& os);

	//‘ÀÀ„∑˚÷ÿ‘ÿ
	CComplex operator+(const CComplex& c);
	friend CComplex operator+(const CComplex& c1, const CComplex& c2);
	
	friend ostream& operator<<(ostream& os, const CComplex& c);
	ostream& operator<<(ostream& os);

protected:
	double	m_dReal;
	double	m_dImage;
};

CComplex operator+(const CComplex& c1, const CComplex& c2);
ostream& operator<<(ostream& os, const CComplex& c);
