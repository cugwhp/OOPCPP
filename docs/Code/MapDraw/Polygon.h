#pragma once
#include "Shape.h"
class Polygon : public Shape
{
public:
	Polygon();
	~Polygon() = default;

	void Draw() override;
	void Move(int dx, int dy) override;

protected:
	bool write(ostream& os) const override;
	bool read(istream& is) override;
};

