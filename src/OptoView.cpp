// OptoView.cpp : implementation of the COptoView class
//

#include "stdafx.h"
#include "Opto.h"
#include "MainFrm.h"

#include "OptoDoc.h"
#include "OptoView.h"

#include "ObjPrpDialogs.h"
#include "GeneralPropertiesDlg.h"
#include "OptimizeDlg.h"
#include "other\globals.h"
#include "other\cflatmirror.h"
#include "other\clightsource.h"
#include "other\clightblock.h"
#include "other\clens.h"
#include "other\clightsegment.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptoView

IMPLEMENT_DYNCREATE(COptoView, CScrollView)

BEGIN_MESSAGE_MAP(COptoView, CScrollView)
	//{{AFX_MSG_MAP(COptoView)
	ON_COMMAND(ID_ZOOM_DECREASE, OnZoomDecrease)
	ON_COMMAND(ID_ZOOM_INCREASE, OnZoomIncrease)
	ON_COMMAND(ID_CREATE_FLATMIRROR, OnCreateFlatmirror)
	ON_COMMAND(ID_CREATE_LENS, OnCreateLens)
	ON_COMMAND(ID_CREATE_LIGHTBLOCK, OnCreateLightblock)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_PROPERTIES, OnProperties)
	ON_COMMAND(ID_CREATE_LIGHTSOURCE, OnCreateLightsource)
	ON_COMMAND(ID_SAVE_COLORSCHEME, OnSaveColorscheme)
	ON_COMMAND(ID_LOAD_COLORSCHEME, OnLoadColorscheme)
	ON_COMMAND(ID_ANIMATION_START, OnAnimationStart)
	ON_COMMAND(ID_ANIMATION_STOP, OnAnimationStop)
	ON_WM_TIMER()
	ON_COMMAND(ID_OPTIMIZE, OnOptimize)
	ON_COMMAND(ID_ANIMATION_PAUSE, OnAnimationPause)
	ON_COMMAND(ID_ZOOM_FIT, OnZoomFit)
	ON_UPDATE_COMMAND_UI(ID_ANIMATION_START, OnUpdateAnimationStart)
	ON_UPDATE_COMMAND_UI(ID_ANIMATION_STOP, OnUpdateAnimationStop)
	ON_UPDATE_COMMAND_UI(ID_ANIMATION_PAUSE, OnUpdateAnimationPause)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_DECREASE, OnUpdateZoomDecrease)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_FIT, OnUpdateZoomFit)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_INCREASE, OnUpdateZoomIncrease)
	ON_COMMAND(ID_CREATE_LIGHTSEGMENT, OnCreateLightsegment)
	ON_COMMAND(ID_SELECT_ANIMLS, OnSelectAnimls)
	ON_UPDATE_COMMAND_UI(ID_CREATE_LIGHTSEGMENT, OnUpdateCreateLightsegment)
	ON_COMMAND(ID_HIDE_RAYS, OnHideRays)
	ON_UPDATE_COMMAND_UI(ID_HIDE_RAYS, OnUpdateHideRays)
	ON_UPDATE_COMMAND_UI(ID_SELECT_ANIMLS, OnUpdateSelectAnimls)
	ON_COMMAND(ID_SHOW_OBJDLG, OnShowObjdlg)
	ON_UPDATE_COMMAND_UI(ID_SHOW_OBJDLG, OnUpdateShowObjdlg)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptoView construction/destruction

