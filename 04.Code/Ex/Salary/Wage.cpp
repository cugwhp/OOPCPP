// Wage.cpp: implementation of the CWage class.
//
//////////////////////////////////////////////////////////////////////

#include "Wage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWage::CWage(const char* name) : CEmployee(name)
{
	m_fWage = 250.0;
	m_fHours = 40.0;
}

CWage::~CWage()
{

}


void
CWage::SetWage(float wage)
{
	m_fWage = wage > 0.0 ? wage : 0.0;
}

void
CWage::SetHours(float hours)
{
	m_fHours = hours > 0.0 ? hours : 0.0;
}

float
CWage::ComputePay()
{
	return m_fWage * m_fHours;
}