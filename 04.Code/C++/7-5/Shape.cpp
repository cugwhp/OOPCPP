#include "StdAfx.h"
#include "Shape.h"

CShape::CShape(void)
{
	TRACE0("CShape::CShape()");
}

CShape::~CShape(void)
{
	TRACE0("CShape::~CShape()");
}

void 
CShape::DrawInfo(CDC* pDC)
{
	POINT	pt0 = GetCenter();
	CString	strInfo;

	strInfo.Format(_T("Perimer=%.1f,Area=%.1f"), GetPerimer(), GetArea());

	pDC->TextOut(pt0.x, pt0.y, strInfo);
}
