// LBlockPropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Opto.h"
#include "LBlockPropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLBlockPropertiesDlg dialog


CLBlockPropertiesDlg::CLBlockPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLBlockPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLBlockPropertiesDlg)
	m_BlockName = _T("");
	m_BlockX1 = 0;
	m_BlockX2 = 0;
	m_BlockY1 = 0;
	m_BlockY2 = 0;
	//}}AFX_DATA_INIT
}


void CLBlockPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLBlockPropertiesDlg)
	DDX_Text(pDX, IDC_LBLOCK_NAME, m_BlockName);
	DDV_MaxChars(pDX, m_BlockName, 32);
	DDX_Text(pDX, IDC_LBLOCK_X1, m_BlockX1);
	DDV_MinMaxInt(pDX, m_BlockX1, 0, 2000);
	DDX_Text(pDX, IDC_LBLOCK_X2, m_BlockX2);
	DDV_MinMaxInt(pDX, m_BlockX2, 0, 2000);
	DDX_Text(pDX, IDC_LBLOCK_Y1, m_BlockY1);
	DDV_MinMaxInt(pDX, m_BlockY1, 0, 2000);
	DDX_Text(pDX, IDC_LBLOCK_Y2, m_BlockY2);
	DDV_MinMaxInt(pDX, m_BlockY2, 0, 2000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLBlockPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CLBlockPropertiesDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLBlockPropertiesDlg message handlers
