#include <stdafx.h>
#include "cgfxparamst.h"
#include "optenums.h"
#include "globals.h"

//////////////////////////////////////////////////////////////////////////////
//CGraphicsParamStorage class member functions:
//////////////////////////////////////////////////////////////////////////////
CGraphicsParamStorage::CGraphicsParamStorage( void )
{
  m_ColorArray[GS_LIGHTSOURCE] = RGB( 255, 200, 0 );
  m_ColorArray[GS_RAY] = RGB( 255, 200, 0 );
  m_ColorArray[GS_RAYARROWS] = RGB( 200, 200, 0 );
  m_ColorArray[GS_LIGHTBLOCK] = RGB( 0, 0, 0 );
  m_ColorArray[GS_FLATMIRROR] = RGB( 0, 200, 255 );
  m_ColorArray[GS_SPHERICALMIRROR] = RGB( 0, 200, 0 );
  m_ColorArray[GS_CONVERGINGLENS] = RGB( 0, 230, 0 );
  m_ColorArray[GS_DIVERGINGLENS] = RGB( 0, 230, 0 );
  m_ColorArray[GS_FOCALPLANES] = RGB( 0, 220, 0 );
  m_ColorArray[GS_MOA] = RGB( 0, 220, 0 );
  m_ColorArray[GS_LIGHTSEGMENT] = RGB( 190, 190, 190 );

  for( int i = 0; i < 8; i++ )
  {
    m_WidthArray[i] = 2;
    m_StyleArray[i] = PS_SOLID;
  }
  
  m_WidthArray[GS_RAY] = 1;
  m_WidthArray[GS_RAYARROWS] = 1;
  m_WidthArray[GS_FOCALPLANES] = 1;
  m_WidthArray[GS_MOA] = 1;
  m_WidthArray[GS_LIGHTSEGMENT] = 1;
  
  m_StyleArray[GS_FOCALPLANES] = PS_DASH;
  m_StyleArray[GS_MOA] = PS_DASHDOT;

  m_UseGlobalColor = FALSE;
  m_ShowRays = TRUE;
  m_ILSColor = RGB( 225, 225, 225 );
  m_SelectionColor = RGB( 200, 0, 0 );
}//CGraphicsParamStorage
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::SetStyle( int Object )
{
  CPen* pPen;
  pPen = new CPen;

  if( m_UseGlobalColor )
    pPen->CreatePen( m_StyleArray[Object], m_WidthArray[Object], m_GlobalColor );
  else
    pPen->CreatePen( m_StyleArray[Object], m_WidthArray[Object], m_ColorArray[Object] );
  
  m_TempPen = GlobalDC->SelectObject( pPen );
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::SetStyle( int Style, int Width, COLORREF Color )
{
  CPen* pPen;
  pPen = new CPen;

  if( m_UseGlobalColor )
    pPen->CreatePen( Style, Width, m_GlobalColor );
  else
    pPen->CreatePen( Style, Width, Color );

  m_TempPen = GlobalDC->SelectObject( pPen );
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::RestorePen( void )
{
  delete ( GlobalDC->SelectObject( m_TempPen ) );
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::SetGlobalColor( COLORREF Color )
{
  m_GlobalColor = Color;
  m_UseGlobalColor = TRUE;
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::SetColor( int Object, COLORREF Color )
{
  m_ColorArray[Object] = Color;
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::RestoreColors( void )
{
  m_UseGlobalColor = FALSE;
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::SetScreenLimits( int x1, int y1, int x2, int y2 )
{
  m_ScreenLimits[0].Create( x1, y1, x2 + 5, y1 );
  m_ScreenLimits[1].Create( x1, y1, x1, y2 );
  m_ScreenLimits[2].Create( x2, y1, x2, y2 );
  m_ScreenLimits[3].Create( x1, y2, x2, y2 );
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::SetObjectColor( int Object )
{
  CColorDialog ColorDlg;
  
  if( ColorDlg.DoModal() == IDOK )
    m_ColorArray[Object] = ColorDlg.GetColor();
}
//////////////////////////////////////////////////////////////////////////////
void CGraphicsParamStorage::SerializeStyles( CArchive& Ar )
{
  int i;
  
  if( Ar.IsStoring() )
  {
    for( i = 0; i < 11; i++ )
    {
      Ar << m_ColorArray[i];
      Ar << m_WidthArray[i];
      Ar << m_StyleArray[i];
    }
    
    Ar << m_ILSColor;
    Ar << m_SelectionColor;
  }
  else
  {
    for( i = 0; i < 11; i++ )
    {
      Ar >> m_ColorArray[i];
      Ar >> m_WidthArray[i];
      Ar >> m_StyleArray[i];
    }

    Ar >> m_ILSColor;
    Ar >> m_SelectionColor;
  }
}