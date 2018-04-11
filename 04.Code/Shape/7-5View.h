// 7-5View.h : CMy75View 类的接口
//


#pragma once

class CShape;

class CMy75View : public CView
{
protected: // 仅从序列化创建
	CMy75View();
	DECLARE_DYNCREATE(CMy75View)

// 属性
public:
	CMy75Doc* GetDocument() const;

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
	virtual ~CMy75View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShapeDisplay();
	afx_msg void OnShapeTest();
	afx_msg void OnInitUpdate();
};

#ifndef _DEBUG  // 7-5View.cpp 中的调试版本
inline CMy75Doc* CMy75View::GetDocument() const
   { return reinterpret_cast<CMy75Doc*>(m_pDocument); }
#endif