COptoView::COptoView()
{
  m_ActiveObject = NULL;
  m_MouseFlags = 0;
  m_ClickAccuracy = 3;
  m_DrawShadow = TRUE;
  AnimationFlag = 0;
  m_AnimationFrequency = 100;
  GraphParams.m_Zoom = 1;
  GraphParams.m_DrawILS = TRUE;
  GraphParams.SetScreenLimits( -1, -1, 2005, 2005 );
  GraphParams.m_DrawRayArrows = TRUE;
  m_LSSelectFlag = 0;
  m_AnimationLightSource = NULL;
  m_ObjDlg.Create( IDD_SETPRIORITY );
  m_ObjDlg.m_pView = this;
  SelectedObject = NULL;
  m_IsObjDlgActive = TRUE;
  m_CurrentFileName.Format("");

  //CFile File( "default.ocs", CFile::modeRead );
  //CArchive Archive( &File, CArchive::load );
  //GraphParams.SerializeStyles( Archive );
  //Archive.Close();
  //File.Close();
}

COptoView::~COptoView()
{
  m_ObjDlg.DestroyWindow();
}

BOOL COptoView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COptoView drawing

void COptoView::OnDraw(CDC* pDC)
{
  CRect rect, rect1;
  GetClientRect( &rect );
  rect1 = GetSystemSize();

  if( GraphParams.m_Zoom == -1 )
    GraphParams.m_Zoom = Min( rect.Width() / ( rect1.right + 5.0 ), rect.Height() / ( rect1.bottom + 5.0 ) );
  
  pDC->SetMapMode( MM_ISOTROPIC );
  pDC->SetWindowExt( rect.Width(), rect.Height());
  pDC->ScaleWindowExt( 1, 1, 1, 1 );
  pDC->SetViewportExt( int( rect.Width() * GraphParams.m_Zoom ), 
                       int( rect.Height() * GraphParams.m_Zoom ) );
	CSize sizeTotal;
	sizeTotal.cx = int( ( rect1.right + 5 ) * GraphParams.m_Zoom );
  sizeTotal.cy = int( ( rect1.bottom + 5 ) * GraphParams.m_Zoom );
  SetScrollSizes( MM_TEXT, sizeTotal );
  GlobalDC = pDC; 
  
  if( !AnimationFlag || AnimationFlag == 2 )
  {
    if( AnimationFlag == 2 )
    {
      MainOptList.GoToStart();
  
      while( GetOptObjectType( MainOptList.GetElement() ) != T_LIGHTSOURCE )
        MainOptList.Next();

      StartAnimation( m_AnimationLightSource );
      AnimationFlag = 1;
    }

    if( m_DrawShadow && GraphParams.m_Zoom > 0.5 )  
    {
      GraphParams.m_ShadowMode = TRUE;
      GraphParams.SetGlobalColor( RGB( 195, 195, 195 ) );
      pDC->SetWindowOrg( -2, -2 );
      DrawSystem();
      GraphParams.RestoreColors();
      pDC->SetWindowOrg( 0, 0 );
      GraphParams.m_ShadowMode = FALSE;
    }
    
    DrawSystem();

    if( SelectedObject )
    {
      GraphParams.SetGlobalColor( GraphParams.m_SelectionColor );
      SelectedObject->Draw();
      GraphParams.RestoreColors();
    }
  }

  if( !AnimationFlag )
  {
    CalculateScene();
    
    if( GraphParams.m_DrawILS )
      CalculateSceneSegments();
  }
  
  if( AnimationFlag == 1 )
  {
    AnimateSystem();
    
    if( !AnimationFlag )
    {  
      KillTimer( 1 );
      Invalidate();
    }
  }
}

void COptoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// COptoView diagnostics

#ifdef _DEBUG
void COptoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void COptoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

COptoDoc* COptoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COptoDoc)));
	return (COptoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COptoView additional creation functions

/////////////////////////////////////////////////////////////////////////////
// COptoView message handlers

void COptoView::OnZoomDecrease() 
{
	if( GraphParams.m_Zoom > 0.3 )
  {
    GraphParams.m_Zoom /= 1.2;
    Invalidate();
  }
}

void COptoView::OnZoomIncrease() 
{
	if( GraphParams.m_Zoom < 4 )
  {
    GraphParams.m_Zoom *= 1.2;
    Invalidate();
  }
}

void COptoView::OnCreateFlatmirror() 
{
  CFlatMirror* NewFlatMirror;
  NewFlatMirror = new CFlatMirror;

  if( ChangeFMirrorProperties( NewFlatMirror ))
  {
    MainOptList.AddElement();
    MainOptList.SetElement( ( COptObject* )NewFlatMirror );
    if( m_IsObjDlgActive )
      m_ObjDlg.AddObject( NewFlatMirror );
  }
  else
    delete NewFlatMirror;

  Invalidate();
}

void COptoView::OnCreateLens() 
{
  CLens* NewLens;
  NewLens = new CLens;

  if( ChangeLensProperties( NewLens ))
  {
    MainOptList.AddElement();
    MainOptList.SetElement( ( COptObject* )NewLens );
    
    if( m_IsObjDlgActive )
      m_ObjDlg.AddObject( NewLens );
  }
  else
    delete NewLens;

  Invalidate();
}

void COptoView::OnCreateLightblock() 
{
  CLightBlock* NewLightBlock;
  NewLightBlock = new CLightBlock;

  if( ChangeLBlockProperties( NewLightBlock ))
  {
    MainOptList.AddElement();
    MainOptList.SetElement( ( COptObject* )NewLightBlock );

    if( m_IsObjDlgActive )
      m_ObjDlg.AddObject( NewLightBlock );
  }
  else
    delete NewLightBlock;

  Invalidate();
}


void COptoView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
  CPoint point1;
  point1.x= int(( point.x + GetScrollPos( SB_HORZ )) / GraphParams.m_Zoom );
  point1.y= int(( point.y + GetScrollPos( SB_VERT )) / GraphParams.m_Zoom );
  
  COptObject* ClickedObject;
  ClickedObject = CheckWhatIsClicked( &point1, m_ClickAccuracy );

  if( ClickedObject )
  {
    if( nFlags & MK_CONTROL )
    {
      CString TempStr;
      
      if( ClickedObject->m_Name.IsEmpty() )
        TempStr.Format( "Remove object?" );
      else
        TempStr.Format( "Remove object \"%s\"?", ClickedObject->m_Name );
      
      if( AfxMessageBox( TempStr, 1, 0 ) == IDOK )
      {
        if( GetOptObjectType( ClickedObject ) == T_LIGHTSOURCE )
        {
          if( ( COptObject* )m_AnimationLightSource == ClickedObject )
            m_AnimationLightSource = NULL;
          
          ValidateLightSegments( ( CLightSource* )( LPVOID( ClickedObject )) );
        }

        if( m_IsObjDlgActive )
          m_ObjDlg.DeleteObject( ClickedObject );

        MainOptList.RemoveCurrentElement();
      }
    }
    else
    {
      switch( GetOptObjectType( ClickedObject ) )
      {
        case T_FLATMIRROR: 
          ChangeFMirrorProperties( ClickedObject );
          break;

        case T_LENS:
          ChangeLensProperties( ClickedObject );
          break;

        case T_LIGHTBLOCK:
          ChangeLBlockProperties( ClickedObject );
          break;

        case T_LIGHTSOURCE:
          ChangeLSourceProperties( ClickedObject );
      }

      m_ObjDlg.UpdateObject( ClickedObject );
    }
  }

  Invalidate();
  CScrollView::OnLButtonDblClk(nFlags, point);
}

void COptoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
  CPoint point1;
  point1.x= int(( point.x + GetScrollPos( SB_HORZ )) / GraphParams.m_Zoom );
  point1.y= int(( point.y + GetScrollPos( SB_VERT )) / GraphParams.m_Zoom );
  COptObject* TempObject;
  TempObject = CheckWhatIsClicked( &point1, m_ClickAccuracy );

  if( !m_LSSelectFlag )
  {
    m_ActiveObject = TempObject;
    
    if( nFlags & MK_CONTROL )
      m_MouseFlags = 1;
    
    if( nFlags & MK_SHIFT )
      m_MouseFlags = 2;

    if( m_ActiveObject )
    {
      if( !m_MouseFlags )
        m_PrevCoords = point1;
      else
        m_PrevCoords = point;
    }
  }
  else 
    if( TempObject && GetOptObjectType( TempObject ) == T_LIGHTSOURCE )
      switch( m_LSSelectFlag )
      {
        case 1: 
          m_AnimationLightSource = ( CLightSource* )( ( LPVOID )( TempObject ));
          m_LSSelectFlag = 0;
          break;

        case 2:
          m_SelectedLightSource = ( CLightSource* )( ( LPVOID )( TempObject ));
          m_LSSelectFlag = 3;
          break;

        case 3:
          CLightSegment* LSegment;
          LSegment = new CLightSegment;
          LSegment->Create( m_SelectedLightSource, ( CLightSource* )( ( LPVOID )( TempObject )) );
          MainOptList.GoToEnd();
          MainOptList.AddElement();
          MainOptList.SetElement( ( COptObject* )LSegment );
          m_LSSelectFlag = 0;
          Invalidate();
      }
  
  SelectedObject = NULL;
  
  if( m_IsObjDlgActive )
  {
    if( TempObject )
      m_ObjDlg.m_ObjList.SetCurSel( GetObjectNumber( TempObject ) );

    Invalidate();  
  }

  CScrollView::OnLButtonDown(nFlags, point);
}

void COptoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
  m_ActiveObject = NULL;
  m_MouseFlags = 0;
	CScrollView::OnLButtonUp(nFlags, point);
}

void COptoView::OnMouseMove(UINT nFlags, CPoint point) 
{
  CPoint point1;
  point1.x= int(( point.x + GetScrollPos( SB_HORZ )) / GraphParams.m_Zoom );
  point1.y= int(( point.y + GetScrollPos( SB_VERT )) / GraphParams.m_Zoom );
  
  CString StatusString;
  CMainFrame* pMainFrm;
  pMainFrm = ( CMainFrame* )AfxGetApp()->m_pMainWnd;
  CStatusBar* pStatusBar = &( pMainFrm->m_wndStatusBar );
  
  if( m_ActiveObject )
  {  
    switch( m_MouseFlags )
    {
      case 0: 
        m_ActiveObject->ParallelMove( point1.x - m_PrevCoords.x, point1.y - m_PrevCoords.y );
        m_PrevCoords = point1;
        StatusString.Format( "X: %d  Y: %d", point1.x, point1.y );
        pStatusBar->SetPaneText( 1, StatusString );
        break; 
             
      case 1: 
        m_ActiveObject->Rotate( ( point.x - m_PrevCoords.x ) / 50.0 );
        m_PrevCoords = point;
        StatusString.Format( "%s", LogString );
        pStatusBar->SetPaneText( 1, StatusString );
        break;

      case 2: 
        m_ActiveObject->ChangeSize( point.x - m_PrevCoords.x );
        m_PrevCoords = point;
        StatusString.Format( "%s", LogString );
        pStatusBar->SetPaneText( 1, StatusString );
    }
    Invalidate();
  }
  else
  {
    StatusString.Format( "X: %d  Y: %d", point1.x, point1.y );
    pStatusBar->SetPaneText( 1, StatusString );
  }
	
  CScrollView::OnMouseMove(nFlags, point);
}

void COptoView::OnFileNew() 
{
  MainOptList.Clear();
  Invalidate();
  m_CurrentFileName.Format("");
  m_AnimationLightSource = NULL;

  if( m_IsObjDlgActive )
    m_ObjDlg.UpdateList();
}

