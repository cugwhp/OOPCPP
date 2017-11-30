// RSImageView.h : CRSImageView 类的接口
//


#pragma once

#include "RSImageDef.h"

class CRSImageView : public CView
{
protected: // 仅从序列化创建
	CRSImageView();
	DECLARE_DYNCREATE(CRSImageView)

// 属性
public:
	CRSImageDoc* GetDocument() const;
	double GetDispRate() const {return m_dDispRate;}
	
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CRSImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	double	m_dDispRate;	//显示比例
	int		m_iX0, m_iY0;	//图像偏移的位置
	int		m_iRasXSize, m_iRasYSize;
	void*	m_ptrRedBuff;
	void*	m_ptrGrnBuff;
	void*	m_ptrBluBuff;
	int		m_nXBuffSize;
	int		m_nYBuffSize;
	int		m_nRgbList[3];

	BITMAP	m_oBitmap;
	BYTE*	m_ptRGBBitmap;
	int		m_nBitmapWidth;
	int		m_nBitmapHeight;

	eDispType	m_eDispType;	//显示类型
	eEnhanceStyle	m_eEnhanceStyle;	//增强方式

	bool InitDispPara();	//初始化显示比例	
	bool InitDispBuffer();	//2. 初始化显示缓存	
	bool GenDispBitmap();	//3. 创建显示位图
	void DrawRaster(CDC* pDC);

	void ReleaseBuff();

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // RSImageView.cpp 中的调试版本
inline CRSImageDoc* CRSImageView::GetDocument() const
   { return reinterpret_cast<CRSImageDoc*>(m_pDocument); }
#endif

