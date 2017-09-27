#ifndef _CLOCK_H_INCLUDED_
#define _CLOCK_H_INCLUDED_

class Clock
{
public:
	Clock(int h=0, int m=0, int s=0);
	
	void setTime(int h, int m, int s);
	void showTime();
	
private:
	int		hour;
	int		min;
	int		sec;
};

#endif	//_CLOCK_H_INCLUDED_