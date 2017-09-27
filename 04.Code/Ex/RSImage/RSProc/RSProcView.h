// RSProcView.h : CRSProcView 类的接口
//


#pragma once


class CRSProcView : public CView
{
protected: // 仅从序列化创建
	CRSProcView();
	DECLARE_DYNCREATE(CRSProcView)

// 属性
public:
	CRSProcDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	inline void SetDrawImage(CRSImage* pImage) {m_pDispImage = pImage;}

protected:
	void DrawImage(CDC* pDC, CRSImage* pImage);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CRSProcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CRSImage*	m_pDispImage;

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // RSProcView.cpp 中的调试版本
inline CRSProcDoc* CRSProcView::GetDocument() const
   { return reinterpret_cast<CRSProcDoc*>(m_pDocument); }
#endif

