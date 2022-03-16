// GeneralPropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Opto.h"
#include "GeneralPropertiesDlg.h"
#include "other\globals.h"
#include "other\optenums.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralPropertiesDlg dialog


CGeneralPropertiesDlg::CGeneralPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGeneralPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGeneralPropertiesDlg)
	m_ClickAccuracy = 0;
	m_DrawShadow = FALSE;
	m_AnimFrequency = 0;
	m_ShowRayArrows = FALSE;
	m_ShowILS = FALSE;
	m_SelectILS = FALSE;
	//}}AFX_DATA_INIT
}


void CGeneralPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralPropertiesDlg)
	DDX_Text(pDX, IDC_CLICKACCURACY, m_ClickAccuracy);
	DDV_MinMaxInt(pDX, m_ClickAccuracy, 1, 6);
	DDX_Check(pDX, IDC_DRAWSHADOW, m_DrawShadow);
	DDX_Text(pDX, IDC_ANIM_FREQ, m_AnimFrequency);
	DDV_MinMaxInt(pDX, m_AnimFrequency, 10, 1000);
	DDX_Check(pDX, IDC_SHOWRAYARROWS, m_ShowRayArrows);
	DDX_Check(pDX, IDC_SHOWILS, m_ShowILS);
	DDX_Check(pDX, IDC_SELECT_ILS, m_SelectILS);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CGeneralPropertiesDlg)
	ON_BN_CLICKED(IDC_LBLOCK_COLOR_BUTTON, OnLblockColorButton)
	ON_BN_CLICKED(IDC_FMIRROR_COLOR_BUTTON, OnFmirrorColorButton)
	ON_BN_CLICKED(IDC_DIVLENS_COLOR_BUTTON, OnDivlensColorButton)
	ON_BN_CLICKED(IDC_CONLENS_COLOR_BUTTON, OnConlensColorButton)
	ON_BN_CLICKED(IDC_ILSCOLOR, OnIlscolor)
	ON_BN_CLICKED(IDC_CSEGCOLOR, OnCsegcolor)
	ON_BN_CLICKED(IDC_SEL_COLOR, OnSelColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralPropertiesDlg message handlers

void CGeneralPropertiesDlg::OnLblockColorButton() 
{
  GraphParams.SetObjectColor( GS_LIGHTBLOCK );	
}

void CGeneralPropertiesDlg::OnFmirrorColorButton() 
{
	GraphParams.SetObjectColor( GS_FLATMIRROR );	
}

void CGeneralPropertiesDlg::OnDivlensColorButton() 
{
  GraphParams.SetObjectColor( GS_DIVERGINGLENS );
}

void CGeneralPropertiesDlg::OnConlensColorButton() 
{
  GraphParams.SetObjectColor( GS_CONVERGINGLENS );
}

void CGeneralPropertiesDlg::OnIlscolor() 
{
  CColorDialog ColorDlg;
  
  if( ColorDlg.DoModal() == IDOK )
    GraphParams.m_ILSColor = ColorDlg.GetColor();
}

void CGeneralPropertiesDlg::OnCsegcolor() 
{
  GraphParams.SetObjectColor( GS_LIGHTSEGMENT );	
}

void CGeneralPropertiesDlg::OnSelColor() 
{
  CColorDialog ColorDlg;
  
  if( ColorDlg.DoModal() == IDOK )
    GraphParams.m_SelectionColor = ColorDlg.GetColor();
}
