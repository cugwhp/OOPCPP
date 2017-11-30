#include "StdAfx.h"
#include "Complex.h"

CComplex::CComplex(double dR, double dI)
{
	m_dReal = dR;
	m_dImage = dI;
}

CComplex::CComplex(const CComplex& c)
{
	m_dReal = c.m_dReal;
	m_dImage = c.m_dImage;
}

CComplex::~CComplex(void)
{
}
