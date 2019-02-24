#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

/// class point
class Point
{
public: /// constructor / destructor
    Point(int x=0, int y=0);
    Point(const Point& pt);

    inline int GetX(){ return m_x; }
    inline int GetY() { return m_y; }

	static int GetCount();

private:
    int     m_x;    /// x position
    int     m_y;    /// y position
	static int m_nCount;
};


#endif // POINT_H_INCLUDED