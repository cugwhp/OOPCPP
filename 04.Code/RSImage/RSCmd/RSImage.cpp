/************************************************************************/
/* File: RSImage.cpp                                                    */
/* class CRSImage implementation										*/
/************************************************************************/

#include "RSImage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "Windows.h"	//windows

using namespace std;


// 前向声明，调用获取控制台窗口句柄
// 因为是Win32全局函数，故使用extern "C"
extern "C" HWND WINAPI GetConsoleWindow();

COLORREF Normal(CRSImage::DataType r, CRSImage::DataType g, CRSImage::DataType b, void* pParameters=NULL);
COLORREF Linear(CRSImage::DataType r, CRSImage::DataType g, CRSImage::DataType b, void* pParameters=NULL);
COLORREF Equalization(CRSImage::DataType r, CRSImage::DataType g, CRSImage::DataType b, void* pParameters=NULL);

/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
CRSImage::CRSImage()
{
	m_pppData = NULL;
	m_nBands = 0;
	m_nLines = 0;
	m_nSamples = 0;
}

/************************************************************************/
/* 拷贝构造函数，未实现                                                 */
/************************************************************************/
CRSImage::CRSImage(const CRSImage& img)
{
	m_pppData = NULL;					//指针记录三维数组首地址
	m_nBands = img.m_nBands;			//波段数
	m_nLines = img.m_nLines;			//行数
	m_nSamples = img.m_nSamples;		//列数
	m_eInterleave = img.m_eInterleave;	//数据存储类型BSQ/BIL/BIP
	m_nDataType = img.m_nDataType;		//数据类型

	if (InitBuffer())
	{
		int     i, j;
		for (i=0; i<m_nBands; ++i)
		{
			for (j=0; j<m_nLines; ++j)
				memcpy(m_pppData[i][j], img.m_pppData[i][j], 
						sizeof(DataType)*m_nSamples);
	    }
	}
}

/************************************************************************/
/* 析构函数                                                             */
/* 释放分配的数组														*/
/************************************************************************/
CRSImage::~CRSImage()
{
	Close();
}

//----------------------------------------------------------------------//
//----------------------------- Operation Methods ----------------------//
//----------------------------------------------------------------------//

/************************************************************************/
/* 功能：Open - 打开图像文件                                            */
/* 参数： const char* lpstrPath - 数据文件路径							*/
/* 返回值： bool 成功-true/失败-false									*/
/************************************************************************/
/* 如示例数据文件为test.img 和 test.hdr。其中test.img 为数据文件，存储图像
   DN；test.hdr为元数据文件（文本文件），记录图像的行、列、波段、数据类型。
   读取文件的意思是指：从数据文件（硬盘上）读取到内存中的过程。			*/
bool	CRSImage::Open(const char* lpstrPath)
{
	// 参数检查
	if (NULL == lpstrPath)
		return false;

	// 1. Read Meta Data
	string		strMetaFilePath = lpstrPath;	//元数据文件与数据文件同名，后缀为.hdr
	int				pos = strMetaFilePath.rfind('.');
	if (pos>=0)
    {
        strMetaFilePath = strMetaFilePath.substr(0, pos);
    }
	strMetaFilePath.append(".hdr");		//替换后缀为.hdr

	// 读元数据文本文件
	if (!ReadMetaData(strMetaFilePath.c_str()))
	{
		cerr << "Read Meta Data Failed." << endl;
		return false;
	}

	// 2. Initialize Buffer
	// 分配三维数组，根据图像的波段、行、列
	if (!InitBuffer())
	{
		cerr << "Initialize Buffer Failed." << endl;
		return false;
	}

	// 3. Read File
	// 读数据文件（二进制），注意排列顺序
	if (!ReadImgData(lpstrPath))
	{
		cerr << "Read Image Data Failed." << endl;
		return false;
	}

	return true;
}

