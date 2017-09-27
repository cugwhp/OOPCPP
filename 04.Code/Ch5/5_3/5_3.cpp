// main
#include <iostream>
#include "Clock.h"
using namespace std;

Clock	gClock;	//全局对象，具有静态生存期，命名空间作用域

int main()
{
	gClock.showTime();

	gClock.setTime(8, 30, 30);
	
	Clock	myClock(gClock);
	myClock.showTime();

	return 0;
}