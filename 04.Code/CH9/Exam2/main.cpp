/*
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int ReadData(const char* strDataPath, int a[])
{
    if (a==0UL)
        return 0;

    ifstream    ifs;
    ifs.open(strDataPath);
    if (!ifs.is_open())
    {
        cerr << "open file failed.";
        return 0;
    }

    int i = 0;
    while(!ifs.eof() && i<10)
    {
        ifs >> a[i++];
    }
    ifs.close();

    return i;
}

void DirectSelSort(int a[], int n)
{
    if (a==0UL || n<2)
        return;

    int iTemp;
    int iIdx;
    int i, j;

    for (i=0; i<9; i++)
    {
        iIdx = i;
        for (j=i+1; j<10; j++)
        {
            if (a[iIdx] > a[j])
            {
                iIdx = j;
            }
        }
        iTemp = a[i];
        a[i] = a[iIdx];
        a[iIdx] = iTemp;
    }

    return;
}

template<typename T>
void Sort(T A[], int n)
{
    int i, j;
    T   temp;
    for (i=1; i<n; ++i)
    {
        for (j=i,temp=A[i]; j>0&&A[j-1]>temp; j--)
        {
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

int main()
{
    int     b[] = {4, 5, 2, 1, 7};
    Sort(b, 5);
    return 0;
    int     a[10];
    int     n;

    n = ReadData("d:\\a.txt", a);

    DirectSelSort(a, n);

    for (int i=0; i<n; i++)
        cout << setw(6) << a[i];
    cout << endl;

    return 0;
}
*/

#include <iostream>
using namespace std;

/************************************************************
 * 程序功能：统计图像的最小值、最大值、均值、方差和直方图， *
             并输出至屏幕									*
 * 要求：实现Min、Max、Mean、Var、Hist函数体，补充其调用部分*
 * 分值：每空5分，共40分。				                    *
 ************************************************************/

// 图像数据数组
int gImg[] ={
48,49,49,50,48,48,42,25,25,23,25,23,25,25,26,32,52,38,46,
49,49,51,49,51,51,46,32,23,23,23,24,25,23,25,34,53,42,37,
50,49,48,51,53,55,51,37,24,23,23,23,25,24,23,36,53,43,38,
53,53,52,53,52,50,52,43,25,24,24,24,24,23,23,36,54,38,45,
55,56,53,50,50,53,48,46,34,26,25,23,24,24,24,39,56,35,38,
58,58,58,56,55,54,47,51,42,40,39,30,25,23,23,42,51,42,46,
47,50,60,61,51,49,46,49,47,48,50,46,38,34,38,55,47,52,51,
46,48,52,59,61,60,67,66,62,64,60,57,55,54,56,52,52,55,46,
62,54,51,52,53,58,60,60,61,62,67,70,69,65,62,62,65,58,51,
89,87,71,54,53,52,56,59,59,59,58,60,58,54,54,62,60,59,61,
89,90,89,62,49,51,53,52,55,56,56,57,54,53,55,55,54,54,55,
96,95,75,65,56,57,52,51,49,53,55,54,53,53,56,54,54,56,53,
87,86,70,65,68,65,60,57,56,57,53,53,52,52,52,56,56,54,41,
53,56,65,63,66,65,67,67,62,59,57,52,50,50,52,57,54,48,37};

///////////////////////////////////////////////////////////////////////////////
//最小值
///////////////////////////////////////////////////////////////////////////////
int Min(int* pImg, int nCount)
{
	int		iMin = pImg[0];
	for (int i=1; i<nCount; i++)
	{
		iMin = iMin < pImg[i] ? iMin : pImg[i];//_____(1)______
	}

	return iMin;
}

///////////////////////////////////////////////////////////////////////////////
//最大值
///////////////////////////////////////////////////////////////////////////////
int Max(int* pImg, int nCount)
{
	int		iMax = pImg[0];
	for (int i=1; i<nCount; i++)
	{
		iMax = iMax > pImg[i] ? iMax : pImg[i];	//_____(2)______
	}

	return iMax;
}

///////////////////////////////////////////////////////////////////////////////
//均值
///////////////////////////////////////////////////////////////////////////////
double Mean(int* pImg, int nCount)
{
	double	dMean = 0.0f;
	for (int i=0; i<nCount; i++)
	{
		dMean += pImg[i];	//_____(3)______
	}
	dMean /= nCount;

	return dMean;
}

///////////////////////////////////////////////////////////////////////////////
//方差
///////////////////////////////////////////////////////////////////////////////
double Var(int* pImg, int nCount)
{
	if (pImg == NULL || nCount < 2)
		return 0.0f;

	double	dMean = Mean(pImg, nCount);
	double	dVar = 0.0f;
	for (int i=0; i<nCount; i++)
	{
		dVar += (pImg[i]-dMean)*(pImg[i]-dMean);	//_____(4)______
	}
	dVar /= nCount-1;	//_____(5)______

	return dVar;
}

///////////////////////////////////////////////////////////////////////////////
//直方图
///////////////////////////////////////////////////////////////////////////////
int* Hist(int * pImg, int nCount)
{
	int*	pszHist = NULL;
	int		iMin = Min(pImg, nCount);
	int		iMax = Max(pImg, nCount);
    int     nLevel = iMax - iMin + 1;//_____(6)______

	pszHist = new int[nLevel]{0};	//
	if (NULL == pszHist)
        return pszHist;

	for (int i=0; i<nCount; i++)
	{
		pszHist[ pImg[i] ]++;//_____(7)______
	}

	return pszHist;
}

///////////////////////////////////////////////////////////////////////////////
//主函数
///////////////////////////////////////////////////////////////////////////////
int main()
{
	// 注意：以下为示例代码，输出功能自行补充代码完成 //
	////////////////////////////////////////////////////

   // 输出最小值、最大值、均值和方差
    cout << "Min = " << Min(gImg, 266) << endl;
    cout << "Max = " << Max(gImg, 266) << endl;
    cout << "Mean= " << Mean(gImg, 266) << endl;
    cout << "Var = " << Var(gImg, 266) << endl;

    // 输出直方图
    int	 *pszHist = Hist(gImg, 266);
	int	 nLevel = Max(gImg,266)-Min(gImg,266)+1;//_____(8)______;
    for (int i=0; i<nLevel; i++)
    {
        cout << pszHist[i] << "  ";
    }
    cout << endl;
    if (pszHist) delete[] pszHist;

	return 0;
}
