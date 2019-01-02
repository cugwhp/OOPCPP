#include <iostream>
#include "Circle.h"
#include "Pool.h"

using namespace std;

const float FencePrice = 35;		//围栏单价
const float ConcretePrice = 20;		//过道单价

// 主函数
int main()
{
    Circle  c(2.0f);
    Circle  c2(c);

    c2 = c;

    cout << c.Perimeter() << "\t" << c.Area() << endl;
    cout << c2.Perimeter() << "\t" << c2.Area() << endl;
    return 0;

	float		radius;			//半径
	float		FenceCost;	//围栏造价
	float		ConcreteCost;	//过道造价

	// 输入泳池半径
	cout << "Input pool radius : " << endl;
	cin >> radius;

	Circle		oPool(radius);		//游泳池对象
	Circle		oPoolRim(radius+3.0);	//泳池外围对象

	FenceCost = FencePrice * oPool.Perimeter();	//周长*单价
	cout << "Fence Cost is : ￥" << FenceCost << endl;

	// 面积 * 单价
	ConcreteCost = ConcretePrice * (oPoolRim.Area() - oPool.Area());
	cout << "Concrete Cost is : ￥" << ConcreteCost << endl;

	return 0;
}
