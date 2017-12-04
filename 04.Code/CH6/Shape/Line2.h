// Line2.h: interface for the CLine2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE2_H__69A069CD_C055_4048_AB22_FC3774246F08__INCLUDED_)
#define AFX_LINE2_H__69A069CD_C055_4048_AB22_FC3774246F08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point.h"

class CLine2  
{
public:
	CLine2();
	virtual ~CLine2();

protected:
	Point	m_pt1, m_pt2;
	

};

#endif // !defined(AFX_LINE2_H__69A069CD_C055_4048_AB22_FC3774246F08__INCLUDED_)
