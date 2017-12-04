// RSProcDoc.cpp : CRSProcDoc 类的实现
//

#include "stdafx.h"
#include "RSProc.h"

#include "RSProcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRSProcDoc

IMPLEMENT_DYNCREATE(CRSProcDoc, CDocument)

BEGIN_MESSAGE_MAP(CRSProcDoc, CDocument)
END_MESSAGE_MAP()


// CRSProcDoc 构造/析构

CRSProcDoc::CRSProcDoc()
{
	// TODO: 在此添加一次性构造代码

}

CRSProcDoc::~CRSProcDoc()
{
}

BOOL CRSProcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}


BOOL CRSProcDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
//	return CDocument::OnOpenDocument(lpszPathName);

	DeleteContents();
	SetModifiedFlag();  // dirty during de-serialize

	if (!m_oImage.Open(lpszPathName))
		return FALSE;

	SetModifiedFlag(FALSE);     // start off with unmodified

	return TRUE;
}

void CRSProcDoc::DeleteContents()
{
	m_oImage.Close();

	CDocument::DeleteContents();
}

// CRSProcDoc 序列化

void CRSProcDoc::Serialize(CArchive& ar)
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


// CRSProcDoc 诊断

#ifdef _DEBUG
void CRSProcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRSProcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRSProcDoc 命令
