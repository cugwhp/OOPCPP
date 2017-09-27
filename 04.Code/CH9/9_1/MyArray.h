/************************************************************************/
/* class CMyArray                                                       */
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
class CMyArray
{
public:
	// 构造函数和析构函数
	CMyArray(double* ptData=NULL, int nSize=0);	//
	CMyArray(const CMyArray& ary);	//拷贝构造函数
	~CMyArray(void);

	friend ostream& operator<<(ostream& os, const CMyArray& ary);

	// 属性操作
	inline int	GetSize() {return m_nSize;}	//元素个数
	CMyArray operator=(const CMyArray& ary);//重载=
	double& operator[](int i);				//重载[i]
	const double& operator[](int i) const;	//重载[i]
	operator double*() {return m_ptData;}
	
	// 数据操作
	void Add(double dVal);					//追加一个元素

protected:
	int	GetGrowSize() { return m_nSize + 10;}	//内存空间增长后的大小

private:
	double*	m_ptData;	//数组指针
	int		m_nSize;	//元素个数
	int		m_nCapacity;//存储空间（为了保证追加数据的效率，存储空间略大于元素个数）
};

ostream& operator<<(ostream& os, const CMyArray& ary);
