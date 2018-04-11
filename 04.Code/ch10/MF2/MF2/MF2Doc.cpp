// MF2Doc.cpp : CMF2Doc 类的实现
//

#include "stdafx.h"
#include "MF2.h"

#include "MF2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF2Doc

IMPLEMENT_DYNCREATE(CMF2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMF2Doc, CDocument)
END_MESSAGE_MAP()


// CMF2Doc 构造/析构

CMF2Doc::CMF2Doc()
{
	// TODO: 在此添加一次性构造代码

}

CMF2Doc::~CMF2Doc()
{
}

BOOL CMF2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMF2Doc 序列化

void CMF2Doc::Serialize(CArchive& ar)
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


// CMF2Doc 诊断

#ifdef _DEBUG
void CMF2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMF2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMF2Doc 命令
