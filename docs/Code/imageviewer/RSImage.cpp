/************************************************************************/
/* File: RSImage.cpp                                                    */
/* class CRSImage implementation										*/
/************************************************************************/

#include "RSImage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;


// 前向声明，调用获取控制台窗口句柄
// 因为是Win32全局函数，故使用extern "C"
//extern "C" HWND WINAPI GetConsoleWindow();

/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
CRSImage::CRSImage()
{
//	m_pppData = NULL;
    m_ppData = NULL;
	m_nBands = 0;
	m_nLines = 0;
	m_nSamples = 0;
}

/************************************************************************/
/* 拷贝构造函数，未实现                                                 */
/************************************************************************/
CRSImage::CRSImage(const CRSImage& img)
{

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
    if (m_ppData)
    {
        for (int i=0; i<m_nBands; i++)
        {
            if (m_ppData[i])
                delete[] m_ppData[i];
        }

        delete[] m_ppData;
    }

    m_ppData = NULL;
    m_nBands = 0;
    m_nLines = 0;
    m_nSamples = 0;
}

/************************************************************************/
/* 以下功能未予以实现                                                   */
/************************************************************************/
void	CRSImage::PrintInfo()
{
}

int		CRSImage::CalcStatistics()
{
	return 0;
}

int		CRSImage::Histogram()
{
	return 0;
}

void	CRSImage::Rotate(float fAngle)
{
}

void	CRSImage::Zoom(float fZoom)
{
}

