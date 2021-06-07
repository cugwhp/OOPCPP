#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
	Line();
	~Line();

	void Draw() override;
	void Move(int dx, int dy) override;

protected:
	bool write(ostream& os) const override;
	bool read(istream& is) override;
};