/************************************************************************/
/* Save - 保存文件，与读文件的过程相反，未实现                          */
/************************************************************************/
bool	CRSImage::Save(const char* lpstrPath)
{
	// Write
	return false;
}

/************************************************************************/
/* Close - 释放图像内存                                                 */
/************************************************************************/
void	CRSImage::Close()
{
	// 注意释放的顺序，与new的顺序是相反的
	if (m_pppData != NULL)
	{
		int			i, j;

		for (i=0; i<m_nBands; ++i)
		{
			for (j=0; j<m_nLines; ++j)
			{
			    if (0UL != m_pppData[i][j])
                {
                    delete[] m_pppData[i][j];
                    m_pppData[i][j] = 0UL;
                }
			}

			if (0UL != m_pppData[i])
			{
			    delete[] m_pppData[i];
			    m_pppData[i] = 0UL;
			}
		}

		delete[] m_pppData;	//delete 

		m_pppData = NULL;
		m_nBands = 0;
		m_nLines = 0;
		m_nSamples = 0;
	}
}

/************************************************************************/
/* 以下功能未予以实现                                                   */
/************************************************************************/
void	CRSImage::PrintInfo()
{
	if (!IsOpen())
	{
		cerr << "None Opened Image." << endl;
		return;
	}

	cout << "Bands = " << m_nBands << endl;		//波段数
	cout << "Lines = " << m_nLines << endl;		//行数
	cout << "Samples = " << m_nSamples << endl;		//列数
	switch(m_eInterleave)
	{
	case BSQ:
		cout << "Interleave = BSQ" << endl;
		break;
	case BIL:
		cout << "Interleave = BIL" << endl;
		break;
	case BIP:
		cout << "Interleave = BIP" << endl;
		break;
	default:
		break;
	}

	cout << "Data Type = " << m_nDataType << endl;		//数据类型
}

void	CRSImage::OnStatistics()
{
	if (!IsOpen())
	{
		cerr << "Unable to Open Image." << endl;
		return;
	}

	double*	dpMin = new double[m_nBands];
	double*	dpMax = new double[m_nBands];
	double*	dpMean = new double[m_nBands];
	double*	dpVar = new double[m_nBands];

	CalcStatistics(dpMin, dpMax, dpMean, dpVar);

	
	// Display Statistics
	int		i;
	for (i=0; i<m_nBands; ++i)	//波段
	{		
		cout << "Statics of Band " << i+1 << endl;
		cout << "Min = " << dpMin[i] << endl;
		cout << "Max = " << dpMax[i] << endl;
		cout << "Mean = " << dpMean[i] << endl;
		cout << "Variance = " << dpVar[i] << endl;
		cout << "###########################" << endl;
	}

	
	if (dpMin)	delete[] dpMin;
	if (dpMax)	delete[] dpMax;
	if (dpMean) delete[] dpMean;
	if (dpVar)	delete[] dpVar;
}

int	CRSImage::CalcStatistics(double* dpMin,double* dpMax,double* dpMean,double* dpVar)
{
	int		i, j, k;

	for (i=0; i<m_nBands; ++i)	//波段
	{
		if (dpMin)	dpMin[i] = m_pppData[i][0][0];
		if (dpMax)	dpMax[i] = m_pppData[i][0][0];
		if (dpMean)	dpMean[i] = 0.0f;
		if (dpVar)	dpVar[i] = 0.0f;

		for (j=0; j<m_nLines; ++j)	//行数
		{
			for (k=0; k<m_nSamples; ++k)	////列数
			{
				if (dpMin)	dpMin[i] = min(dpMin[i], m_pppData[i][j][k]);
				if (dpMax)	dpMax[i] = max(dpMax[i], m_pppData[i][j][k]);
				if (dpMean)	dpMean[i] += m_pppData[i][j][k];
			}
		}
		if (dpMean)	dpMean[i] /= (1L*m_nLines*m_nSamples);	//Mean

		// Variance
		for (j=0; j<m_nLines; ++j)	//行数
		{
			for (k=0; k<m_nSamples; ++k)	////列数
			{
				if (dpVar)	dpVar[i] += pow(m_pppData[i][j][k]-dpMean[i],2);
			}
		}
		if (dpVar)	dpVar[i] = sqrt(dpVar[i]/(m_nLines*m_nSamples-1L));
	}

	return 0;
}

