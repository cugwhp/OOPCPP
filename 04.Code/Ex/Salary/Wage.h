// Wage.h: interface for the CWage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WAGE_H__61FF6BF3_CDCC_4725_A7A5_2A2D06E162BA__INCLUDED_)
#define AFX_WAGE_H__61FF6BF3_CDCC_4725_A7A5_2A2D06E162BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Employee.h"

class CWage : public CEmployee
{
public:
	CWage(const char* name);
	virtual ~CWage();

	void SetWage(float wage);
	void SetHours(float hours);
	float ComputePay();
private:
	float		m_fWage;
	float		m_fHours;
};

#endif // !defined(AFX_WAGE_H__61FF6BF3_CDCC_4725_A7A5_2A2D06E162BA__INCLUDED_)
