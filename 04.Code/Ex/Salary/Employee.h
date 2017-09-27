// Employee.h: interface for the CEmployee class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEE_H__86FAEA0A_B485_4B5D_91E4_EF96A225AF8B__INCLUDED_)
#define AFX_EMPLOYEE_H__86FAEA0A_B485_4B5D_91E4_EF96A225AF8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using namespace std;

class CEmployee  
{
public:
	CEmployee(const char* name);
	virtual ~CEmployee();

	float ComputePay();

private:
	string		m_strName;
};

#endif // !defined(AFX_EMPLOYEE_H__86FAEA0A_B485_4B5D_91E4_EF96A225AF8B__INCLUDED_)
