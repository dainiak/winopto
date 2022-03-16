// FMirrorPropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Opto.h"
#include "FMirrorPropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFMirrorPropertiesDlg dialog


CFMirrorPropertiesDlg::CFMirrorPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFMirrorPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFMirrorPropertiesDlg)
	m_MirrorName = _T("");
	m_MirrorX1 = 0;
	m_MirrorY2 = 0;
	m_MirrorX2 = 0;
	m_MirrorY1 = 0;
	//}}AFX_DATA_INIT
}


void CFMirrorPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFMirrorPropertiesDlg)
	DDX_Text(pDX, IDC_FMIRROR_NAME, m_MirrorName);
	DDV_MaxChars(pDX, m_MirrorName, 32);
	DDX_Text(pDX, IDC_FMIRROR_X1, m_MirrorX1);
	DDV_MinMaxInt(pDX, m_MirrorX1, 0, 2000);
	DDX_Text(pDX, IDC_FMIRROR_Y2, m_MirrorY2);
	DDV_MinMaxInt(pDX, m_MirrorY2, 0, 2000);
	DDX_Text(pDX, IDC_FMIRROR_X2, m_MirrorX2);
	DDV_MinMaxInt(pDX, m_MirrorX2, 0, 2000);
	DDX_Text(pDX, IDC_FMIRROR_Y1, m_MirrorY1);
	DDV_MinMaxInt(pDX, m_MirrorY1, 0, 2000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFMirrorPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CFMirrorPropertiesDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFMirrorPropertiesDlg message handlers

