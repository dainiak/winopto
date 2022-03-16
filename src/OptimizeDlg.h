#if !defined(AFX_OPTIMIZEDLG_H__458DBBE1_F208_11D5_9BB8_000000000000__INCLUDED_)
#define AFX_OPTIMIZEDLG_H__458DBBE1_F208_11D5_9BB8_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptimizeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptimizeDlg dialog

class COptimizeDlg : public CDialog
{
// Construction
public:
	COptimizeDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(COptimizeDlg)
	enum { IDD = IDD_OPTIMIZEDLG };
	int		m_Left;
	int		m_Top;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptimizeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptimizeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIMIZEDLG_H__458DBBE1_F208_11D5_9BB8_000000000000__INCLUDED_)