void	CRSImage::OnHistogram()
{
	int		nHistograms[256];
	int		nCount;
	int		i;
	for (i=0; i<m_nBands; ++i)
	{
		cout << "############# Band " << i+1 << " Histograms ###########" << endl;
		nCount = CalcHistogram(i, nHistograms);

		DrawHistogram(nHistograms, nCount);
	}
}


void	CRSImage::Rotate(float fAngle)
{
	cout << "Constructing ..." << endl;
}

void	CRSImage::Zoom(float fZoom)
{
	cout << "Constructing ..." << endl;
}

void	CRSImage::OnFilter()
{
	if (!IsOpen())
	{
		cerr << "Unable to Open Image." << endl;
		return;
	}

	// Input kernel size
	cout << "Input Filter Kernel Parameters(odd size and kernel): " << endl;
	cout << "Input filter kernel size (3x3,5x5,...odds) : ";
	int		nKernelSz;
	cin >> nKernelSz;
	if (nKernelSz < 0 || nKernelSz%2==0)
	{
		cerr << "Invalid kernel size." << endl;
		return;
	}

	// Input kernel
	double*	dpKernel = new double[nKernelSz*nKernelSz];
	cout << "M - Mean Filter Kernel, Others Key - Optional Filter Kernel" << endl;

	int		i;
	char	cmd;
	cin >> cmd;
	switch(cmd)
	{
	case 'M':
	case 'm':
		for (i=0; i<nKernelSz*nKernelSz; ++i)
			dpKernel[i] = 1.0f/(nKernelSz*nKernelSz);
		break;
	default:
		cout << "Input Kernel " << nKernelSz << "x" << nKernelSz << " : ";
		for (i=0; i<nKernelSz*nKernelSz; ++i)
			cin >> dpKernel[i];
		break;
	}

	// Do convolution
	Conv(dpKernel, nKernelSz);

	if (dpKernel) delete[] dpKernel;

	return;
}

void	CRSImage::Conv(double* dFilterKernel, int nSize)
{
	int		i, j, k, m, n, s;
	DataType*	pDataBuff = new DataType[nSize*nSize];
	double		dConvVal;

	for (i=0; i<m_nBands; ++i)
	{
		for (j=nSize/2; j<m_nLines-nSize/2; ++j)
		{
			for (k=nSize/2; k<m_nSamples-nSize/2; ++k)
			{
				for (s=0,m=-nSize/2; m<=nSize/2; ++m)
				{
					for (n=-nSize/2; n<nSize/2; ++n)
					{
						pDataBuff[s++] = m_pppData[i][j+m][k+n]; 
					}
				}

				dConvVal = 0.0f;
				for (s=0; s<nSize*nSize; ++s)
					dConvVal += pDataBuff[s] * dFilterKernel[s];
				m_pppData[i][j][k] = (DataType)fabs(dConvVal);
			}
		}
	}

	if (pDataBuff)	delete[] pDataBuff;
}


