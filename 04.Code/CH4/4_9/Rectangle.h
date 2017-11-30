#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Point.h"
#include <cmath>

/// class Rectangle
class Rectangle
{
public:
    /// 构造函数
    Rectangle(int xmin=0, int xmax=0, int ymin=0, int ymax=0);
    Rectangle(const Point& ptLu, const Point& ptRb);
    Rectangle(const Rectangle& rect);

    /// 面积、周长、高度、宽度
    inline int Width() { return abs(m_ptRightBottom.GetX()-m_ptLeftUp.GetX()); }
    inline int Height() { return abs(m_ptRightBottom.GetY()-m_ptLeftUp.GetY()); }
    inline int Area() { return Width() * Height(); }
    inline int Perimeter() { return 2*(Width()+Height()); }

private:
    Point   m_ptLeftUp;         /// 左上角坐标(xmin, ymin)
    Point   m_ptRightBottom;    /// 右下角坐标(xmax, ymax)
};

#endif // RECTANGLE_H_INCLUDED
