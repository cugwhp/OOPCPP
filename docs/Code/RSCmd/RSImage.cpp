#include "RSImage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Windows.h"

using namespace std;

// 前向声明，调用获取控制台窗口句柄
// 因为是Win32全局函数，故使用extern "C"
extern "C" HWND WINAPI GetConsoleWindow();


CRSImage::CRSImage(void)
{
	//初始化
	m_nSamples = 0;
	m_nLines = 0;
	m_nBands = 0;
	m_eInterleave = BSQ;
	m_nDataType = 0; 
	m_pppData = nullptr;
}


CRSImage::~CRSImage(void)
{
	Close();
}

void CRSImage::Close()
{
		if (m_pppData != nullptr)
	{
		for (int i=0; i<m_nBands; ++i)
		{
			for (int j=0; j<m_nLines; ++j)
			{
				if (m_pppData[i][j] != nullptr)
				{
					delete[] m_pppData[i][j];

				}
			}

			if (m_pppData[i] != nullptr)
			{
					delete[] m_pppData[i];
					m_pppData[i] = nullptr;
			}
		}

		delete[] m_pppData;
		m_pppData = nullptr;
	}
}

// Open Image File
void
CRSImage::doOpen()
{
	//0. 文件路径 *.img
	string		strImageFilePath;
	cout << "Input Image File Path: ";
	cin >> strImageFilePath;

	//元数据文件的路径？？
	string		strMetaDataPath;
	strMetaDataPath = getMetaDataPath(strImageFilePath.c_str());

	//1. 打开元数据文件.hdr,读取图像的行、列、波段、排列方式
	if (!ReadMetaData(strMetaDataPath.c_str()))
	{
		cerr << "Read Meta Data Failed." << endl;
		return;
	}

	//2. 为图像分配数组内存空间
	if (!NewImageArray())
	{
		cerr << "New Image Array Failed." << endl;
		return;
	}

	//3. 读取图像文件
	if (!ReadImageData(strImageFilePath.c_str()))
	{
		cerr << "Read Image Data Failed." << endl;
		return;
	}

	// Open Image Success.
	cout << "Read Image Success." << endl;

	return;
}

//从图像文件路径-->元数据文件路径
string CRSImage::getMetaDataPath(const char* lpstrPath)
{
	string		strPath = lpstrPath;
	int			pos = strPath.rfind('.');	//查找'.'的位置

	//
	if (pos >= 0)	//如果存在'.'，将'.'之前的字符串截取出来
		strPath = strPath.substr(0, pos);

	strPath += ".hdr";	//加上".hdr"即可得到元数据文件路径

	return strPath;
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

	ifs.open(lpstrMetaFilePath, ios_base::in);
    if (!ifs.is_open())
        return false;

    while(!ifs.eof())   //end of file
    {
        getline(ifs, strLine);	//读取一行，可以调试下，看读取的内容

        ss.clear();
        ss.str(strLine);    //"samples = 640"
        ss >> strSubTxt;

        if (strSubTxt == "samples")
        {
            ss >> strSubTxt >> m_nSamples;	//读取的变量要保存，故需要定义成员变量
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


bool CRSImage::NewImageArray()				//分配数组
{
	Close();	//先关闭图像

	// 知道了图像的行、列和波段，可以分配数组来存放图像
	typedef unsigned char	ImgType;
	
	m_pppData = new ImgType**[m_nBands];
	if (m_pppData == nullptr)
		return false;

	for (int i=0; i<m_nBands; ++i)
	{
		m_pppData[i] = new ImgType*[m_nLines];
		if (m_pppData[i] == nullptr)
			return false;

		for (int j=0; j<m_nLines; ++j)
		{
			m_pppData[i][j] = new ImgType[m_nSamples];
			if (m_pppData[i][j] == nullptr)
				return false;
		}
	}

	// 很显然，数组要长久存在，便于后面处理，故而要声明为成员变量

	return true;
}

bool CRSImage::ReadImageData(const char* lpstrPath)	//读取图像文件.img to 数组
{
	bool		bFlag = false;

	// 只展示按BSQ读取
	switch(m_eInterleave)
	{
	case BSQ:
		ReadBsqImage(lpstrPath);
		break;
	case BIL:
		ReadBilImage(lpstrPath);
		break;
	case BIP:
		ReadBipImage(lpstrPath);
		break;
	default:
		bFlag = false;
		break;
	}

	return true;
}

//读取BSQ
bool CRSImage::ReadBsqImage(const char* lpstrPath)
{
	ifstream	ifs(lpstrPath, ios::binary);
	if (!ifs)
		return false;

	for (int i=0; i<m_nBands; ++i)
	{
		for (int j=0; j<m_nLines; ++j)
		{
			ifs.read((char*)m_pppData[i][j], sizeof(unsigned char)*m_nSamples);
		}
	}

	ifs.close();
	return true;
}


bool CRSImage::ReadBilImage(const char* lpstrPath)		//读取BIL
{
	return false;
}

bool CRSImage::ReadBipImage(const char* lpstrPath)	//读取BIP
{
	return false;
}

//显示图像
void CRSImage::doDisplay()
{
	//0. 判断文件是否打开，能否显示
	if (m_pppData == nullptr || m_nLines<1 || m_nSamples < 1 || m_nBands < 1)
	{
		cerr << "Unable Image." <<endl;
		return;
	}

	//1. 输入显示的通道
	int		r, g, b;
	cout << "Input R G B bands base 0: ";
	cin >> r >> g >> b;
	if (r<0 || r>=m_nBands ||
		g<0 || g>=m_nBands ||
		b<0 || b>=m_nBands)
	{
		cerr << "Input Invalid bands no" << endl;
		return;
	}

	//2.绘制图像
	DrawImage(r, g, b);
}

void CRSImage::DrawImage(int r, int g, int b)
{
	HWND	hWnd = GetConsoleWindow();

	if (hWnd == 0L)
	{
		cerr << "Get Window failed." << endl;
		return;
	}

	HDC		hDC = GetDC(hWnd);
	if (hDC == 0L)
	{
		cerr << "Get DC Failed." << endl;
		return;
	}

	for (int i=0; i<m_nLines; ++i)
	{
		for (int j=0; j<m_nSamples; ++j)
			SetPixel(hDC, j, i, RGB(m_pppData[r][i][j], m_pppData[g][i][j], m_pppData[b][i][j]));
	}
	return;
}