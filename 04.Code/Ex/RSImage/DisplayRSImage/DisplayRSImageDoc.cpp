// DisplayRSImageDoc.cpp : CDisplayRSImageDoc 类的实现
//

#include "stdafx.h"
#include "DisplayRSImage.h"

#include "DisplayRSImageDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDisplayRSImageDoc

IMPLEMENT_DYNCREATE(CDisplayRSImageDoc, CDocument)

BEGIN_MESSAGE_MAP(CDisplayRSImageDoc, CDocument)
END_MESSAGE_MAP()


// CDisplayRSImageDoc 构造/析构

CDisplayRSImageDoc::CDisplayRSImageDoc()
{
	// TODO: 在此添加一次性构造代码
	m_poDataset = NULL;
}

CDisplayRSImageDoc::~CDisplayRSImageDoc()
{
}

BOOL CDisplayRSImageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

//===================================================//
// 重载DeleteContents()，清理相关资源
//===================================================//
void CDisplayRSImageDoc::DeleteContents()
{
	// 调用基类接口
	CDocument::DeleteContents();

	// 关闭数据集
	if (m_poDataset)
	{
		delete m_poDataset;
		m_poDataset = NULL;
	}
}

//==========================================================//
// 重载OnOpenDocument接口，用于打开数据集					//
//==========================================================//
BOOL CDisplayRSImageDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	// 调用基类函数
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// 打开数据集
	USES_CONVERSION;	//支持unicode
	m_poDataset = (GDALDataset*)GDALOpen(lpszPathName, GA_ReadOnly);
	if (m_poDataset == NULL)
	{
		AfxMessageBox(_T("Open Image File Failed!!"));

		return FALSE;
	}

	//----------------- 图像是怎么显示的呢 ? ----------------------//
	// MFC 有一整套机制，来通知视图来绘制，你要做的就是在视图的OnDraw()
	// 接口中填写相应的绘制图像代码即可。
	//=============================================================//

	return TRUE;
}


// CDisplayRSImageDoc 序列化

void CDisplayRSImageDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CDisplayRSImageDoc 诊断

#ifdef _DEBUG
void CDisplayRSImageDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDisplayRSImageDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDisplayRSImageDoc 命令
