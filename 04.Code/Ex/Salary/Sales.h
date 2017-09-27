// Sales.h: interface for the CSales class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SALES_H__AAEE12CE_B275_44A0_B3B0_4A1C643239DC__INCLUDED_)
#define AFX_SALES_H__AAEE12CE_B275_44A0_B3B0_4A1C643239DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Wage.h"

class CSales : public CWage
{
public:
	CSales(const char* name);
	virtual ~CSales();

	void SetCommission(float comm);
	void SetSale(float sale);
	float ComputePay();

private:
	float		m_fComm;
	float		m_fSale;
};

#endif // !defined(AFX_SALES_H__AAEE12CE_B275_44A0_B3B0_4A1C643239DC__INCLUDED_)
