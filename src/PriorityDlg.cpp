// PriorityDlg.cpp : implementation file
//

#include "stdafx.h"
#include "opto.h"
#include "PriorityDlg.h"
#include "ObjPrpDialogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPriorityDlg dialog


CPriorityDlg::CPriorityDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPriorityDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPriorityDlg)
	//}}AFX_DATA_INIT
}


void CPriorityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPriorityDlg)
	DDX_Control(pDX, IDC_OBJLIST, m_ObjList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPriorityDlg, CDialog)
	//{{AFX_MSG_MAP(CPriorityDlg)
	ON_LBN_DBLCLK(IDC_OBJLIST, OnDblclkObjlist)
	ON_LBN_SELCHANGE(IDC_OBJLIST, OnSelchangeObjlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CPriorityDlg::DeleteObject( COptObject* Object )
{
  m_ObjList.DeleteString( GetObjectNumber( Object ) );
}

void CPriorityDlg::AddObject( COptObject* Object, int Position )
{
  CString Str;
  
  switch( GetOptObjectType( Object ) )
  {
    case T_LENS:
      if( Object->m_Name.IsEmpty() )
        Str.Format( "Lens" );
      else
        Str.Format( "Lens \"%s\"", Object->m_Name );
      break;

    case T_FLATMIRROR:
      if( Object->m_Name.IsEmpty() )
        Str.Format( "Mirror" );
      else
        Str.Format( "Mirror \"%s\"", Object->m_Name );
      break;

    case T_LIGHTBLOCK:
      if( Object->m_Name.IsEmpty() )
        Str.Format( "Shield" );
      else
        Str.Format( "Shield \"%s\"", Object->m_Name );
      break;

    case T_LIGHTSOURCE:
      if( Object->m_Name.IsEmpty() )
        Str.Format( "Light source" );
      else
        Str.Format( "Light source \"%s\"", Object->m_Name );
      break;

    case T_LIGHTSEGMENT:
      Str.Format("Segment");
  }

  m_ObjList.InsertString( Position, Str );
}

void CPriorityDlg::UpdateList( void )
{
  m_ObjList.ResetContent();

  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    MainOptList.FreeAccess( i );
    AddObject( MainOptList.GetElement() );
  }
}
/////////////////////////////////////////////////////////////////////////////
// CPriorityDlg message handlers

void CPriorityDlg::OnOK() 
{
	//CDialog::OnOK();
}

void CPriorityDlg::OnCancel() 
{
	//CDialog::OnCancel();
}

void CPriorityDlg::UpdateObject( COptObject* Object )
{
  int n = GetObjectNumber( Object );
  m_ObjList.DeleteString( n );
  AddObject( Object, n );
}

void CPriorityDlg::OnDblclkObjlist() 
{
  COptObject* TempObject;
  MainOptList.FreeAccess( m_ObjList.GetCurSel() );
  TempObject = MainOptList.GetElement();

  switch( GetOptObjectType( TempObject ) )
  {
    case T_LENS:
      ChangeLensProperties( LPVOID( TempObject ) );
      break;
    case T_FLATMIRROR:
      ChangeFMirrorProperties( LPVOID( TempObject ) );
      break;
    case T_LIGHTBLOCK:
      ChangeLBlockProperties( LPVOID( TempObject ) );
      break;
    case T_LIGHTSOURCE:
      ChangeLSourceProperties( LPVOID( TempObject ) );
  }

  UpdateObject( TempObject );
}

void CPriorityDlg::OnSelchangeObjlist() 
{
  MainOptList.FreeAccess( m_ObjList.GetCurSel() );
  SelectedObject = MainOptList.GetElement();
  m_pView->Invalidate();
}