// MF2View.cpp : CMF2View 类的实现
//

#include "stdafx.h"
#include "MF2.h"

#include "MF2Doc.h"
#include "MF2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF2View

IMPLEMENT_DYNCREATE(CMF2View, CView)

BEGIN_MESSAGE_MAP(CMF2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMF2View 构造/析构

CMF2View::CMF2View()
{
	// TODO: 在此处添加构造代码

}

CMF2View::~CMF2View()
{
}

BOOL CMF2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMF2View 绘制

void CMF2View::OnDraw(CDC* /*pDC*/)
{
	CMF2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMF2View 打印

BOOL CMF2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMF2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMF2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CMF2View 诊断

#ifdef _DEBUG
void CMF2View::AssertValid() const
{
	CView::AssertValid();
}

void CMF2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMF2Doc* CMF2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMF2Doc)));
	return (CMF2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMF2View 消息处理程序
