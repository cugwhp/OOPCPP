#pragma once
#include <iostream>
#include <list>
using namespace std;

class Shape;

class ShapeSet
{
	friend ostream& operator<<(ostream& os, const ShapeSet& shpset);
	friend istream& operator>>(istream& is, ShapeSet& shpset);
public:
	ShapeSet();
	~ShapeSet();

	void Append();
	void Del(int x, int y);
	void Del(int x, int y, int w, int h);
	void Modify();

	void Draw();

protected:
	void Search(int x, int y);
	void Search(int x, int y, int w, int h);
private:
	list<Shape*>	m_lstShape;
};

ostream& operator<<(ostream& os, const ShapeSet& shpset);
istream& operator>>(istream& is, ShapeSet& shpset);