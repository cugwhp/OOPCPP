#include "Clock.h"
#include <iostream>
using namespace std;

CClock::CClock(int NewH, int NewM, int NewS)
{
	m_nHour = NewH;
	m_nMin = NewM;
	m_nSec = NewS;
}

CClock::~CClock(void)
{
}


CClock& CClock::operator ++( )	//前置单目运算符重载函数
{
	m_nSec++;
	if(m_nSec>=60)
	{  
		m_nSec=m_nSec-60;
		m_nMin++;
		if(m_nMin>=60)
		{
			m_nMin=m_nMin-60;
			m_nHour++;
			m_nHour=m_nHour%24;
		}
	}
	return *this;
}


//后置单目运算符重载
CClock CClock::operator ++(int)
{
	CClock old=*this;
	++(*this);
	return old;
}

void CClock::ShowTime( )
{
	cout<<m_nHour<<":"<<m_nMin<<":"<<m_nSec<<endl;
}



int _TestClock()
{
	CClock myClock(23,59,59);
	cout<<"First time output:";
	myClock.ShowTime( );
	cout<<"Show myClock++:";
	(myClock++).ShowTime( );
	cout<<"Show myClock:";
	myClock.ShowTime( );
	cout<<"Show ++myClock:";
	(++myClock).ShowTime( );
	return 0;
}