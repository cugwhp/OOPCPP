#ifndef _POINT_H_INCLUDED_
#define _POINT_H_INCLUDED_

// class Point
class Point
{
public:
	Point(int x=0, int y=0);
	Point(const Point& pt);
	~Point();
	
	inline int GetX() { return m_ix; }
	inline int GetY() { return m_iy; }
	void Move(int x, int y);
private:
	int		m_ix;
	int		m_iy;
};

/// class vector point
class VectorPoint{
public:
	VectorPoint(int n=0);
	VectorPoint(const VectorPoint& vecPnt);
	~VectorPoint();

	inline int GetCount() { return m_iCount; }
	
	Point& GetPoint(int index);	//点元素
	const Point& GetPoint(int index) const;	//
	Point& operator[](int index);	//重载点元素
	const Point& operator[](int index) const;
	
private:
	Point*	m_ptrData;
	int		m_iCount;
};

#ifndef NULL
#define NULL 0
#endif
#endif	//_POINT_H_INCLUDED_