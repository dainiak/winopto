// OptimizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "opto.h"
#include "OptimizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptimizeDlg dialog


COptimizeDlg::COptimizeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptimizeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptimizeDlg)
	m_Left = 0;
	m_Top = 0;
	//}}AFX_DATA_INIT
}


void COptimizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptimizeDlg)
	DDX_Text(pDX, IDC_OPTIMIZELEFT, m_Left);
	DDV_MinMaxInt(pDX, m_Left, 0, 100);
	DDX_Text(pDX, IDC_OPTIMIZETOP, m_Top);
	DDV_MinMaxInt(pDX, m_Top, 0, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptimizeDlg, CDialog)
	//{{AFX_MSG_MAP(COptimizeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptimizeDlg message handlers
