// RSImageView.cpp : CRSImageView 类的实现
//

#include "stdafx.h"
#include "RSImage.h"

#include "RSImageDoc.h"
#include "RSImageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRSImageView

IMPLEMENT_DYNCREATE(CRSImageView, CView)

BEGIN_MESSAGE_MAP(CRSImageView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRSImageView 构造/析构

CRSImageView::CRSImageView()
{
	// TODO: 在此处添加构造代码
	m_dDispRate = 1.;	//显示比例
	m_iX0 = m_iY0 = 0;	//图像偏移的位置

	// 初始化显示缓存
	m_ptrRedBuff = NULL;
	m_ptrGrnBuff = NULL;
	m_ptrBluBuff = NULL;
	m_nXBuffSize = 0;
	m_nYBuffSize = 0;
	memset(m_nRgbList, 0, sizeof(int)*3);

	memset(&m_oBitmap, 0, sizeof(BITMAP));
	m_ptRGBBitmap = NULL;
	m_nBitmapWidth = 0;
	m_nBitmapHeight = 0;
}

CRSImageView::~CRSImageView()
{
	ReleaseBuff();
}

BOOL CRSImageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

void CRSImageView::OnInitialUpdate()
{
	//1. 初始化显示比例
	InitDispPara();

	//2. 初始化显示缓存
	InitDispBuffer();

	//3. 创建显示位图
	GenDispBitmap();

	OnUpdate(NULL, 0, NULL);
}

//初始化显示比例
bool CRSImageView::InitDispPara()
{
	CRSImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc == NULL)
		return false;

	GDALDataset*	ptrDS = pDoc->GetDS();
	if (ptrDS == NULL)
		return false;

	CRect	rectWnd;
	GetClientRect(&rectWnd);

	m_iRasXSize = ptrDS->GetRasterXSize();
	m_iRasYSize = ptrDS->GetRasterYSize();

	m_dDispRate = min((1.*rectWnd.Width())/m_iRasXSize, (1.*rectWnd.Height())/m_iRasYSize);
	m_iX0 = m_iY0 = 0;

	// 初始化RGB组合
	if (ptrDS->GetRasterCount() >= 3)
	{
		m_nRgbList[0] = 1;
		m_nRgbList[1] = 2;
		m_nRgbList[2] = 3;
		m_eDispType = DT_Color;			//显示类型
		m_eEnhanceStyle = ES_Normal;	//增强方式

	}
	else
	{
		m_nRgbList[0] = m_nRgbList[1] = m_nRgbList[2] = 1;
		m_eDispType = DT_Gray;			//显示类型
		m_eEnhanceStyle = ES_Normal;	//增强方式
	}

	return true;
}

bool CRSImageView::InitDispBuffer()
{
	CRSImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc == NULL)	return false;

	GDALDataset*	ptrDS = pDoc->GetDS();
	if (ptrDS == NULL)	return false;

	m_nXBuffSize = int(m_iRasXSize * m_dDispRate + 0.5);
	m_nYBuffSize = int(m_iRasYSize * m_dDispRate + 0.5);

	m_ptrRedBuff = CPLMalloc(GDALGetDataTypeSize(GDT_Float32) * m_nXBuffSize * m_nYBuffSize);
	m_ptrGrnBuff = CPLMalloc(GDALGetDataTypeSize(GDT_Float32) * m_nXBuffSize * m_nYBuffSize);
	m_ptrBluBuff = CPLMalloc(GDALGetDataTypeSize(GDT_Float32) * m_nXBuffSize * m_nYBuffSize);
	
	GDALRasterBand*	pBand = ptrDS->GetRasterBand(m_nRgbList[0]);
	if (pBand != NULL)
		pBand->RasterIO(GF_Read, 0, 0, m_iRasXSize, m_iRasYSize, m_ptrRedBuff, m_nXBuffSize, m_nYBuffSize, GDT_Float32, 0, 0);

	pBand = ptrDS->GetRasterBand(m_nRgbList[1]);
	if (pBand != NULL)
		pBand->RasterIO(GF_Read, 0, 0, m_iRasXSize, m_iRasYSize, m_ptrGrnBuff, m_nXBuffSize, m_nYBuffSize, GDT_Float32, 0, 0);

	pBand = ptrDS->GetRasterBand(m_nRgbList[2]);
	if (pBand != NULL)
		pBand->RasterIO(GF_Read, 0, 0, m_iRasXSize, m_iRasYSize, m_ptrBluBuff, m_nXBuffSize, m_nYBuffSize, GDT_Float32, 0, 0);	
	
	return true;
}

