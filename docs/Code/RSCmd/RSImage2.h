#pragma once

#include <string>
using namespace std;

class CRSImage
{
public:
	CRSImage(void);
	~CRSImage(void);

	// Methods
	void doOpen();	//# O – Open 打开影像文件


protected:
	// image file path to Meta Data File Path
	string getMetaDataFilePath(const char*);

	// 1. Read Meta Data – 知道img记录的图像的属性
	bool ReadMetaData(const char*);	//string::c_str();
	
	// 2. New Arrays to store Image – 需要分配数组来存放多个图层的图像
	bool NewArrays();

	// 3. Read Image Data – 将img文件的内容逐个读取到前面分配的数组中
	bool ReadImageData(const char*);
};

/*
	void doDisplay();	//# D - Display 显示图像
	void doInfo();	//# I – Information 输出当前图像的路径 ，行列值 、波段数 、数据类 数据类 型、排列方式等信息
	void doClose();	//# C – Closed 关闭当前图像
	void doStat();	//# S – Statistics 输出图像数据统计量 ，若文件未打开 ，输出提示
	void doHist();	//# H – Histogram 输出图像的直方图
	void doSaveas();	//# A – Save as 输入保存的文件路径 ，输出图像为二进制文件
	void doRotate();	//# R – Rotate 图像旋转，输入角度逆时针
	void doZoom();	//# Z – Zoom 图像缩放，输入比例尺出
	void doFilter();	//# F - Filter 输入滤波核，输出滤波后图像
*/