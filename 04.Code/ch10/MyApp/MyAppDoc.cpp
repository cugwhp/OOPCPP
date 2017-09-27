// MyAppDoc.cpp : CMyAppDoc 类的实现
//

#include "stdafx.h"
#include "MyApp.h"

#include "MyAppDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyAppDoc

IMPLEMENT_DYNCREATE(CMyAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyAppDoc, CDocument)
END_MESSAGE_MAP()


// CMyAppDoc 构造/析构

CMyAppDoc::CMyAppDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMyAppDoc::~CMyAppDoc()
{
}

BOOL CMyAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMyAppDoc 序列化

void CMyAppDoc::Serialize(CArchive& ar)
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


// CMyAppDoc 诊断

#ifdef _DEBUG
void CMyAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyAppDoc 命令
