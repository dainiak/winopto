#if !defined(AFX_GENERALPROPERTIESDLG_H__6EA10653_E635_11D5_8E17_0080AD7C47F3__INCLUDED_)
#define AFX_GENERALPROPERTIESDLG_H__6EA10653_E635_11D5_8E17_0080AD7C47F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GeneralPropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGeneralPropertiesDlg dialog

class CGeneralPropertiesDlg : public CDialog
{
// Construction
public:
	CGeneralPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGeneralPropertiesDlg)
	enum { IDD = IDD_GENERALPROPERTIES };
	int		m_ClickAccuracy;
	BOOL	m_DrawShadow;
	int		m_AnimFrequency;
	BOOL	m_ShowRayArrows;
	BOOL	m_ShowILS;
	BOOL	m_SelectILS;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGeneralPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGeneralPropertiesDlg)
	afx_msg void OnLblockColorButton();
	afx_msg void OnFmirrorColorButton();
	afx_msg void OnDivlensColorButton();
	afx_msg void OnConlensColorButton();
	afx_msg void OnIlscolor();
	afx_msg void OnCsegcolor();
	afx_msg void OnSelColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALPROPERTIESDLG_H__6EA10653_E635_11D5_8E17_0080AD7C47F3__INCLUDED_)
