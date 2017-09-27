#include "MyArray.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

// 构造函数
CMyArray::CMyArray(double* ptData, int nSize)
{
	m_nSize = max(nSize, 0);
	m_nCapacity = GetGrowSize();

	m_ptData = new double[m_nCapacity];
	if (m_ptData != NULL && m_nSize>0)
	{
		memcpy(m_ptData, ptData, sizeof(double)*m_nSize);
	}
}

// 拷贝构造函数
CMyArray::CMyArray(const CMyArray& ary)
{
	m_nSize = ary.m_nSize;
	m_nCapacity = GetGrowSize();
	m_ptData = new double[m_nCapacity];
	if (m_ptData)
	{
		memcpy(m_ptData, ary.m_ptData, sizeof(double)*m_nSize);
	}
}

// 析构函数
CMyArray::~CMyArray(void)
{
	if (m_ptData)
	{
		delete[] m_ptData;
		m_ptData = NULL;
	}
	m_nSize = 0;
	m_nCapacity = 0;
}

// 重载 = 运算符
CMyArray CMyArray::operator=(const CMyArray& ary)
{
	if (m_nSize >= ary.m_nSize)
	{	// 存储空间足够，直接复制
		m_nSize = ary.m_nSize;
		memcpy(m_ptData, ary.m_ptData, sizeof(double)*m_nSize);
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
		m_ptData = new double[m_nCapacity];
		if (m_ptData != NULL)
		{
			memcpy(m_ptData, ary.m_ptData, sizeof(double)*m_nSize);
		}
	}

	return (*this);
}

// 重载[i]
double& CMyArray::operator[](int i)
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

// 重载[i]
const double& CMyArray::operator[](int i) const
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

// 追加一个元素
void CMyArray::Add(double dVal)
{	
	// 如果存储空间已满，则需要重新分配内存
	if (m_nSize == m_nCapacity)
	{
		int		nCapacity = GetGrowSize();	//重新分配的内存的大小
		double*	dptBuff = new double[nCapacity];	//new
		if (dptBuff)
		{
			memcpy(dptBuff, m_ptData, sizeof(double)*m_nSize);	//复制原有的数据
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
	m_ptData[m_nSize++] = dVal;
}

ostream& operator<<(ostream& os, const CMyArray& ary)
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