/////////////////////////////////////////////////////////////////////
// 读取元数据文件
/////////////////////////////////////////////////////////////////////
bool	CRSImage::ReadMetaData(const char* lpstrMetaFilePath)
{
    ifstream    ifs;
    string      strLine;
    string      strSubTxt;
    stringstream    ss;

    char        sBuff[260];

	ifs.open(lpstrMetaFilePath, ios_base::in);
    if (!ifs.is_open())
        return false;

    while(!ifs.eof())   //end of file
    {
        ifs.getline(sBuff, 260);
        strLine = sBuff;

        ss.clear();
        ss.str(strLine);    //"samples = 640"
        ss >> strSubTxt;

        if (strSubTxt == "samples")
        {
            ss >> strSubTxt >> m_nSamples;
        }
        else if (strSubTxt == "lines")
        {
            ss >> strSubTxt >> m_nLines;
        }
        else if (strSubTxt == "bands")
        {
            ss >> strSubTxt >> m_nBands;
        }
        else if (strSubTxt == "interleave")
        {
            ss >> strSubTxt >> strSubTxt;
            if (strSubTxt == "bsq")
            {
                m_eInterleave = BSQ;
            }
            else if (strSubTxt == "bip")
            {
                m_eInterleave = BIP;
            }
            else if (strSubTxt == "bil")
            {
                m_eInterleave = BIL;
            }
            else
            {
                // blank
            }
        }
        else if (strSubTxt == "data")
        {
            ss >> strSubTxt;
            if(strSubTxt == "type")
            {
                ss >> strSubTxt >> m_nDataType;
            }
        }
        else
        {
            // blank
        }
    }

	return true;
}

/************************************************************************/
/* InitBuffer - 分配内存                                                */
/* 按波段、行的顺序分配数据存储单元，使用的是3维数组，注意分配方式。	*/
/************************************************************************/
bool	CRSImage::InitBuffer(void)
{
    int     i, j;

    m_pppData = new DataType**[m_nBands];
    if (m_pppData == NULL)  return false;

    for (i=0; i<m_nBands; i++)
        m_pppData[i] = 0UL;

    for (i=0; i<m_nBands; ++i)
    {
        m_pppData[i] = new DataType*[m_nLines];
        if (m_pppData[i] == NULL)   return false;

        for (j=0; j<m_nLines; ++j)
            m_pppData[i][j] = 0UL;

        for (j=0; j<m_nLines; ++j)
        {
            m_pppData[i][j] = new DataType[m_nSamples];
        }
    }

	return true;
}

/************************************************************************/
/* ReadImgData - 读二进制文件                                           */
/* const char* lpstrImgFilePath - 文件路径								*/
/************************************************************************/
bool	CRSImage::ReadImgData(const char* lpstrImgFilePath)
{
    bool        bFlag = true;
    int         i, j;
    ifstream    ifs;				//文件流
    int*        ptrBuff = NULL;
    ifs.open(lpstrImgFilePath, ios::binary);	//按二进制文件打开

    if (ifs.is_open())	//判断是否打开成功
    {
        switch(m_eInterleave)	//数据存储排列方式
        {
        case BSQ:	//按波段排列，一个波段内按行优先
            for (i=0; i<m_nBands && !ifs.eof(); i++)
            {
                for (j=0; j<m_nLines && !ifs.eof(); j++)
                {
                    ifs.read((char*)m_pppData[i][j], sizeof(DataType)*m_nSamples);
                }
            }

            // 判断是否读到了应有的行和列数
            if (i<m_nBands || j<m_nLines)
                bFlag = false;
            break;
        case BIL:	//按行来排列，以行优先，依次按波段排列
            for (i=0; i<m_nLines && !ifs.eof(); i++)
            {
                for (j=0; j<m_nBands && !ifs.eof(); j++)
                {
                    ifs.read((char*)m_pppData[j][i], sizeof(DataType)*m_nSamples);
                }
            }
            // 数据是否完整
            if (i<m_nLines || j<m_nBands)
                bFlag = false;
            break;
        case BIP:	//按像元优先排列
            ptrBuff = new int[m_nBands];
            if (ptrBuff == NULL)
                bFlag = false;

            for (i=0; i<m_nSamples*m_nLines && !ifs.eof(); i++)
            {
                ifs.read((char*)ptrBuff,sizeof(DataType)*m_nBands);

                for (j=0; j<m_nBands; j++)
                {
                    m_pppData[j][i/m_nLines][i%m_nLines] = ptrBuff[j];
                }
            }

			// 检查数据是否读完整
            if (i<m_nSamples*m_nLines)
                bFlag = false;
            break;
        }

        ifs.close();	//关闭文件，记住一定要关闭！
    }

    return bFlag;
}

