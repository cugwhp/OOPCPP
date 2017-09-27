#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
	{
		int		n;
		cin >> n;

		VectorPoint		vecPnt(n);
		vecPnt.GetPoint(0).GetX();
		vecPnt[0].GetX();

		Point*	pPnts = new Point[n];
		
		if (pPnts != 0)
		{
			pPnts[0].GetX();
			
			delete[] pPnts;
			pPnts = 0;
		}
	}

	{
		int		count;
		cout << "Input count: " << endl;
		cin >> count;

		int		i;
		int		*pheight = new int[count];
		if (pheight != 0L)
		{
			for (i=0; i<count; ++i)
			{
				cout << "Input No. " << (i+1) << "  Height: ";
				cin >> pheight[i];
			}
			
			delete[] pheight;
			pheight = 0L;
		}


		return 0;
	}

	{
	Point*	ptPnt = NULL;	// Step 1. 定义指针
	ptPnt = new Point;		// Step 2. 赋值，申请空间
	
	if (ptPnt)	{
		delete ptPnt;			// Step 3. 删除空间
		ptPnt = NULL;
	}
	
	// 
	ptPnt = new Point(1,2);	// ★★初始化列表
	if (ptPnt){
		delete ptPnt;
		ptPnt = NULL;
	}
	ptPnt = new Point();
	if (ptPnt) { 
		delete ptPnt;
		ptPnt = NULL;
	}

	// 指向数组指针
	ptPnt = new Point[10];	
	if (ptPnt){
		delete ptPnt;
		ptPnt = NULL;
	}

	// 有没有错误？？？
	ptPnt = new Point[0];
	
	// 访问元素
	ptPnt[0].GetX();
	(*(ptPnt+0)).GetX();
	(ptPnt+0)->GetX();
	}

	/////////////////////////////////////////////////////////////
	// 1. 指针变量 and const用法
	{
		int		a = 5;
		int		b = 10;
		int	*	pa = &a;
		*pa = 10;	// <==> a=10;
		cout << pa << "\t" << *pa << endl;
		
		// 2. 引用 & const
		int& ra = a;
		ra = 10;	//<==> a=10;
		ra = b;
		
		// 3.指针的引用
		int*	&rpa = pa;	// 	int&	*pra = pa;
		
		//???指针与引用的区别？？？
	}

	/////////////////////////////////////////////////////////////
	// 2.指向数组的指针
	/////////////////////////////////////////////////////////////
	{
		// 一维数组
		int		a[10];
		int		*pa;

		pa = a;
		pa = &a[0];
		cout << pa[1] << "\t";
		cout << *(pa+1) << "\t";
		cout << *pa+1 << "\t";
		
		// 数组指针 VS. 指针数组
		int		b[10][10];
		int		*pb[10];	//指针数组
	//	pb = b;	//????
		int		(*pb2)[10];
		pb2 = b;

		// 如何通过指针访问二维数组？？
		// 方法1. 二维数组等价为一维数组
		int		*pm;	//pm = b;
		pm = &b[0][0];
		// *(pm+i*col+j);
		// pm[i*col+j];
		
		// 方法2. 用指针数组模拟二维数组
		int		**ppm;
		int		irow = 10;
		int		icol = 5;
		int		i;
		ppm = new int* [irow];
		for (i=0; i<irow; ++i)
		{
			ppm[i] = new int[icol];
		}

		//delete
		for (i=0; i<irow; ++i)
		{
			if (ppm[i]) delete[] ppm[i];
		}
		delete[] ppm;
		
		/////////////////////////////////////////////////////////////////////////////////
		/// 函数指针
		//////////////////////////////////////////////////////////////////////////////////
		{
			int		(*pfn)(int, int);
			//pfn = ;
			int		(Point::*pfn2)() = Point::GetX;

			//静态变量？？

		}
		
		
	}
	
	return 0;
}

/**指针的用法

*/
