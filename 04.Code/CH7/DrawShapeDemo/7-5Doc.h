// 7-5Doc.h : CMy75Doc 类的接口
//


#pragma once

class CShape;

class CMy75Doc : public CDocument
{
protected: // 仅从序列化创建
	CMy75Doc();
	DECLARE_DYNCREATE(CMy75Doc)

// 属性
public:
	CShape**	m_ptShapeAry;
	int			m_nShapeCount;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
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
	afx_msg void OnShapeDisplay();

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


