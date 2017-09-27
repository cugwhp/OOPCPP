// DisplayRSImageDoc.h : CDisplayRSImageDoc 类的接口
//


#pragma once


class CDisplayRSImageDoc : public CDocument
{
protected: // 仅从序列化创建
	CDisplayRSImageDoc();
	DECLARE_DYNCREATE(CDisplayRSImageDoc)

// 属性
public:
	GDALDataset*	GetDataset() { return m_poDataset; }	//返回栅格数据对象

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);

	virtual void DeleteContents();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CDisplayRSImageDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	GDALDataset*	m_poDataset;	//栅格数据句柄

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};