void	CRSImage::Filter(double* dFilterKernel, int nSize)
{
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
    int     i;

    m_ppData = new DataType* [m_nBands];
    if (m_ppData == NULL)   return false;

    for (i=0; i<m_nBands; i++)
    {
        m_ppData[i] = new DataType[m_nLines*m_nSamples];
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
    DataType*        ptrBuff = NULL;
    ifs.open(lpstrImgFilePath, ios::binary);	//按二进制文件打开

    if (ifs.is_open())	//判断是否打开成功
    {
        switch(m_eInterleave)	//数据存储排列方式
        {
        case BSQ:	//按波段排列，一个波段内按行优先
            for (i=0; i<m_nBands && !ifs.eof(); i++)
            {
                ifs.read((char*)m_ppData[i], sizeof(DataType)*m_nLines*m_nSamples);
            }

            // 判断是否读到了应有的行和列数
            if (i<m_nBands)
                bFlag = false;
            break;
        case BIL:	//按行来排列，以行优先，依次按波段排列
            for (i=0; i<m_nLines && !ifs.eof(); i++)
            {
                for (j=0; j<m_nBands && !ifs.eof(); j++)
                {
                    ifs.read((char*)(m_ppData[j]+i*m_nSamples), sizeof(DataType)*m_nSamples);
                }
            }
            // 数据是否完整
            if (i<m_nLines || j<m_nBands)
                bFlag = false;
            break;
        case BIP:	//按像元优先排列
            ptrBuff = new DataType[m_nBands];
            if (ptrBuff == NULL)
                bFlag = false;

            for (i=0; i<m_nSamples*m_nLines && !ifs.eof(); i++)
            {
                ifs.read((char*)ptrBuff,sizeof(DataType)*m_nBands);

                for (j=0; j<m_nBands; j++)
                {
                    m_ppData[j][i] = ptrBuff[j];
                }
            }
            delete[] ptrBuff;

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
// toQImage - Transform DataBuffer to QImage    						//
// 返回值 - QImage														//
//////////////////////////////////////////////////////////////////////////
QImage  CRSImage::toQImage(int iR, int iG, int iB, EDT eDispType)
{
    QImage      qImage;

    if (!this->IsOpen() || iR<0 || iG<0 || iB<0 ||
        iR>=m_nBands || iG>=m_nBands || iB>=m_nBands)
    {
        return qImage;
    }

    // 波段组合
    switch(eDispType)
    {
    case EDT_Normal:
        normalImage(iR, iG, iB);
        break;
    case EDT_Linear:
        linearImage(iR, iG, iB);
        break;
    default:
        normalImage(iR, iG, iB);
        break;
    }

    // 构建QImage对象
    qImage = QImage((const unsigned char*)(m_aryDispBuff.data()),
                    m_nSamples, m_nLines, QImage::Format_RGB888);

    return qImage;
}

void CRSImage::normalImage(int iR, int iG, int iB)
{
    // 图像数据
    int		iBytesLine = (m_nSamples*24+31) / 32 * 4;	//图像的line,按4字节对齐...
    m_aryDispBuff.resize(m_nLines*iBytesLine);
    m_aryDispBuff.fill(0);

    int     i, j, n=0, k=0;
    for (i=0; i<m_nLines; i++)
    {
        for (j=0; j<m_nSamples; j++)
        {
            m_aryDispBuff[k++] = m_ppData[iR][n];
            m_aryDispBuff[k++] = m_ppData[iG][n];
            m_aryDispBuff[k++] = m_ppData[iB][n++];
        }
        while(k%4) {k++;}   //4 bytes align
    }
}

void CRSImage::linearImage(int iR, int iG, int iB)
{
    // 图像数据
    int		iImageWidth = (m_nSamples*8+31) / 32 * 4;	//图像的宽度,按4字节对齐...
    m_aryDispBuff.resize(m_nLines*iImageWidth*3);
    m_aryDispBuff.fill(0);

    unsigned char     iMin[3], iMax[3];
    int     i, j, k, n;

    iMin[0] = iMax[0] = m_ppData[iR][0];
    iMin[1] = iMax[1] = m_ppData[iG][0];
    iMin[2] = iMax[2] = m_ppData[iB][0];
    for (i=0; i<m_nLines*m_nSamples; i++)
    {
        iMin[0] = min(iMin[0], m_ppData[iR][i]);
        iMin[1] = min(iMin[1], m_ppData[iG][i]);
        iMin[2] = min(iMin[2], m_ppData[iB][i]);
        iMax[0] = max(iMax[0], m_ppData[iR][i]);
        iMax[1] = max(iMax[1], m_ppData[iG][i]);
        iMax[2] = max(iMax[2], m_ppData[iB][i]);
    }

    n = k = 0;
    for (i=0; i<m_nLines; i++)
    {
        for (j=0; j<m_nSamples; j++)
        {
            m_aryDispBuff[k++] = 255L*(m_ppData[iR][n] - iMin[0])/(iMax[0]-iMin[0]);
            m_aryDispBuff[k++] = 255L*(m_ppData[iG][n] - iMin[1])/(iMax[1]-iMin[1]);
            m_aryDispBuff[k++] = 255L*(m_ppData[iB][n] - iMin[2])/(iMax[2]-iMin[2]);
        }
        while(k%4) {k++;}   //4 bytes align
    }
}
//////////////////////////////////////////////////////////////////////////
// Display - 显示图像到控制台窗口										//
// 返回值 - void														//
//////////////////////////////////////////////////////////////////////////
/// \brief CRSImage::Display
/// \param nRedBand
/// \param nGrnBand
/// \param nBluBand
/*
void CRSImage::Display(int nRedBand, int nGrnBand, int nBluBand)
{	
	// 未图像数据，无法显示
	if (m_pppData == NULL || m_nBands<1)
		return;

	HWND	hwnd = NULL;//获得句柄
	HDC		hdc = NULL;
	int		i, j;

	// 窗口句柄为NULL，返回
	hwnd = GetConsoleWindow();
	if (hwnd == NULL)
		return;
	
	// 设备上下文返回NULL，程序返回
	hdc = GetDC(hwnd);	
	if (hdc == NULL)
		return;

	//RGB波段, 若不合法，则用第一个波段作为缺省值
	nRedBand = nRedBand<0||nRedBand>=m_nBands ? 0 : nRedBand;
	nGrnBand = nGrnBand<0||nGrnBand>=m_nBands ? 0 : nGrnBand;
	nBluBand = nBluBand<0||nBluBand>=m_nBands ? 0 : nBluBand;

	// 遍历像素，显示图像
	for (i=0; i<m_nLines; i++)
	{
		for (j=0; j<m_nSamples; j++)
		{	//逐个像元输出
			SetPixel(hdc,j, i, RGB(m_pppData[nRedBand][i][j], m_pppData[nGrnBand][i][j], m_pppData[nBluBand][i][j])); 	
		}
	}
	
	ReleaseDC(hwnd,hdc);
}
*/
