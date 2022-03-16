// OptoDoc.h : interface of the COptoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPTODOC_H__0E204BA9_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
#define AFX_OPTODOC_H__0E204BA9_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COptoDoc : public CDocument
{
protected: // create from serialization only
	COptoDoc();
	DECLARE_DYNCREATE(COptoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COptoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COptoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTODOC_H__0E204BA9_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