void COptoView::OnProperties() 
{
  CGeneralPropertiesDlg GPDlg;
  GPDlg.m_DrawShadow = m_DrawShadow;
  GPDlg.m_ClickAccuracy = m_ClickAccuracy;
  GPDlg.m_AnimFrequency = m_AnimationFrequency;
  GPDlg.m_ShowRayArrows = GraphParams.m_DrawRayArrows;
  GPDlg.m_ShowILS = GraphParams.m_DrawILS;
  GPDlg.m_SelectILS = GraphParams.m_SelectILS;

  if( GPDlg.DoModal() == IDOK )
  {
    m_DrawShadow = GPDlg.m_DrawShadow;
    m_ClickAccuracy = GPDlg.m_ClickAccuracy;
    m_AnimationFrequency = GPDlg.m_AnimFrequency;
    GraphParams.m_DrawRayArrows = GPDlg.m_ShowRayArrows;
    GraphParams.m_DrawILS = GPDlg.m_ShowILS;
    GraphParams.m_SelectILS = GPDlg.m_SelectILS;
    Invalidate();
  }
}

void COptoView::OnCreateLightsource() 
{
	CLightSource* NewLightSource;
  NewLightSource = new CLightSource;

  if( ChangeLSourceProperties( NewLightSource ))
  {
    MainOptList.AddElement();
    MainOptList.SetElement( ( COptObject* )NewLightSource );
    m_ObjDlg.AddObject( NewLightSource );
  }
  else
    delete NewLightSource;

  Invalidate();
}

void COptoView::OnSaveColorscheme() 
{
  CFileDialog FileDlg( FALSE );
  
  if( FileDlg.DoModal() == IDOK )
  {
    CString FileName;
    FileName = FileDlg.GetPathName();
    CFile File( FileName, CFile::modeCreate | CFile::modeWrite );    
    CArchive Archive( &File, CArchive::store );
    GraphParams.SerializeStyles( Archive );
    Archive.Close();
    File.Close();
  }
}

void COptoView::OnLoadColorscheme() 
{
  CFileDialog FileDlg( TRUE );
  
  if( FileDlg.DoModal() == IDOK )
  {
    CString FileName;
    FileName = FileDlg.GetPathName();
    CFile File( FileName, CFile::modeRead );
    CArchive Archive( &File, CArchive::load );
    GraphParams.SerializeStyles( Archive );
    Archive.Close();
    File.Close();
    Invalidate();
  }
}

void COptoView::OnAnimationStart() 
{
  if( AnimationFlag == 3 )
    AnimationFlag = 1;
  else
  {
    AnimationFlag = 2;
    Invalidate( FALSE );
  }

  SetTimer( 1, 1000 / m_AnimationFrequency, NULL );
}

void COptoView::OnAnimationStop() 
{
  AnimationFlag = 0;
  ResetAnimator();
  KillTimer( 1 );
  Invalidate();
}

void COptoView::OnTimer(UINT nIDEvent) 
{
  Invalidate( FALSE );
  CScrollView::OnTimer(nIDEvent);
}

void COptoView::OnOptimize() 
{
  COptimizeDlg Dlg;
  Dlg.m_Left = 5;
  Dlg.m_Top = 5;

  if( Dlg.DoModal() == IDOK )
  {  
    OptimizeSystemLocation( Dlg.m_Left, Dlg.m_Top );
    Invalidate();
  }
}

void COptoView::OnAnimationPause() 
{
  if( AnimationFlag == 1 )
  {
    KillTimer( 1 );
    AnimationFlag = 3;
  }
}

void COptoView::OnZoomFit() 
{
  GraphParams.m_Zoom = -1;
  Invalidate();
}

void COptoView::OnUpdateAnimationStart(CCmdUI* pCmdUI) 
{
  pCmdUI->Enable( ( AnimationFlag != 2 ) && m_AnimationLightSource );
  
  if( AnimationFlag == 1 )
    pCmdUI->SetCheck( TRUE );
  else
    pCmdUI->SetCheck( FALSE );
}

void COptoView::OnUpdateAnimationStop(CCmdUI* pCmdUI) 
{
  pCmdUI->Enable( AnimationFlag != 0 );
}

