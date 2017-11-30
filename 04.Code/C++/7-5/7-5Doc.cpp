// 7-5Doc.cpp : CMy75Doc 类的实现
//

#include "stdafx.h"
#include "7-5.h"

#include "7-5Doc.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy75Doc

IMPLEMENT_DYNCREATE(CMy75Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy75Doc, CDocument)
	ON_COMMAND(ID_SHAPE_DISPLAY, &CMy75Doc::OnShapeDisplay)
END_MESSAGE_MAP()


// CMy75Doc 构造/析构

CMy75Doc::CMy75Doc()
{
	// TODO: 在此添加一次性构造代码
	m_ptShapeAry = NULL;
	m_nShapeCount = 0;
}

CMy75Doc::~CMy75Doc()
{
}

BOOL CMy75Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy75Doc 序列化

void CMy75Doc::Serialize(CArchive& ar)
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


// CMy75Doc 诊断

#ifdef _DEBUG
void CMy75Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy75Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy75Doc 命令
void CMy75Doc::DeleteContents()
{
	if (m_ptShapeAry)
	{
		for (int i=0; i<m_nShapeCount; i++)
		{
			if (m_ptShapeAry[i])
				delete m_ptShapeAry[i];
		}

		delete[] m_ptShapeAry;
		m_ptShapeAry = NULL;
	}

	CDocument::DeleteContents();
}

void CMy75Doc::OnShapeDisplay()
{
	if (m_ptShapeAry == NULL)
	{
		m_nShapeCount = 5;
		m_ptShapeAry = new CShape*[m_nShapeCount];

		m_ptShapeAry[0] = new CCircle(10, 100, 100);
		m_ptShapeAry[1] = new CCircle(50, 200, 200);

		m_ptShapeAry[2] = new CRectangle(500, 300, 600, 400);
		m_ptShapeAry[3] = new CRectangle(30, 20, 100,50);
		m_ptShapeAry[4] = new CTriangle(500, 100, 660, 260, 460, 360);
	}

	UpdateAllViews(NULL);
}