#ifndef _LINE_H_INCLUDED_
#define _LINE_H_INCLUDED_

#include "Point.h"

//class CPoint;	//Ç°ÏòÉùÃ÷

class CLine
{
public:
	CLine();
	CLine(const CPoint& p1, const CPoint& p2);
	CLine(const CLine& CLine);
	~CLine();
	
public:
	double Length() const;
private:
	CPoint	m_P1;
	CPoint	m_P2;
};

#endif	//_LINE_H_INCLUDED_
