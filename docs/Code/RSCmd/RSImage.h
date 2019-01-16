#pragma once
#include <string>
using namespace std;

// 数据排列方式枚举
enum eInterleave{BSQ,BIL,BIP};

class CRSImage
{
public:
	CRSImage(void);
	~CRSImage(void);

	// Methods
	void doOpen();	//打开文件
	void doDisplay();	//显示图像
protected:
	string getMetaDataPath(const char*);	//从图像文件路径-->元数据文件路径
	bool ReadMetaData(const char*);			//读取元数据文件
	bool NewImageArray();					//分配数组
	bool ReadImageData(const char*);		//读取图像文件.img to 数组
	bool ReadBsqImage(const char*);			//读取BSQ
	bool ReadBilImage(const char*);			//读取BIL
	bool ReadBipImage(const char*);			//读取BIP
	void Close();							//关闭文件，释放内存

	void DrawImage(int, int, int);			//绘制图像
private:
	int		m_nSamples;
	int		m_nLines;
	int		m_nBands;
	eInterleave		m_eInterleave;
	int		m_nDataType;    
	unsigned char***	m_pppData;
};

