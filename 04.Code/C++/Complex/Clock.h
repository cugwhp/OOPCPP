#pragma once

class CClock	//时钟类声明
{
public:	//外部接口
	CClock(int NewH=0, int NewM=0, int NewS=0);
	~CClock(void);

	void ShowTime( );

	CClock&  operator ++( );  //前置单目运算符重载
	CClock operator ++(int);  //后置单目运算符重载

private:	//私有数据成员
	int m_nHour;
	int	m_nMin;
	int	m_nSec;
};

int _TestClock();