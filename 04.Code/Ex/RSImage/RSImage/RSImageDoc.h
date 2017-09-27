// RSImageDoc.h : CRSImageDoc 类的接口
//


#pragma once


class CRSImageDoc : public CDocument
{
protected: // 仅从序列化创建
	CRSImageDoc();
	DECLARE_DYNCREATE(CRSImageDoc)

// 属性
public:
	GDALDataset* GetDS() {return m_ptrDS;}
	GDALDataset*	GetDataset() { return m_poDataset; }

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);

	virtual void DeleteContents();

// 实现
public:
	virtual ~CRSImageDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	GDALDataset*	m_ptrDS;
	GDALDataset*	m_poDataset;	//Dataset

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


