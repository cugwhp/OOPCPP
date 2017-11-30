#ifndef _TRIANGLE_H_INCLUDED_
#define _TRIANGLE_H_INCLUDED_

class CShape
{
public:
	double	GetArea();
};

class CCircle : public CShape
{
public:
	double GetArea();
};

class CRectangle : public CShape
{
public:
	double	GetArea();
};

class CTriangle : public CShape
{
public:
	CTriangle(double a=0., double b=0., double c=0.);
	CTriangle(const CTriangle& t);
	~CTriangle();
public:
	bool Set(double a0, double b0, double c0);
	double	GetPerimeter();
	double	GetArea();

protected:
	bool IsValidTriangle(double a0, double b0, double c0);
	virtual bool IsValidTriangle();

private:
	double	a, b, c;
};

#endif
//