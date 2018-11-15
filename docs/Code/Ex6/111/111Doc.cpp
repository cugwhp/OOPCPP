// 111Doc.cpp : implementation of the CMy111Doc class
//

#include "stdafx.h"
#include "111.h"

#include "111Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy111Doc

IMPLEMENT_DYNCREATE(CMy111Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy111Doc, CDocument)
	//{{AFX_MSG_MAP(CMy111Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy111Doc construction/destruction

CMy111Doc::CMy111Doc()
{
	// TODO: add one-time construction code here

}

CMy111Doc::~CMy111Doc()
{
}

BOOL CMy111Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy111Doc serialization

void CMy111Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy111Doc diagnostics

#ifdef _DEBUG
void CMy111Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy111Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy111Doc commands
