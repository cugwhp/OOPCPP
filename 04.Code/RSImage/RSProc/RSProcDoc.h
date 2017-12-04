// RSProcDoc.h : CRSProcDoc 类的接口
//


#pragma once

#include "RSImage.h"

class CRSProcDoc : public CDocument
{
protected: // 仅从序列化创建
	CRSProcDoc();
	DECLARE_DYNCREATE(CRSProcDoc)

// 属性
public:

// 操作
public:
	const CRSImage&	GetImage() const { return m_oImage;}

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();

// 实现
public:
	virtual ~CRSProcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CRSImage	m_oImage;

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


