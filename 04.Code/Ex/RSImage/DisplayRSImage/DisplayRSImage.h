// DisplayRSImage.h : DisplayRSImage 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CDisplayRSImageApp:
// 有关此类的实现，请参阅 DisplayRSImage.cpp
//

class CDisplayRSImageApp : public CWinApp
{
public:
	CDisplayRSImageApp();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	afx_msg void OnFileOpen();
	DECLARE_MESSAGE_MAP()
};

extern CDisplayRSImageApp theApp;