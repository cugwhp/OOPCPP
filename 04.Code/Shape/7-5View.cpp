// 7-5View.cpp : CMy75View 类的实现
//

#include "stdafx.h"
#include "7-5.h"

#include "7-5Doc.h"
#include "7-5View.h"

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy75View

IMPLEMENT_DYNCREATE(CMy75View, CView)

BEGIN_MESSAGE_MAP(CMy75View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHAPE_DISPLAY, &CMy75View::OnShapeDisplay)
	ON_COMMAND(ID_SHAPE_TEST, &CMy75View::OnShapeTest)
//	ON_COMMAND(WM_INITIALUPDATE, &CMy75View::OnInitUpdate)
END_MESSAGE_MAP()

// CMy75View 构造/析构

CMy75View::CMy75View()
{
	// TODO: 在此处添加构造代码
}

CMy75View::~CMy75View()
{	
}

void CMy75View::OnInitUpdate()
{
	CView::OnInitialUpdate();
}

BOOL CMy75View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy75View 绘制

void CMy75View::OnDraw(CDC* pDC)
{
	pDC->TextOut(10, 10, "Shape Demo.");

	CMy75Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	list<CShape*>::iterator	iter;
	for (iter = pDoc->m_lstShape.begin(); iter!=pDoc->m_lstShape.end(); ++iter)
	{
		(*iter)->Draw(pDC);
	}
}

// CMy75View 打印

BOOL CMy75View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy75View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy75View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CMy75View 诊断

#ifdef _DEBUG
void CMy75View::AssertValid() const
{
	CView::AssertValid();
}

void CMy75View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy75Doc* CMy75View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy75Doc)));
	return (CMy75Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy75View 消息处理程序

void CMy75View::OnShapeDisplay()
{
	CMy75Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	
	pDoc->m_lstShape.push_back(new CCircle(10, 100, 100));
	pDoc->m_lstShape.push_back(new CCircle(50, 200, 200));
	pDoc->m_lstShape.push_back(new CRectangle(500,300, 600, 400));
	pDoc->m_lstShape.push_back(new CRectangle(30, 20, 100,50));

	Invalidate();
}

void CMy75View::OnShapeTest()
{
	// TODO: 在此添加命令处理程序代码
	AfxMessageBox("Hello World!");
}
