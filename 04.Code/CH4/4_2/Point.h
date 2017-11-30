#ifndef _POINT_H_INCLUDED_
#define _POINT_H_INCLUDED_

// Class CPoint
class CPoint
{
public:
	// Constructor
	CPoint(int nX=0, int nY=0);
	CPoint(const CPoint& pt);
	~CPoint();
	
	// Get/Set Methods
	inline int GetX() const { return m_nX;}
	inline int GetY() const { return m_nY;}
	static int GetCount();

	friend CPoint operator+(const CPoint& p1, const CPoint& p2);
	friend CPoint operator- (const CPoint& p1, const CPoint& p2);
	friend CPoint operator* (const CPoint& p1, const CPoint& p2);
//	friend CPoint operator++ (CPoint& pt);
//	friend CPoint operator(CPoint& pt)++;

private:
	int		m_nX;
	int		m_nY;
	static int	m_nCount;
};
#endif	//







































