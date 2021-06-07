#include "Shape.h"

ostream& operator<<(ostream& os, const Shape& shp)
{
	shp.write(os);
	return os;
}

istream& operator>>(istream& is, Shape& shp)
{
	shp.read(is);
	return is;
}

