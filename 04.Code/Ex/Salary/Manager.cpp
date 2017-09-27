// Manager.cpp: implementation of the CManager class.
//
//////////////////////////////////////////////////////////////////////

#include "Manager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CManager::CManager(const char* name) : CEmployee(name)
{
	m_fSalary = 15000.0;
}

CManager::~CManager()
{

}

void
CManager::SetSalary(float salary)
{
	m_fSalary = salary > 0.0 ? salary : 0.0;
}

float
CManager::ComputePay()
{
	return m_fSalary;
}
