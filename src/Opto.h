// Opto.h : main header file for the OPTO application
//

#if !defined(AFX_OPTO_H__0E204BA3_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
#define AFX_OPTO_H__0E204BA3_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COptoApp:
// See Opto.cpp for the implementation of this class
//

class COptoApp : public CWinApp
{
public:
	COptoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COptoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTO_H__0E204BA3_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
