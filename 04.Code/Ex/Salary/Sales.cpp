// Sales.cpp: implementation of the CSales class.
//
//////////////////////////////////////////////////////////////////////

#include "Sales.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSales::CSales(const char* name) : CWage(name)
{
	m_fComm = 0.0;
	m_fSale = 0.0;
}

CSales::~CSales()
{

}

void
CSales::SetCommission(float comm)
{
	m_fComm = comm > 0.0 ? comm : 0.0;
}

void
CSales::SetSale(float sale)
{
	m_fSale = sale > 0.0 ? sale : 0.0;
}

float
CSales::ComputePay()
{
//	return 0.0f;
	return m_fComm*m_fSale + CWage::ComputePay();//m_fWage*m_fHours;
}