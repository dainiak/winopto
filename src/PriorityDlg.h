#if !defined(AFX_PRIORITYDLG_H__BDFB8191_E980_11D5_9BAC_000000000000__INCLUDED_)
#define AFX_PRIORITYDLG_H__BDFB8191_E980_11D5_9BAC_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "other\globals.h"
// PriorityDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPriorityDlg dialog

class CPriorityDlg : public CDialog
{
// Construction
public:
	CPriorityDlg(CWnd* pParent = NULL);   // standard constructor
  void UpdateList( void );
  void DeleteObject( COptObject* );
  void AddObject( COptObject*, int = -1 );
  void UpdateObject( COptObject* );

  CView* m_pView;

// Dialog Data
	//{{AFX_DATA(CPriorityDlg)
	enum { IDD = IDD_SETPRIORITY };
	CListBox	m_ObjList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPriorityDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPriorityDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDblclkObjlist();
	afx_msg void OnSelchangeObjlist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIORITYDLG_H__BDFB8191_E980_11D5_9BAC_000000000000__INCLUDED_)
