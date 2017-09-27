/************************************************************************/
/* class CTArray                                                        */
/* 自定义的数组类，动态分配内存											*/
/* Wang hongping 2017.3.7												*/
/************************************************************************/

#pragma once

#ifndef NULL
#define NULL 0
#endif	//NULL

#include <iostream>
using namespace std;

//
template<typename T>
class CTArray
{
public:
	// 构造函数和析构函数
	CTArray(T* ptData=NULL, int nSize=0)//
	{
		m_nSize = max(nSize, 0);
		m_nCapacity = GetGrowSize();

		m_ptData = new T[m_nCapacity];
		if (m_ptData != NULL && m_nSize>0)
		{
			memcpy(m_ptData, ptData, sizeof(T)*m_nSize);
		}
	}

	CTArray(const CTArray& ary)	//拷贝构造函数
	{
		m_nSize = ary.m_nSize;
		m_nCapacity = GetGrowSize();
		m_ptData = new T[m_nCapacity];
		if (m_ptData)
		{
			memcpy(m_ptData, ary.m_ptData, sizeof(T)*m_nSize);
		}
	}

	operator T*()
	{
		return m_ptData;
	}

	~CTArray(void)
	{
		if (m_ptData)
		{
			delete[] m_ptData;
			m_ptData = NULL;
		}
		m_nSize = 0;
		m_nCapacity = 0;
	}

	friend ostream& operator<<(ostream& os, const CTArray<T>& ary)
	{
		int		i;
		for (i=0; i<ary.m_nSize; i++)
		{
			if (i>0 && i%10==0)
				cout << endl;

			os << ary[i] << " ";
		}
		if (i%10)
			cout << endl;

		return os;
	}

	// 属性操作
	inline int	GetSize() {return m_nSize;}	//元素个数

	CTArray operator=(const CTArray& ary)//重载=
	{
		if (m_nSize >= ary.m_nSize)
		{	// 存储空间足够，直接复制
			m_nSize = ary.m_nSize;
			memcpy(m_ptData, ary.m_ptData, sizeof(T)*m_nSize);
		}
		else	//存储空间不够
		{
			// 先释放已有内存，再分配更大的内存空间，最后复制
			if (m_ptData)
			{
				delete[] m_ptData;
				m_ptData = NULL;
			}
			m_nSize = ary.m_nSize;
			m_nCapacity = GetGrowSize();
			m_ptData = new T[m_nCapacity];
			if (m_ptData != NULL)
			{
				memcpy(m_ptData, ary.m_ptData, sizeof(T)*m_nSize);
			}
		}

		return (*this);
	}

	T& operator[](int i)				//重载[i]
	{
		try
		{
			if (i>=0 && i<m_nSize)	//下标检查
				return m_ptData[i];
			else
				throw;
		}
		catch(...)
		{
			cerr << "operator [] failed." << endl;
		}
	}

	const T& operator[](int i) const	//重载[i]
	{
		try
		{
			if (i>=0 && i<m_nSize)	//下标检查
				return m_ptData[i];
			else
				throw;
		}
		catch(...)
		{
			cerr << "operator [] failed." << endl;
		}
	}

	// 数据操作
	void Add(T Val)					//追加一个元素
	{
		// 如果存储空间已满，则需要重新分配内存
		if (m_nSize == m_nCapacity)
		{
			int		nCapacity = GetGrowSize();	//重新分配的内存的大小
			T*	dptBuff = new T[nCapacity];	//new
			if (dptBuff)
			{
				memcpy(dptBuff, m_ptData, sizeof(T)*m_nSize);	//复制原有的数据
			}

			if (m_ptData)	//释放原有数据
			{
				delete[] m_ptData;
			}

			//成员变量重新赋值
			m_ptData = dptBuff;
			m_nCapacity = nCapacity;
		}

		// 追加一个元素
		m_ptData[m_nSize++] = Val;
	}

protected:
	int	GetGrowSize() { return m_nSize + 10;}	//内存空间增长后的大小

private:
	T*		m_ptData;	//数组指针
	int		m_nSize;	//元素个数
	int		m_nCapacity;//存储空间（为了保证追加数据的效率，存储空间略大于元素个数）
};