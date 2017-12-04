// PolyLine.h: interface for the CPolyLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYLINE_H__0F903BEC_FA7F_40DC_9C22_A1573F93E1EF__INCLUDED_)
#define AFX_POLYLINE_H__0F903BEC_FA7F_40DC_9C22_A1573F93E1EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point.h"

class CPolyLine  
{
public:
	CPolyLine();
	CPolyLine(CPoint pts[], int nPtCount);
	CPolyLine(const CPolyLine& pl);
	virtual ~CPolyLine();

	double GetLineLen();

protected:
	CPoint*	m_pPts;
	int		m_nPtCounts;

};

#endif // !defined(AFX_POLYLINE_H__0F903BEC_FA7F_40DC_9C22_A1573F93E1EF__INCLUDED_)
