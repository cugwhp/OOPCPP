// Point.h: interface for the CPoint class.
//
//////////////////////////////////////////////////////////////////////


#if !defined(AFX_POINT_H__9E93957A_E469_4837_A262_41F16A4DB6FA__INCLUDED_)
#define AFX_POINT_H__9E93957A_E469_4837_A262_41F16A4DB6FA__INCLUDED_

//static int 
class CPoint  
{
public:
	CPoint(int x=0, int y=0);
	CPoint(const CPoint& pt);
	virtual ~CPoint();

	inline int GetX() { return m_x;}
	inline int GetY() { return m_y;}

	static int GetCount() {return m_nPointCount;}

protected:
	int		m_x;
	int		m_y;

	static int	m_nPointCount;	//æ≤Ã¨±‰¡ø
};

#endif // !defined(AFX_POINT_H__9E93957A_E469_4837_A262_41F16A4DB6FA__INCLUDED_)
