#if !defined(AFX_LBLOCKPROPERTIESDLG_H__6EA10654_E635_11D5_8E17_0080AD7C47F3__INCLUDED_)
#define AFX_LBLOCKPROPERTIESDLG_H__6EA10654_E635_11D5_8E17_0080AD7C47F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LBlockPropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLBlockPropertiesDlg dialog

class CLBlockPropertiesDlg : public CDialog
{
// Construction
public:
	CLBlockPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLBlockPropertiesDlg)
	enum { IDD = IDD_LIGHTBLOCK };
	CString	m_BlockName;
	int		m_BlockX1;
	int		m_BlockX2;
	int		m_BlockY1;
	int		m_BlockY2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLBlockPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLBlockPropertiesDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LBLOCKPROPERTIESDLG_H__6EA10654_E635_11D5_8E17_0080AD7C47F3__INCLUDED_)
