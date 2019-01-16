#include "RSImage.h"
#include <iostream>
using namespace std;

/*############ Remote Sensing Image Process Tools.############
# X – Exit Exit 退出程序
# O – Open 打开影像文件
# D - Display 显示图像
# I – Information 输出当前图像的路径 ，行列值 、波段数 、数据类 数据类 型、排列方式等信息
# C – Closed 关闭当前图像
# S – Statistics 输出图像数据统计量 ，若文件未打开 ，输出提示
# H – Histogram 输出图像的直方图
# ? – Help 输出本信息
# A – Save as 输入保存的文件路径 ，输出图像为二进制文件
# R – Rotate 图像旋转，输入角度逆时针
# Z – Zoom 图像缩放，输入比例尺出
# F - Filter 输入滤波核，输出滤波后图像
#################################################################*/

// 前向声明
void Usage();

int main()
{
	bool	bExit = false;
	char	cmd;
	CRSImage	orsimg;
	
	Usage();

	do
	{
		cout << "Input Command (? for help):";
		cin >> cmd;

		switch(cmd)
		{
		case 'o':
		case 'O':
			// 打开函数
			orsimg.doOpen();
			break;
		case 'd':
		case 'D':
			orsimg.doDisplay();//显示图像
			break;
		//case ... for others..
		case 'c':
		case 'C':
			break;
		case 'x':
		case 'X':
			bExit = true;
			break;
		case '?':
			Usage();
			break;
		default:
			cout << "Input ? for help." << endl;
			break;
		}

	}while(!bExit);

	return 0;
}

// 程序的提示信息，当输入错误的时候，输出提示
void Usage()
{
	cout << "############ Remote Sensing Image Process Tools.############" << endl;
	cout << "# X – Exit Exit 退出程序" << endl;
	cout << "# O – Open 打开影像文件" << endl;
	cout << "# D - Display 显示图像" << endl;
	cout << "# I – Information 输出当前图像的路径 ，行列值 、波段数 、数据类 数据类 型、排列方式等信息" << endl;
	cout << "# C – Closed 关闭当前图像" << endl;
	cout << "# S – Statistics 输出图像数据统计量 ，若文件未打开 ，输出提示" << endl;
	cout << "# H – Histogram 输出图像的直方图" << endl;
	cout << "# ? – Help 输出本信息" << endl;
	cout << "# A – Save as 输入保存的文件路径 ，输出图像为二进制文件" << endl;
	cout << "# R – Rotate 图像旋转，输入角度逆时针" << endl;
	cout << "# Z – Zoom 图像缩放，输入比例尺出" << endl;
	cout << "# F - Filter 输入滤波核，输出滤波后图像" << endl;
	cout << "#################################################################" << endl;
}