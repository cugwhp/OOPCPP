// RSProcView.cpp : CRSProcView 类的实现
//

#include "stdafx.h"
#include "RSProc.h"

#include "RSProcDoc.h"
#include "RSProcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRSProcView

IMPLEMENT_DYNCREATE(CRSProcView, CView)

BEGIN_MESSAGE_MAP(CRSProcView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRSProcView 构造/析构

CRSProcView::CRSProcView()
{
	// TODO: 在此处添加构造代码

}

CRSProcView::~CRSProcView()
{
}

BOOL CRSProcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CRSProcView 绘制

void CRSProcView::OnDraw(CDC* pDC)
{
	CRSProcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRSImage::DataType***	pppData = pDoc->GetImage().GetDataBuffer();
	if (pppData != NULL)
	{
		int	nLines = pDoc->GetImage().GetLines();
		int nSamples = pDoc->GetImage().GetSamples();
		int	nBands = pDoc->GetImage().GetBands();

		int	x, y;
		int	iRed, iGreen, iBlue;
		iRed = min(nBands-1,0);
		iGreen = min(nBands-1,1);
		iBlue = min(nBands-1, 2);
		for (x=0; x<nLines; ++x)
		{
			for (y=0; y<nSamples; ++y)
			{
				pDC->SetPixel(y, x, RGB(pppData[iRed][x][y], pppData[iGreen][x][y], pppData[iBlue][x][y]));
			}
		}
	}
}


// CRSProcView 打印

BOOL CRSProcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CRSProcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CRSProcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CRSProcView 诊断

#ifdef _DEBUG
void CRSProcView::AssertValid() const
{
	CView::AssertValid();
}

void CRSProcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRSProcDoc* CRSProcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRSProcDoc)));
	return (CRSProcDoc*)m_pDocument;
}
#endif //_DEBUG


// CRSProcView 消息处理程序
