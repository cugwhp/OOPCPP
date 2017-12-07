#include <iostream>
#include <string>
#include <sstream>
#include "RSImage.h"
#include "Windows.h"	//windows

using namespace std;

// 前向声明，调用获取控制台窗口句柄
// 因为是Win32全局函数，故使用extern "C"
extern "C" HWND WINAPI GetConsoleWindow();

void Usage();	//declaration forward

// 前向声明，显示图像
void DisplayImage(CRSImage* pRSImg);

// 主函数
int main()
{
	Usage();	//Command用法

	char			cCmd;
	bool			bExit = false;
	string			strParam;
	CRSImage	rsImg;		//RSImage对象

	//循环输入命令，直到输入'X'，退出程序
	do {
		cout << "Input a command: ";
		cin >> cCmd;	//读入Menu

		switch(cCmd)
		{
		case 'X':	// Exit
		case 'x':
			bExit = true;
			break;

		case 'O':	// Open Image
		case 'o':
		    cout << "Input Image file path: ";
			cin >> strParam;
			rsImg.Open(strParam.c_str());
			break;

		case 'I':	// Print Image Info
		case 'i':
			rsImg.PrintInfo();
			break;

		case 'C':	// Close Image
		case 'c':
			rsImg.Close();
			break;

		case 'D':
		case 'd':
			if (rsImg.IsOpen())
				DisplayImage(&rsImg);
			else
				cerr << "Please Open image first." << endl;
			break;

		case 'S':	// Calculate Statistics
		case 's':
			rsImg.CalcStatistics();
			break;

		case 'H':	// Calculate Histogram
		case 'h':
			rsImg.Histogram();
			break;

		case '?':	// Help
			Usage();
			break;

		case 'A':	// Save As File
		case 'a':
			rsImg.Save(NULL);
			break;

		case 'R':	// Rotate-旋转
		case 'r':
			rsImg.Rotate(0.0f);
			break;

		case 'Z':	// Zoom-放大缩小
		case 'z':
			rsImg.Zoom(0.0f);
			break;

		case 'F':	// Filter - 滤波
		case 'f':
			rsImg.Filter(NULL, 0);
			break;
		}
	}while(!bExit);

	return 0;
}


//===================================================================
// 菜单提示，命令行
//===================================================================
void Usage()
{
	cout << "############ Remote Sensing Image Process Tools.############\n";
	cout << "# X – Exit Exit\t退出程序" << endl;
	cout << "# O – Open \t打开影像文件" << endl;
	cout << "# I – Information\t输出当前图像的路径 ，行列值 、波段数 、数据类 数据类 型、排列方式等信息" << endl;
	cout << "# C –Closed\t关闭当前图像" << endl;
	cout << "# S – Statistics\t输出图像数据统计量 ，若文件未打开 ，输出提示" << endl;
	cout << "# H – Histogram\t输出图像的直方" << endl;
	cout << "# ? – Help\t输出本信息" << endl;
	cout << "# A – Save as\t输入保存的文件路径 ，输出图像为二进制文件" << endl;
	cout << "# R – Rotate\t图像旋转，输入角度逆时针" << endl;
	cout << "# Z – Zoom\t图像缩放，输入比例尺出" << endl;
	cout << "# F - Filter\t输入滤波核，输出滤波后图像" << endl;
	cout << "#################################################################" << endl;
}

//////////////////////////////////////////////////////////////////////////
// DisplayImage - 显示图像到控制台窗口									//
// CRSImage* pRSImg - 图像数据指针										//
// 返回值 - void														//
//////////////////////////////////////////////////////////////////////////
void DisplayImage(CRSImage* pRSImg)
{
	// 参数判断
	if (pRSImg==NULL)
		return;
	
	HWND	hwnd = NULL;//获得句柄
	HDC		hdc = NULL;

	// 窗口句柄为NULL，返回
	hwnd = GetConsoleWindow();
	if (hwnd == NULL)
		return;

	// 设备上下文返回NULL，程序返回
	hdc = GetDC(hwnd);	
	if (hdc == NULL)
		return;

	int		i, j;	
	int		nBands = pRSImg->GetBands();		//波段
	int		nSamples = pRSImg->GetSamples();	//列
	int		nLines = pRSImg->GetLines();		//行
	unsigned char***	pppData = pRSImg->GetDataBuffer();	//三维数组头指针
	unsigned char**		ppRed = pppData[0];		//红色通道的波段
	unsigned char**		ppGrn = nBands>2 ? pppData[1] : pppData[0];	//绿色通道的波段
	unsigned char**		ppBlu = nBands>2 ? pppData[2] : pppData[0];	//蓝色通道的波段

	// 遍历像素，显示图像
	for (i=0; i<nLines; i++)
	{
		for (j=0; j<nSamples; j++)
		{	//逐个像元输出
			SetPixel(hdc,j, i, RGB(ppRed[i][j], ppGrn[i][j], ppBlu[i][j])); 	
		}
	}

	ReleaseDC(hwnd,hdc);
}
