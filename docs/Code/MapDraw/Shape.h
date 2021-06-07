#pragma once
#include <iostream>
using namespace std;

class Shape
{
	friend ostream& operator<<(ostream& os, const Shape& shp);
	friend istream& operator>>(istream& is, Shape& shp);
public:
	Shape() = default;
	virtual ~Shape()=default;

	virtual void Draw() = 0;
	virtual void Move(int dx, int dy) = 0;

protected:
	virtual bool write(ostream& os) const = 0;
	virtual bool read(istream& is) = 0;
};

ostream& operator<<(ostream& os, const Shape& shp);
istream& operator>>(istream& is, Shape& shp);

