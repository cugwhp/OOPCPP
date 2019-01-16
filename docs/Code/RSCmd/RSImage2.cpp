#include "RSImage.h"
#include <iostream>
#include <string>
using namespace std;

CRSImage::CRSImage(void)
{
}


CRSImage::~CRSImage(void)
{
}

// Methods
//# O – Open 打开影像文件
void CRSImage::doOpen()
{
	cout << "Open()." << endl;
	//画出影像文件打开的流程图！！！！

	// 1. Read Meta Data – 知道img记录的图像的属性
	// 此处需要分析，每个函数的输入、输出参数
	// 比如读元数据文件，需要元数据文件的路径，那么就需要
	string	strImageFilePath;
	cout << "Input Image File Path:";
	cin >> strImageFilePath;

	// .img --> .hdr
	string		strMetaDataFilePath = getMetaDataFilePath(strImageFilePath.c_str());

	// bool 标记是否读入正确
	if (!ReadMetaData(strMetaDataFilePath.c_str()))//string::c_str();
	{
		cerr << "Read Meta Data Failed." << endl;
		return;
	}
	//返回值是什么呢？？？就是lines,samples, bands ...
	// Think??? lines, samples, bands is member variables or local variables???

	// 2. New Arrays to store Image – 需要分配数组来存放多个图层的图像
	if (!NewArrays())
	{
		cerr << "New Arrays Failed." << endl;
		return;
	}

	// 3. Read Image Data – 将img文件的内容逐个读取到前面分配的数组中
	if (!ReadImageData(strImageFilePath.c_str()))
	{
		cerr << "Read Image Data Failed." << endl;
		return;
	}

	cout << "Open Image Success." << endl;
}


string CRSImage::getMetaDataFilePath(const char*)
{
	string		strPath = "";
	return strPath;
}

// 1. Read Meta Data – 知道img记录的图像的属性
bool CRSImage::ReadMetaData(const char* lpstrFilePath)//string::c_str();
{
	return false;
}

// 2. New Arrays to store Image – 需要分配数组来存放多个图层的图像
bool CRSImage::NewArrays()
{
	return false;
}

// 3. Read Image Data – 将img文件的内容逐个读取到前面分配的数组中
bool CRSImage::ReadImageData(const char* lpstrFilePath)
{
	return false;
}

/*

//# D - Display 显示图像
void CRSImage::doDisplay()
{

}

//# I – Information 输出当前图像的路径 ，行列值 、波段数 、数据类 数据类 型、排列方式等信息
void CRSImage::doInfo()
{
}

//# C – Closed 关闭当前图像
void CRSImage::doClose()
{
}

//# S – Statistics 输出图像数据统计量 ，若文件未打开 ，输出提示
void CRSImage::doStat()
{
}	

//# H – Histogram 输出图像的直方图
void CRSImage::doHist()
{
}	

//# A – Save as 输入保存的文件路径 ，输出图像为二进制文件
void CRSImage::doSaveas()
{
}

//# R – Rotate 图像旋转，输入角度逆时针
void CRSImage::doRotate()
{
}

//# Z – Zoom 图像缩放，输入比例尺出
void CRSImage::doZoom()
{
}	

//# F - Filter 输入滤波核，输出滤波后图像
void CRSImage::doFilter()
{
}
*/