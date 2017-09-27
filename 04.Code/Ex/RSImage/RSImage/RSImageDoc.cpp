// RSImageDoc.cpp : CRSImageDoc 类的实现
//

#include "stdafx.h"
#include "RSImage.h"

#include "RSImageDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRSImageDoc

IMPLEMENT_DYNCREATE(CRSImageDoc, CDocument)

BEGIN_MESSAGE_MAP(CRSImageDoc, CDocument)
END_MESSAGE_MAP()


// CRSImageDoc 构造/析构

CRSImageDoc::CRSImageDoc()
{
	// TODO: 在此添加一次性构造代码
	m_ptrDS = NULL;
}

CRSImageDoc::~CRSImageDoc()
{
}

BOOL CRSImageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

// Override Open Document for Raster
BOOL CRSImageDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	DeleteContents();
	SetModifiedFlag();  // dirty during de-serialize

	// 打开图像
	m_ptrDS = (GDALDataset*)GDALOpen(lpszPathName, GA_ReadOnly);
	if (m_ptrDS == NULL)	return FALSE;
	
	SetModifiedFlag(FALSE);     // start off with unmodified

	return TRUE;
}


// CRSImageDoc 序列化

void CRSImageDoc::Serialize(CArchive& ar)
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

// 重载，关闭图像
void CRSImageDoc::DeleteContents()
{
	if (m_ptrDS)
	{
		GDALClose(m_ptrDS);
		m_ptrDS = NULL;
	}

	CDocument::DeleteContents();
}

// CRSImageDoc 诊断

#ifdef _DEBUG
void CRSImageDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRSImageDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRSImageDoc 命令
