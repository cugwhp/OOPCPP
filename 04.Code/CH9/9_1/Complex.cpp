#include "Complex.h"

// 构造函数
CComplex::CComplex(double r, double i) : m_dblReal(r), m_dblImage(i)
{
}

// 析构函数
CComplex::~CComplex(void)
{
}

CComplex	//负号重载
CComplex::operator-()
{
	return CComplex(-m_dblReal, -m_dblImage);
}

bool	// < 重载
CComplex::operator<(const CComplex& c)
{
	if (m_dblReal < c.m_dblReal && m_dblImage < c.m_dblImage)
		return true;
	return false;
}


// 输出符重载
ostream& operator<<(ostream& os, const CComplex& c)
{
	os << c.m_dblReal << (c.m_dblImage>0.0 ? "+" : "");
	os << c.m_dblImage << "i";

	return os;
}

// 输入符重载
istream& operator>>(istream& is, CComplex& c)
{
	is >> c.m_dblReal >> c.m_dblImage;
	return is;
}