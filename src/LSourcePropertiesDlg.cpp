// LSourcePropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "opto.h"
#include "LSourcePropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLSourcePropertiesDlg dialog


CLSourcePropertiesDlg::CLSourcePropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLSourcePropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLSourcePropertiesDlg)
	m_LSAngle = 0;
	m_LSX = 0;
	m_LSY = 0;
	m_LSName = _T("");
	//}}AFX_DATA_INIT
}


void CLSourcePropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLSourcePropertiesDlg)
	DDX_Text(pDX, IDC_LS_ANGLE, m_LSAngle);
	DDV_MinMaxInt(pDX, m_LSAngle, -180, 180);
	DDX_Text(pDX, IDC_LS_X, m_LSX);
	DDV_MinMaxInt(pDX, m_LSX, 0, 2000);
	DDX_Text(pDX, IDC_LS_Y, m_LSY);
	DDV_MinMaxInt(pDX, m_LSY, 0, 2000);
	DDX_Text(pDX, IDC_LS_NAME, m_LSName);
	DDV_MaxChars(pDX, m_LSName, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLSourcePropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CLSourcePropertiesDlg)
	ON_BN_CLICKED(IDC_LS_COLOR, OnLsColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLSourcePropertiesDlg message handlers

void CLSourcePropertiesDlg::OnLsColor() 
{
  CColorDialog ColorDlg;

  if( ColorDlg.DoModal() == IDOK )
  {
    m_LSColor = ColorDlg.GetColor();
  }	
}
