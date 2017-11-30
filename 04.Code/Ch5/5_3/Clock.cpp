//clock
#include "Clock.h"
#include <iostream>

using namespace std;

Clock::Clock(int h, int m, int s) : hour(h), min(m), sec(s)
{
}

void
Clock::setTime(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

void
Clock::showTime()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

