// MyAppView.cpp : CMyAppView 类的实现
//

#include "stdafx.h"
#include "MyApp.h"

#include "MyAppDoc.h"
#include "MyAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyAppView

IMPLEMENT_DYNCREATE(CMyAppView, CView)

BEGIN_MESSAGE_MAP(CMyAppView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMyAppView 构造/析构

CMyAppView::CMyAppView()
{
	// TODO: 在此处添加构造代码

}

CMyAppView::~CMyAppView()
{
}

BOOL CMyAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyAppView 绘制

void CMyAppView::OnDraw(CDC* /*pDC*/)
{
	CMyAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMyAppView 打印

BOOL CMyAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMyAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CMyAppView 诊断

#ifdef _DEBUG
void CMyAppView::AssertValid() const
{
	CView::AssertValid();
}

void CMyAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyAppDoc* CMyAppView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyAppDoc)));
	return (CMyAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyAppView 消息处理程序
