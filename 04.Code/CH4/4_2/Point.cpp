/*
*/
#include "Point.h"
#include <iostream>

using namespace std;

int CPoint::m_nCount = 0;

// 构造函数
CPoint::CPoint(int nX, int nY)
{
	m_nX = nX;
	m_nY = nY;
	m_nCount++;
	cout << "CPoint::CPoint(int, int) @" << this <<" is called." << endl;
}

// 拷贝构造函数
CPoint::CPoint(const CPoint& pt)
{	
	m_nX = pt.m_nX;
	m_nY = pt.m_nY;
	m_nCount++;

	cout << "CPoint::CPoint(const CPoint&) @" << this << " is called." << endl;
}

// 析构函数
CPoint::~CPoint()
{
	m_nCount--;
	cout << "CPoint::~CPoint() @ " << this << " is called." << endl;
}

int
CPoint:: GetCount()
{
	return m_nCount;
}

CPoint operator+ (const CPoint& p1, const CPoint& p2)
{
	return CPoint(p1.m_nX+p2.m_nX, p1.m_nY+p2.m_nY);
}

CPoint operator- (const CPoint& p1, const CPoint& p2)
{
	return CPoint(p1.m_nX-p2.m_nX, p1.m_nY-p2.m_nY);
}

CPoint operator* (const CPoint& p1, const CPoint& p2)
{
	return CPoint(p1.m_nX*p2.m_nX, p1.m_nY*p2.m_nY);
}

/*
CPoint& operator++ (CPoint& pt)
{
	pt.m_nX++;
	pt.m_nY++;
	return pt;
}

CPoint& operator(CPoint& pt)++
{
	++pt.m_nX;
	++pt.m_nY;
	return pt;
}
*/