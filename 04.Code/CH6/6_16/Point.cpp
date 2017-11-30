#include "Point.h"

//////////////////////////////////////////////////////////////
/// class Point				  						  //
/////////////////////////////////////////////////////////////
Point::Point(int x, int y) : m_ix(x), m_iy(y)
{
	
}

Point::Point(const Point& pt) : m_ix(pt.m_ix), m_iy(pt.m_iy)
{
}

Point::~Point()
{
}
	
void
Point::Move(int x, int y)
{
	m_ix += x;
	m_iy += y;
}

///////////////////////////////////////////////////////////////
//				 class vector point					//
//////////////////////////////////////////////////////////////
VectorPoint::VectorPoint(int n)
{
	m_ptrData = new Point[n];
	m_iCount = n;
}

/// 拷贝构造函数
VectorPoint::VectorPoint(const VectorPoint& vecPnt)
{
	m_iCount = vecPnt.m_iCount;
	m_ptrData = new Point[m_iCount];
	if (m_ptrData != NULL)
	{
		for (int i=0; i<m_iCount; ++i)
			(*this)[i] = vecPnt[i];
	}
}

/// 析构函数
VectorPoint::~VectorPoint()
{
	if (m_ptrData != NULL)
	{
		delete[] m_ptrData;
		m_ptrData = NULL;
	}
}

Point& VectorPoint::GetPoint(int index)
{
	try
	{
		if (index<0 || index>=m_iCount)
			throw;
	}
	catch(...)
	{
	}

	return m_ptrData[index];
}

const Point& VectorPoint::GetPoint(int index) const
{
	return m_ptrData[index];
}

Point& VectorPoint::operator[](int index)
{
	return m_ptrData[index];
}

const Point& VectorPoint::operator[](int index) const
{
	return m_ptrData[index];
}