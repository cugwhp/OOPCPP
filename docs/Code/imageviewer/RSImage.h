/************************************************************************/
/*                        class CRSImage                                */
/* Author: Wang Hongping												*/
/* Purpose: Reomte sensing image data									*/
/* Modify List:															*/
/* 2016.12.10 - Create it.												*/
/* 2017.12.11 - Add function to Display image in console window 		*/
/************************************************************************/
#ifndef _RS_IMAGE_H_INC_
#define _RS_IMAGE_H_INC_

// NULL define
#ifndef NULL
#define NULL 0
#endif	//#ifndef NULL

// 数据存储方式枚举类型，BSQ-按波段间隔存储、BIL-按行为间隔存储、BIP-按像元间隔存储
enum INTERLEAVE_TYPE {BSQ,BIP,BIL};

// class CRSImage - Remote Sensing image
class CRSImage
{
public:
	typedef unsigned char	DataType;	//typedef 定义数据类型别名

	//------------------- 构造/析构函数 -----------------------//
	CRSImage();
	CRSImage(const CRSImage& img);
	~CRSImage();

	//-------------------------- Operations ------------------------------//
	bool	Open(const char* lpstrPath);	//打开文件，传入文件路径，读取数据到内存变量
	bool	Save(const char* lpstrPath);	//保持文件，传入文件路径，写数据到硬盘
	void	Close();						//关闭图像，初始化变量
	void	PrintInfo();					//打印信息
	int		CalcStatistics();				//计算统计量，以波段为单位
	int		Histogram();					//直方图
	void	Rotate(float fAngle);			//旋转图像
	void	Zoom(float fZoom);				//缩放图像
	void	Filter(double* dFilterKernel, int nSize);	//图像滤波
//	void	Display(int nRedBand=0, int nGrnBand=1, int nBluBand=2);		//显示图像 Add by 2017.12.11

	//--------------- 内联函数，获取图像属性值 --------------------//
	inline int	GetBands() const {return m_nBands;}
	inline int	GetLines() const {return m_nLines;}
	inline int GetSamples() const {return m_nSamples;}
	inline DataType*** GetDataBuffer() const {return m_pppData;}
	inline bool	IsOpen() const { return (NULL != m_pppData ? true : false);}

protected:
	// 读文件
	bool	ReadMetaData(const char* lpstrMetaFilePath);	//元数据文件
	bool	InitBuffer(void);								//初始化内存
	bool	ReadImgData(const char* lpstrImgFilePath);		//读图像文件

protected:
	//--------------------- 成员变量 --------------------------//
	DataType***		m_pppData;		//指针记录三维数组首地址
	int				m_nBands;		//波段数
	int				m_nLines;		//行数
	int				m_nSamples;		//列数
	INTERLEAVE_TYPE m_eInterleave;	//数据存储类型BSQ/BIL/BIP
	short       m_nDataType;		//数据类型
};

#endif	//#ifndef _RS_IMAGE_H_INC_
