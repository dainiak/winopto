#if !defined(AFX_LSOURCEPROPERTIESDLG_H__F7EA9E01_EE3C_11D5_9BB2_000000000000__INCLUDED_)
#define AFX_LSOURCEPROPERTIESDLG_H__F7EA9E01_EE3C_11D5_9BB2_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LSourcePropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLSourcePropertiesDlg dialog

class CLSourcePropertiesDlg : public CDialog
{
// Construction
public:
	CLSourcePropertiesDlg(CWnd* pParent = NULL);   // standard constructor
  COLORREF m_LSColor;

// Dialog Data
	//{{AFX_DATA(CLSourcePropertiesDlg)
	enum { IDD = IDD_LIGHTSOURCE };
	int		m_LSAngle;
	int		m_LSX;
	int		m_LSY;
	CString	m_LSName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLSourcePropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLSourcePropertiesDlg)
	afx_msg void OnLsColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LSOURCEPROPERTIESDLG_H__F7EA9E01_EE3C_11D5_9BB2_000000000000__INCLUDED_)
