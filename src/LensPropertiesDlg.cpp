// LensPropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Opto.h"
#include "LensPropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLensPropertiesDlg dialog


CLensPropertiesDlg::CLensPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLensPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLensPropertiesDlg)
	m_LensX = 0;
	m_ShowMOA = FALSE;
	m_ShowFP = FALSE;
	m_LensName = _T("");
	m_LensBottom = 0;
	m_LensTop = 0;
	m_LensFocalDistance = 0;
	//}}AFX_DATA_INIT
}


void CLensPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLensPropertiesDlg)
	DDX_Text(pDX, IDC_LENS_X, m_LensX);
	DDV_MinMaxInt(pDX, m_LensX, 0, 2000);
	DDX_Check(pDX, IDC_LENS_SHOWMOA, m_ShowMOA);
	DDX_Check(pDX, IDC_LENS_SHOW_FP, m_ShowFP);
	DDX_Text(pDX, IDC_LENS_NAME, m_LensName);
	DDV_MaxChars(pDX, m_LensName, 32);
	DDX_Text(pDX, IDC_LENS_BOTTOM, m_LensBottom);
	DDV_MinMaxInt(pDX, m_LensBottom, 0, 2000);
	DDX_Text(pDX, IDC_LENS_TOP, m_LensTop);
	DDV_MinMaxInt(pDX, m_LensTop, 0, 2000);
	DDX_Text(pDX, IDC_LENS_FDIST, m_LensFocalDistance);
	DDV_MinMaxInt(pDX, m_LensFocalDistance, -300, 300);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLensPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CLensPropertiesDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLensPropertiesDlg message handlers
