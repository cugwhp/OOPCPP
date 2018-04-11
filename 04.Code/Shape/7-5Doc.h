// 7-5Doc.h : CMy75Doc 类的接口
//


#pragma once

#include <list>
#include <memory>
using namespace std;

class CShape;

class CMy75Doc : public CDocument
{
protected: // 仅从序列化创建
	CMy75Doc();
	DECLARE_DYNCREATE(CMy75Doc)

// 属性
public:
	list<CShape*>	m_lstShape;

// 操作
public:
	void	RemoveAllShape();

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();

// 实现
public:
	virtual ~CMy75Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


