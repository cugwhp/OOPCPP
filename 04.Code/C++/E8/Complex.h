#pragma once

class CComplex
{
public:
	CComplex(double dR=0.0, double dI=0.0);
	CComplex(const CComplex& c);
	~CComplex(void);

	void Display();

protected:
	double	m_dReal;
	double	m_dImage;
};
