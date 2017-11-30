#pragma once

#include <iostream>
using namespace std;

template<typename T, int MAXSIZE=100>
class CTStack
{
public:
	CTStack();
	~CTStack();

	bool Push(const T& item);
	T Pop();

	const T& Peek() const;
	void Clear();

	bool IsEmpty();
	bool IsFull();

private:
	T		m_Ary[MAXSIZE];
	int		m_nTop;

	friend ostream& operator<<(ostream& os, const CTStack<T,MAXSIZE>& s)
	{
		int		i;
		int		nCount = 0;
		for (i=s.m_nTop; i>-1; i--)
		{
			if ((++nCount)%10==0)
				os << endl;
			os << s.m_Ary[i] << "\t";
		}
		if (nCount%10)
			os << endl;

		return os;
	}
};

//

template<typename T, int MAXSIZE>
CTStack<T, MAXSIZE>::CTStack()
{
	m_nTop = -1;
}

template<typename T, int MAXSIZE>
CTStack<T, MAXSIZE>::~CTStack()
{
}

template<typename T, int MAXSIZE>
bool CTStack<T, MAXSIZE>::Push(const T& item)
{
	if (!IsFull())
	{
		m_Ary[++m_nTop] = item;
		return true;
	}
	return false;
}

template<typename T, int MAXSIZE>
T CTStack<T, MAXSIZE>::Pop()
{
	if (!IsEmpty())
		return m_Ary[m_nTop--];
}

template<typename T, int MAXSIZE>
const T& CTStack<T, MAXSIZE>::Peek() const
{
	if (!IsEmpty())
		return m_Ary[m_nTop];	
}

template<typename T, int MAXSIZE>
void CTStack<T, MAXSIZE>::Clear()
{
	m_nTop = -1;
}

template<typename T, int MAXSIZE>
bool CTStack<T, MAXSIZE>::IsEmpty()
{
	return (m_nTop>-1);
}

template<typename T, int MAXSIZE>
bool CTStack<T, MAXSIZE>::IsFull()
{
	return (m_nTop>=MAXSIZE-1);
}