//////////////////////////////////////////////////////////////////////////
// CalcHistogram - 计算某个波段图像的直方图								//
// Input:																//
//	int nBandIdx - 图像波段，base 0										//
//	int* pHistograms - 直方图数组										//
// 返回值 - int 直方图数组的有效范围（0--Max）							//
//////////////////////////////////////////////////////////////////////////
int CRSImage::CalcHistogram(int nBandIdx, int* pHistograms)
{
	if (!IsOpen())
	{
		cerr << "Unable Open Image." << endl;
		return 0;
	}

	if (nBandIdx<0 || nBandIdx>=m_nBands)
	{
		cerr << "Band Index is Invalid." << endl;
		return 0;
	}

	if (pHistograms==NULL)
	{
		cerr << "Input Parameter is invalid." << endl;
		return 0;
	}

	memset(pHistograms, 0, sizeof(int)*256);

	int		i, j;
	for (i=0; i<m_nLines; ++i)
	{
		for (j=0; j<m_nSamples; ++j)
		{
			pHistograms[m_pppData[nBandIdx][i][j]]++;
		}
	}

	for (i=255; i>=0; --i)
		if (pHistograms[i]>0)
			break;
	return i+1;
}


//////////////////////////////////////////////////////////////////////////
// DrawHistogram - 绘制某个波段图像的直方图								//
// Input:																//
//	int* pHistograms - 直方图数组										//
//	int n - 数组个数													//
// 返回值 - void														//
//////////////////////////////////////////////////////////////////////////
void CRSImage::DrawHistogram(int* pHistograms, int n)
{
	int		i, j;
	int		nMaxHistVal = 0;
	for (i=0; i<n; ++i)
		nMaxHistVal = max(nMaxHistVal, pHistograms[i]);

	int		nYMax = (100L*nMaxHistVal)/(m_nLines*m_nSamples);
	for (i=0; i<nYMax+2; ++i)
	{
		// 绘制纵轴
		if (0 == i)
		{
			cout << "   A";
		}
		else
		{
			cout.unsetf(ios::left);
			cout.fill(' ');
			cout.width(2);
			cout << (nYMax+1-i);
			cout << "%|";
		}

		// 绘制 * 
		for (j=0; j<n; ++j)
		{
			if ((100L*pHistograms[j])/(m_nLines*m_nSamples) == nYMax+2-i)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	// 绘制横轴
	// ---------------------------------------------->
	// 0         10		20			...
	cout << "   ";
	cout.setf(ios::left);
	cout.fill('-');
	for (j=0; j<n; ++j)
	{
		if (j%10==0)
		{
			cout.width(10);	
			cout << j;
		}
	}
	cout << "->" << endl;
	
	return;
}


//////////////////////////////////////////////////////////////////////////
// OnDisplay - 显示图像到控制台窗口										//
// 返回值 - void														//
//////////////////////////////////////////////////////////////////////////
void CRSImage::OnDisplay()
{
	// 未图像数据，无法显示
	if (!IsOpen())
	{
		cerr << "Unable to Open Image." << endl;
		return;
	}

	cout << "Input Display Parameters(Display Type, Stretch Type, Red, Green, Blue) : " << endl;

	int		nType;
	cout << "Input Display Type 0-Gray or 1-Color : ";
	cin >> nType;
	switch(nType)
	{
	case 1:
		nType = DT_Color;
		break;
	default:
		nType = DT_Gray;
		break;
	}

	char	cmd;
	cout << "Input L-Linear stretch, Others - default is Normal : ";
	cin >> cmd;
	switch(cmd)
	{
	case 'L':
	case 'l':
		nType |= DT_Linear;
		break;
	default:
		nType |= DT_Normal;
		break;
	}
	
	int		r, g, b;
	cout << "Input RGB bands or gray Band in base 0 : ";
	if (nType & DT_Gray)
	{
		cin >> r;
		g = b = r;
	}
	else
	{
		cin >> r >> g >> b;
	}

	DrawImage(nType, r, g, b);
}

//////////////////////////////////////////////////////////////////////////
// DrawImage - 显示图像到控制台窗口										//
//	eDisplayType - Display Type, Gray/Color/Normal/Linear/Equalization	//
//	int nRedBand - Red Band base 0										//
//	int nGrndBand - Green Band	base 0									//
//	int nBluBand - Blue Band	base 0									//
// 返回值 - void														//
//////////////////////////////////////////////////////////////////////////
void CRSImage::DrawImage(int nDispType,int nRedBand, int nGrnBand, int nBluBand)
{	
	HWND	hwnd = NULL;//获得句柄
	HDC		hdc = NULL;
	int		i, j;
	COLORREF (*pf)(CRSImage::DataType, CRSImage::DataType, CRSImage::DataType, void*);


	// 窗口句柄为NULL，返回
	hwnd = GetConsoleWindow();
	if (hwnd == NULL)
		return;
	
	// 设备上下文返回NULL，程序返回
	hdc = GetDC(hwnd);	
	if (hdc == NULL)
		return;

	if (nDispType & DT_Gray)	//Gray Display
		nBluBand = nGrnBand = nRedBand;
	else	//RGB波段, 若不合法，则用第一个波段作为缺省值
	{
		nRedBand = nRedBand<0||nRedBand>=m_nBands ? 0 : nRedBand;
		nGrnBand = nGrnBand<0||nGrnBand>=m_nBands ? 0 : nGrnBand;
		nBluBand = nBluBand<0||nBluBand>=m_nBands ? 0 : nBluBand;
	}

	double	dpParamters[6];
	if (nDispType & DT_Linear)
	{
		double*	dpMin = new double[m_nBands];
		double*	dpMax = new double[m_nBands];

		CalcStatistics(dpMin, dpMax);

		dpParamters[0] = dpMin[nRedBand];
		dpParamters[1] = dpMax[nRedBand];
		dpParamters[2] = dpMin[nGrnBand];
		dpParamters[3] = dpMax[nGrnBand];
		dpParamters[4] = dpMin[nBluBand];
		dpParamters[5] = dpMax[nBluBand];

		delete[] dpMin;
		delete[] dpMax;

		pf = Linear;
	}
	else if (nDispType & DT_Equalization)
	{
		pf = Equalization;
	}
	else
	{
		pf = Normal;
	}

	// 遍历像素，显示图像
	for (i=0; i<m_nLines; i++)
	{
		for (j=0; j<m_nSamples; j++)
		{	//逐个像元输出
			SetPixel(hdc,j, i, pf(m_pppData[nRedBand][i][j],
				m_pppData[nGrnBand][i][j], m_pppData[nBluBand][i][j],(void*)dpParamters));
		}
	}
	
	ReleaseDC(hwnd,hdc);
}

COLORREF Normal(CRSImage::DataType r, CRSImage::DataType g, CRSImage::DataType b, void* pParameters)
{
	return RGB(r, g, b);
}

COLORREF Linear(CRSImage::DataType r, CRSImage::DataType g, CRSImage::DataType b, void* pParameters)
{
	double*	pszMinMax = (double*)pParameters;
	r = r*255 / (pszMinMax[1] - pszMinMax[0]);
	g = g*255 / (pszMinMax[3] - pszMinMax[2]);
	b = b*255 / (pszMinMax[5] - pszMinMax[4]);

	return RGB(r, g, b);
}

COLORREF Equalization(CRSImage::DataType r, CRSImage::DataType g, CRSImage::DataType b, void* pParameters)
{
	return RGB(r, g, b);
}
