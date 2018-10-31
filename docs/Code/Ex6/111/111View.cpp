// 111View.cpp : implementation of the CMy111View class
//

#include "stdafx.h"
#include "111.h"

#include "111Doc.h"
#include "111View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy111View

IMPLEMENT_DYNCREATE(CMy111View, CView)

BEGIN_MESSAGE_MAP(CMy111View, CView)
	//{{AFX_MSG_MAP(CMy111View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy111View construction/destruction

CMy111View::CMy111View()
{
	// TODO: add construction code here

}

CMy111View::~CMy111View()
{
}

BOOL CMy111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy111View drawing

void CMy111View::OnDraw(CDC* pDC)
{
	CMy111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy111View printing

BOOL CMy111View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy111View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy111View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy111View diagnostics

#ifdef _DEBUG
void CMy111View::AssertValid() const
{
	CView::AssertValid();
}

void CMy111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy111Doc* CMy111View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy111Doc)));
	return (CMy111Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy111View message handlers
