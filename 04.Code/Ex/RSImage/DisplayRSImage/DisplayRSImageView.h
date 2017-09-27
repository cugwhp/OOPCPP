// DisplayRSImageView.h : CDisplayRSImageView 类的接口
//


#pragma once


class CDisplayRSImageView : public CScrollView
{
protected: // 仅从序列化创建
	CDisplayRSImageView();
	DECLARE_DYNCREATE(CDisplayRSImageView)

	// 特性
public:
	CDisplayRSImageDoc* GetDocument() const;

	// 操作
public:

	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 实现
public:
	virtual ~CDisplayRSImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

/************************************************************************/
/* 用于绘制图像的接口和数据                                             */
/************************************************************************/
protected:
	void	DrawImage(CDC* pDC);			//绘制图像
	void	DrawImgInfo(CDC* pDC);			//绘制图像信息
	void	ReadRaster();					//读图像数据，根据
	bool	InitBuffer(double dRatio = 0.);	//初始化位图缓存

protected:
	void*	m_pRBuff;			// R 波段的数据（缓存）
	void*	m_pGBuff;			// G 波段的数据（缓存）
	void*	m_pBBuff;			// B 波段的数据（缓存）
	int		m_nBuffWidth;		// 缓存的X Size，一般等于窗口的宽度
	int		m_nBuffHeight;		// 缓存的Y size，一般等于窗口的高度
	BYTE*	m_pbyRGB;			// 位图RGB缓存，BIP存放
	int		m_nRGBWidth;		// 位图的宽度
	int		m_nRGBHeight;		// 位图的高度
	double	m_dRatio;			// 显示比例，图像窗口大小/行列值
	int		m_nRBandIdx;		// R波段索引
	int		m_nGBandIdx;		// G波段索引
	int		m_nBBandIdx;		// B波段索引
	BITMAP	m_bitmap;			// 用于显示的位图对象
	HBITMAP	m_hBitmap;			// 用户显示的位图句柄

	// 生成的消息映射函数
protected:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnInitialUpdate();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DisplayRSImageView.cpp 中的调试版本
inline CDisplayRSImageDoc* CDisplayRSImageView::GetDocument() const
   { return reinterpret_cast<CDisplayRSImageDoc*>(m_pDocument); }
#endif

