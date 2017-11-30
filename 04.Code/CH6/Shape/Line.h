// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__2AB0CFC7_4D94_4175_AA0A_1ADFA7DE7CA6__INCLUDED_)
#define AFX_LINE_H__2AB0CFC7_4D94_4175_AA0A_1ADFA7DE7CA6__INCLUDED_

#include "Point.h"

class CLine  
{
public:
	CLine();
	CLine(const CPoint& pt1, const CPoint& pt2);
	CLine(const CLine& line);
	virtual ~CLine();

	double Distance();

protected:
	CPoint		m_pt1, m_pt2;
};

#endif // !defined(AFX_LINE_H__2AB0CFC7_4D94_4175_AA0A_1ADFA7DE7CA6__INCLUDED_)
