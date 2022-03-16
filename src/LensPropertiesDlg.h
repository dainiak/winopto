#if !defined(AFX_LENSPROPERTIESDLG_H__0E204BB3_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
#define AFX_LENSPROPERTIESDLG_H__0E204BB3_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LensPropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLensPropertiesDlg dialog

class CLensPropertiesDlg : public CDialog
{
// Construction
public:
	CLensPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLensPropertiesDlg)
	enum { IDD = IDD_LENS };
	int		m_LensX;
	BOOL	m_ShowMOA;
	BOOL	m_ShowFP;
	CString	m_LensName;
	int		m_LensBottom;
	int		m_LensTop;
	int		m_LensFocalDistance;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLensPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLensPropertiesDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LENSPROPERTIESDLG_H__0E204BB3_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
