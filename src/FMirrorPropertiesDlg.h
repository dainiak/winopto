#if !defined(AFX_FMIRRORPROPERTIESDLG_H__6EA10655_E635_11D5_8E17_0080AD7C47F3__INCLUDED_)
#define AFX_FMIRRORPROPERTIESDLG_H__6EA10655_E635_11D5_8E17_0080AD7C47F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FMirrorPropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFMirrorPropertiesDlg dialog

class CFMirrorPropertiesDlg : public CDialog
{
// Construction
public:
	CFMirrorPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFMirrorPropertiesDlg)
	enum { IDD = IDD_FLATMIRROR };
	CString	m_MirrorName;
	int		m_MirrorX1;
	int		m_MirrorY2;
	int		m_MirrorX2;
	int		m_MirrorY1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFMirrorPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFMirrorPropertiesDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMIRRORPROPERTIESDLG_H__6EA10655_E635_11D5_8E17_0080AD7C47F3__INCLUDED_)
