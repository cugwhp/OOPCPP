/************************************************************************'
 * class Circle
 ************************************************************************/
#ifndef _CIRCLE_H_INCLUDED_
#define _CIRCLE_H_INCLUDED_

//
class Circle
{
public:
	Circle(float r=0.0f);   //Circle() and Circle(float)
	Circle(const Circle& c);
	~Circle();

	float Perimeter() const;
	float Area() const;
protected:
private:
	float		radius;
	int*        m_pAry;
};

#endif
