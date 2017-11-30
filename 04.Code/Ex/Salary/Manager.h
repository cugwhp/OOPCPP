// Manager.h: interface for the CManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGER_H__BB3E6612_BA12_4BFD_9CFA_EC16B1E54F1B__INCLUDED_)
#define AFX_MANAGER_H__BB3E6612_BA12_4BFD_9CFA_EC16B1E54F1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Employee.h"

class CManager : public CEmployee
{
public:
	CManager(const char* name);
	virtual ~CManager();

	void SetSalary(float salary);
	float ComputePay();

private:
	float	m_fSalary;
};

#endif // !defined(AFX_MANAGER_H__BB3E6612_BA12_4BFD_9CFA_EC16B1E54F1B__INCLUDED_)
