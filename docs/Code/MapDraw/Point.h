#pragma once
#include "Shape.h"

class Point : public Shape
{
public:
	Point();
	~Point() = default;

	void Draw() override;
	void Move(int dx, int dy) override;

protected:
	bool write(ostream& os) const override;
	bool read(istream& is) override;
};

