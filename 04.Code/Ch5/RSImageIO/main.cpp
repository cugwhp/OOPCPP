#include <iostream>
#include <string>
#include <sstream>
#include "RSImage.h"

using namespace std;

void Usage();	//declaration forward

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
			strParam = "d:\\test\\can_tmr";
			rsImg.Open(strParam.c_str());
			break;

		case 'I':	// Print Image Info
		case 'i':
			break;

		case 'C':	// Close Image
		case 'c':
			break;

		case 'S':	// Calculate Statistics
		case 's':
            cout << "Input Image file path to Save: ";
			cin >> strParam;
			strParam = "d:\\test\\can_tmr";
			rsImg.Save(strParam.c_str());
			break;

		case 'H':	// Calculate Histogram
		case 'h':
			break;

		case '?':	// Help
			Usage();
			break;

		case 'A':	// Save As File
		case 'a':
			break;

		case 'R':	// Rotate-旋转
		case 'r':
			break;

		case 'Z':	// Zoom-放大缩小
		case 'z':
			break;

		case 'F':	// Filter - 滤波
		case 'f':
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