//3. 创建显示位图
bool CRSImageView::GenDispBitmap()
{
	if (m_nBitmapHeight < m_nYBuffSize || m_nBitmapWidth < m_nXBuffSize)
	{
		if (m_ptRGBBitmap)	delete[] m_ptRGBBitmap;
		m_ptRGBBitmap = NULL;
		m_nBitmapWidth = m_nBitmapHeight = 0;
	}

	if (m_ptRGBBitmap == NULL)
	{
		m_nBitmapWidth = m_nXBuffSize; 
		m_nBitmapHeight = m_nYBuffSize;

		m_ptRGBBitmap = new BYTE[4*m_nBitmapWidth * m_nBitmapHeight];
		memset(m_ptRGBBitmap, 0, sizeof(BYTE)*4*m_nBitmapWidth*m_nBitmapHeight);
	}

	if (m_ptRGBBitmap == NULL)
		return false;

	m_oBitmap.bmBits = (LPVOID)m_ptRGBBitmap;
	m_oBitmap.bmBitsPixel = 24;
	m_oBitmap.bmHeight = m_nBitmapHeight;
	m_oBitmap.bmWidth = m_nBitmapWidth;
	m_oBitmap.bmWidthBytes = ((((24 * m_nBitmapWidth) + 31) / 32) * 4);

	for (int i=0; i<m_nXBuffSize; i++)
	{
		for (int j=0; j<m_nYBuffSize; j++)
		{
			m_ptRGBBitmap[i*3*m_nBitmapWidth+j+0] = (unsigned char)((float*)m_ptrRedBuff)[i*m_nXBuffSize+j];
			m_ptRGBBitmap[i*3*m_nBitmapWidth+j+1] = (unsigned char)((float*)m_ptrGrnBuff)[i*m_nXBuffSize+j];
			m_ptRGBBitmap[i*3*m_nBitmapWidth+j+2] = (unsigned char)((float*)m_ptrBluBuff)[i*m_nXBuffSize+j];
		}
	}

	return true;
}


void CRSImageView::ReleaseBuff()
{
	if (m_ptrRedBuff)
	{
		CPLFree(m_ptrRedBuff);
		m_ptrRedBuff = NULL;
	}

	if (m_ptrGrnBuff)
	{
		CPLFree(m_ptrGrnBuff);
		m_ptrGrnBuff = NULL;
	}

	if (m_ptrBluBuff)
	{
		CPLFree(m_ptrBluBuff);
		m_ptrBluBuff = NULL;
	}

	m_nXBuffSize = 0;
	m_nYBuffSize = 0;

	// 
	if (m_ptRGBBitmap)
	{
		delete m_ptRGBBitmap;
		m_ptRGBBitmap = NULL;
	}
	m_nBitmapWidth = 0;
	m_nBitmapHeight = 0;
}

// CRSImageView 绘制
void CRSImageView::OnDraw(CDC* pDC)
{
	CRSImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DrawRaster(pDC);
}


void CRSImageView::DrawRaster(CDC* pDC)
{
	if (m_oBitmap.bmBits == NULL)
		return;

	HBITMAP hOldBmp;
	CDC		memdc;

	memdc.CreateCompatibleDC(pDC);

	hOldBmp = (HBITMAP)memdc.SelectObject(&m_oBitmap);

	//显示图片
	pDC->BitBlt(0, 0, m_nBitmapWidth, m_nBitmapHeight, &memdc, 0, 0, SRCCOPY);

	memdc.SelectObject(hOldBmp);
}

// CRSImageView 打印

BOOL CRSImageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CRSImageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CRSImageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CRSImageView 诊断

#ifdef _DEBUG
void CRSImageView::AssertValid() const
{
	CView::AssertValid();
}

void CRSImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRSImageDoc* CRSImageView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRSImageDoc)));
	return (CRSImageDoc*)m_pDocument;
}
#endif //_DEBUG


// CRSImageView 消息处理程序
