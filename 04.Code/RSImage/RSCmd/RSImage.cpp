#include "RSImage.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

CRSImage::CRSImage()
{
	m_pppData = NULL;
	m_nBands = 0;
	m_nLines = 0;
	m_nSamples = 0;
}

CRSImage::CRSImage(const CRSImage& img)
{

}

CRSImage::~CRSImage()
{
	Close();
}

// Operations
bool	CRSImage::Open(const char* lpstrPath)
{
	if (NULL == lpstrPath)
		return false;

	// 1. Read Meta Data
	string		strMetaFilePath = lpstrPath;
	int				pos = strMetaFilePath.rfind('.');
	if (pos>=0)
    {
        strMetaFilePath = strMetaFilePath.substr(0, pos);
    }
	strMetaFilePath.append(".hdr");
	if (!ReadMetaData(strMetaFilePath.c_str()))
	{
		cerr << "Read Meta Data Failed." << endl;
		return false;
	}

	// 2. Initialize Buffer
	if (!InitBuffer())
	{
		cerr << "Initialize Buffer Failed." << endl;
		return false;
	}

	// 3. Read File
	if (!ReadImgData(lpstrPath))
	{
		cerr << "Read Image Data Failed." << endl;
		return false;
	}

	return true;
}

bool	CRSImage::Save(const char* lpstrPath)
{
	// Write
	return false;
}

void	CRSImage::Close()
{
	// delete...
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

		delete[] m_pppData;

		m_pppData = NULL;
		m_nBands = 0;
		m_nLines = 0;
		m_nSamples = 0;
	}
}

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

bool	CRSImage::ReadImgData(const char* lpstrImgFilePath)
{
    bool        bFlag = true;
    int         i, j;
    ifstream    ifs;
    int*        ptrBuff = NULL;
    ifs.open(lpstrImgFilePath, ios::binary);

    if (ifs.is_open())
    {
        switch(m_eInterleave)
        {
        case BSQ:
            for (i=0; i<m_nBands && !ifs.eof(); i++)
            {
                for (j=0; j<m_nLines && !ifs.eof(); j++)
                {
                    ifs.read((char*)m_pppData[i][j], sizeof(DataType)*m_nSamples);
                }
            }
            // 文件未读完整
            if (i<m_nBands || j<m_nLines)
                bFlag = false;
            break;
        case BIL:
            for (i=0; i<m_nLines && !ifs.eof(); i++)
            {
                for (j=0; j<m_nBands && !ifs.eof(); j++)
                {
                    ifs.read((char*)m_pppData[j][i], sizeof(DataType)*m_nSamples);
                }
            }
            // 数据不完整
            if (i<m_nLines || j<m_nBands)
                bFlag = false;
            break;
        case BIP:
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
            if (i<m_nSamples*m_nLines)
                bFlag = false;
            break;
        }

        ifs.close();
    }

    return bFlag;
}