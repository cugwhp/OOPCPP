// 111Doc.h : interface of the CMy111Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_111DOC_H__C31AA413_176C_4F00_8475_773127C3B1F9__INCLUDED_)
#define AFX_111DOC_H__C31AA413_176C_4F00_8475_773127C3B1F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy111Doc : public CDocument
{
protected: // create from serialization only
	CMy111Doc();
	DECLARE_DYNCREATE(CMy111Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy111Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy111Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy111Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_111DOC_H__C31AA413_176C_4F00_8475_773127C3B1F9__INCLUDED_)
