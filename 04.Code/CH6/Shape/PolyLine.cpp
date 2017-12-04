// PolyLine.cpp: implementation of the CPolyLine class.
//
//////////////////////////////////////////////////////////////////////

#include "PolyLine.h"
#include <cmath>

#define NULL 0L

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPolyLine::CPolyLine() : m_pPts(NULL), m_nPtCounts(0)
{
}

CPolyLine::CPolyLine(CPoint pts[], int nPtCount)
{
	if (pts == NULL || nPtCount<2)
	{
		m_pPts = NULL;
		m_nPtCounts = 0;
	}
	else
	{
		m_pPts = new CPoint[nPtCount];
		for (int i=0; i<nPtCount; i++)
		{
			m_pPts[i] = pts[i];
		}
		m_nPtCounts = nPtCount;
	}
}

CPolyLine::CPolyLine(const CPolyLine& pl)
{
	m_pPts = new CPoint[pl.m_nPtCounts];
	for (int i=0; i<m_nPtCounts; i++)
	{
		m_pPts[i] = pl.m_pPts[i];
	}
	m_nPtCounts = pl.m_nPtCounts;
}


CPolyLine::~CPolyLine()
{
	if (m_pPts != NULL)
	{
		delete[] m_pPts;
		m_pPts = NULL;
	}
	m_nPtCounts = 0L;
}

double CPolyLine::GetLineLen()
{
	int	i;
	double	dLen = 0.0f;
	double	dx, dy;

	for (i=0; i<m_nPtCounts-1; i++)
	{
		dx = m_pPts[i].GetX() - m_pPts[i+1].GetX();
		dy = m_pPts[i].GetY() - m_pPts[i+1].GetY();

		dLen += sqrt(dx*dx + dy*dy);
	}

	return dLen;
}