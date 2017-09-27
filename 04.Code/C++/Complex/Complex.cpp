#include "Complex.h"

CComplex::CComplex(double dR, double dI) : m_dReal(dR), m_dImage(dI)
{
}

CComplex::CComplex(const CComplex& c) : m_dReal(c.m_dReal), m_dImage(c.m_dImage)
{
}

CComplex::~CComplex(void)
{
}

CComplex CComplex::Add(const CComplex& c)
{
	return CComplex(m_dReal+c.m_dReal,m_dImage+c.m_dImage);
}

CComplex CComplex::operator+(const CComplex& c)
{
	return CComplex(m_dReal+c.m_dReal,m_dImage+c.m_dImage);
}

CComplex operator+(const CComplex& c1, const CComplex& c2)
{
	return CComplex(c1.m_dReal+c2.m_dReal,c1.m_dImage+c2.m_dImage);
}

void CComplex::Display(ostream& os)
{
	os << m_dReal;
	os << (m_dImage>0.0f ? "+" : "");
	os << m_dImage << "i";
}

ostream& CComplex::operator<<(ostream& os)
{
	os << m_dReal;
	os << (m_dImage>0.0f ? "+" : "");
	os << m_dImage << "i";

	return os;
}

ostream& operator<<(ostream& os, const CComplex& c)
{
	os << c.m_dReal;
	os << (c.m_dImage>0.0f ? "+" : "");
	os << c.m_dImage << "i";

	return os;
}