void COptoView::OnUpdateAnimationPause(CCmdUI* pCmdUI) 
{
  if( AnimationFlag )
  {
    pCmdUI->Enable( TRUE );

    if( AnimationFlag == 3 )
      pCmdUI->SetCheck( TRUE );
  }
  else
    pCmdUI->Enable( FALSE );

  if( AnimationFlag != 3 )
  pCmdUI->SetCheck( FALSE );
}

void COptoView::OnUpdateZoomDecrease(CCmdUI* pCmdUI) 
{
  pCmdUI->Enable( MainOptList.GetNumOfElements() != 0 );
}

void COptoView::OnUpdateZoomFit(CCmdUI* pCmdUI) 
{
  pCmdUI->Enable( MainOptList.GetNumOfElements() != 0 );
}

void COptoView::OnUpdateZoomIncrease(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( MainOptList.GetNumOfElements() != 0 );
}

void COptoView::OnCreateLightsegment() 
{
  if( !m_LSSelectFlag ) 
    m_LSSelectFlag = 2;
  else if( m_LSSelectFlag > 1 ) 
    m_LSSelectFlag = 0;
}

void COptoView::OnSelectAnimls() 
{
  if( !m_LSSelectFlag ) m_LSSelectFlag = 1;	
}

void COptoView::OnUpdateCreateLightsegment(CCmdUI* pCmdUI) 
{
  pCmdUI->SetCheck( m_LSSelectFlag > 1 );	
}

void COptoView::OnHideRays() 
{
  GraphParams.m_ShowRays = !GraphParams.m_ShowRays;	
  Invalidate();
}

void COptoView::OnUpdateHideRays(CCmdUI* pCmdUI) 
{
	if( GraphParams.m_ShowRays )
    pCmdUI->SetCheck( FALSE );
  else
    pCmdUI->SetCheck( TRUE );
}

void COptoView::OnUpdateSelectAnimls(CCmdUI* pCmdUI) 
{
  if( m_LSSelectFlag == 1 )
    pCmdUI->SetCheck( TRUE );
  else
    pCmdUI->SetCheck( FALSE );
}

void COptoView::OnShowObjdlg() 
{
  if( m_IsObjDlgActive )
  {
    m_ObjDlg.DestroyWindow();
    SelectedObject = NULL;
  }
  else
  {
    m_ObjDlg.Create( IDD_SETPRIORITY );
    m_ObjDlg.UpdateList();
  }
  
  m_IsObjDlgActive = !m_IsObjDlgActive;
}

void COptoView::OnUpdateShowObjdlg(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_IsObjDlgActive );
}

void COptoView::OnFileOpen() 
{
  CFileDialog FileDlg( TRUE );
  
  if( FileDlg.DoModal() == IDOK )
  {
    CString FileName;
    FileName = FileDlg.GetPathName();
    CFile File( FileName, CFile::modeRead );    
    CArchive Archive( &File, CArchive::load );
    SerializeScene( Archive );
    Archive.Close();
    File.Close();
    Invalidate();
    m_CurrentFileName = FileName;
    m_AnimationLightSource = NULL;
    
    if( m_IsObjDlgActive )
      m_ObjDlg.UpdateList();
  }
}


void COptoView::OnFileSave() 
{
  if( m_CurrentFileName.IsEmpty() )
    OnFileSaveAs();
  else
  {
    CFile File( m_CurrentFileName, CFile::modeCreate | CFile::modeWrite );    
    CArchive Archive( &File, CArchive::store );
    SerializeScene( Archive );
    Archive.Close();
    File.Close();
  }
}

void COptoView::OnFileSaveAs() 
{
  CFileDialog FileDlg( FALSE );
  
  if( FileDlg.DoModal() == IDOK )
  {
    CString FileName;
    FileName = FileDlg.GetPathName();
    CFile File( FileName, CFile::modeCreate | CFile::modeWrite );    
    CArchive Archive( &File, CArchive::store );
    SerializeScene( Archive );
    Archive.Close();
    File.Close();
    m_CurrentFileName = FileName;
  }
}