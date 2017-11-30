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
	ON_COMMAND(ID_SHAPE_TEST, &CMy75View::OnShapeTest)
	ON_COMMAND(ID_C_C1, &CMy75View::OnCC1)
END_MESSAGE_MAP()

// CMy75View 构造/析构

CMy75View::CMy75View()
{
	// TODO: 在此处添加构造代码
}

CMy75View::~CMy75View()
{

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
	CMy75Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->m_ptShapeAry != NULL)
	{
		for (int i=0; i<pDoc->m_nShapeCount; i++)
		{
			if (pDoc->m_ptShapeAry[i])
			{
				pDoc->m_ptShapeAry[i]->Draw(pDC);

				pDoc->m_ptShapeAry[i]->DrawInfo(pDC);
			}
		}
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


void CMy75View::OnShapeTest()
{
	// TODO: 在此添加命令处理程序代码
	AfxMessageBox("Hello World!");
}

void CMy75View::OnCC1()
{
	// TODO: 在此添加命令处理程序代码
	AfxMessageBox("C++");
}
