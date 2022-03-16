#include <stdafx.h>
#include "clens.h"
#include "globals.h"

//////////////////////////////////////////////////////////////////////////////
//CLens class member functions:
//////////////////////////////////////////////////////////////////////////////
CLens::CLens( void )
{
  m_Lens.Create( 0, 0, 0, 0 );
  m_FocalDistance = 0;
  m_ShowMainOpticAxis = 0;
  m_ShowFocalPlanes = 0;
}
//////////////////////////////////////////////////////////////////////////////
void CLens::Create( int x, int y1, int y2, int NewFD )
{
  m_Lens.m_x1 = x;
  m_Lens.m_x2 = x;
  m_Lens.m_y1 = Min( y1, y2 );
  m_Lens.m_y2 = Max( y1, y2 );
  m_ObjectRegion.left = x;
  m_ObjectRegion.right = x;
  m_ObjectRegion.top = y1;
  m_ObjectRegion.bottom = y2;
  m_FocalDistance = NewFD;
}
//////////////////////////////////////////////////////////////////////////////
void CLens::Draw( void )
{
  if( m_FocalDistance > 0 )
  {
    GraphParams.SetStyle( GS_CONVERGINGLENS );
    DrawArrow( m_Lens.m_x1, m_Lens.m_y1, m_Lens.m_x2, m_Lens.m_y2, 7, M_PI / 6, FALSE );
    DrawArrow( m_Lens.m_x2, m_Lens.m_y2, m_Lens.m_x1, m_Lens.m_y1, 7, M_PI / 6, FALSE );
  }
  else
  {
    GraphParams.SetStyle( GS_DIVERGINGLENS );
    DrawArrow( m_Lens.m_x2, m_Lens.m_y2 + 1, m_Lens.m_x2, m_Lens.m_y2, 7, M_PI / 6, FALSE );
    DrawArrow( m_Lens.m_x1, m_Lens.m_y1 - 1, m_Lens.m_x1, m_Lens.m_y1, 7, M_PI / 6, FALSE );
  }
  m_Lens.Draw();
  GraphParams.RestorePen();

  if( !GraphParams.m_ShadowMode )
  {
    if( m_ShowFocalPlanes )
    {
      GraphParams.SetStyle( GS_FOCALPLANES );
      DrawLine( m_Lens.m_x1 + m_FocalDistance, 0, m_Lens.m_x1 + m_FocalDistance, 2000 );
      DrawLine( m_Lens.m_x1 - m_FocalDistance, 0, m_Lens.m_x1 - m_FocalDistance, 2000 );
      GraphParams.RestorePen();
    }

    if( m_ShowMainOpticAxis )
    {
      CPoint NewPoint = m_Lens.GetMiddlePoint();
      GraphParams.SetStyle( GS_MOA );
      DrawLine( 0, NewPoint.y, 2000, NewPoint.y );
      GraphParams.RestorePen();
    }
  }
}
//////////////////////////////////////////////////////////////////////////////
CPoint CLens::GetIntersectPoint( void )
{
  CPoint NewPoint;
  CLine LensLine;
  LensLine = m_Lens.GetParentLine();
  NewPoint = LineIntersect( &LensLine, &CurrentRay );

  if( NewPoint.x != -1000 && NewPoint.y > Min( m_Lens.m_y1, m_Lens.m_y2 ) 
    && NewPoint.y < Max( m_Lens.m_y1, m_Lens.m_y2 ) && 
    ( CurrentRay.m_Direction - ( NewPoint.x > CurrentLSPosition.x )))
    return NewPoint;

  NewPoint.x = -1000;
  return NewPoint;
}
//////////////////////////////////////////////////////////////////////////////
void CLens::CalculateRay( void )
{
  CPoint NewPoint;
  NewPoint.x = m_Lens.m_x1;
  NewPoint.y = CurrentRay.Gety( m_Lens.m_x1 );
  CLine TempLine;
  TempLine.m_k = CurrentRay.m_k;
  TempLine.m_b = CurrentRay.m_b + ( m_Lens.m_y1 + m_Lens.m_y2 ) / 2 - NewPoint.y;
  CPoint TempPoint;
  
  if( CurrentRay.m_Direction == DIR_LR )
  {
    TempPoint.x = m_Lens.m_x1 + m_FocalDistance;
    TempPoint.y = TempLine.Gety( TempPoint.x );
  }
  else
  {
    TempPoint.x = m_Lens.m_x1 - m_FocalDistance;
    TempPoint.y = TempLine.Gety( TempPoint.x );
  }

  if( m_FocalDistance > 0 ) 
    CurrentRay.Create( NewPoint.x, NewPoint.y, TempPoint.x, TempPoint.y );
  else
    CurrentRay.Create( TempPoint.x, TempPoint.y, NewPoint.x, NewPoint.y );

  OldLSPosition = CurrentLSPosition;
  CurrentLSPosition = NewPoint;

  if( GraphParams.m_DrawILS && !AnimationFlag )
  {
    if( m_FocalDistance > 0 )
      ILSIsImgFlag = abs( ILSPosition.x - m_Lens.m_x1 ) <= m_FocalDistance;
    else
      ILSIsImgFlag = TRUE;

    CLine TempLine2;
    TempLine.Create( ILSPosition.x, ILSPosition.y, m_Lens.m_x1, m_Lens.m_y1 );
    TempLine.m_b += ( m_Lens.m_y2 - m_Lens.m_y1 ) / 2;
    TempLine2.m_IsOrtogonal = TRUE;
    
    if( CurrentRay.m_Direction == DIR_LR )
      TempLine2.m_b = m_Lens.m_x1 + m_FocalDistance;
    else
      TempLine2.m_b = m_Lens.m_x1 - m_FocalDistance;

    TempPoint = LineIntersect( &TempLine, &TempLine2 );
    TempLine.Create( m_Lens.m_x1, m_Lens.m_y1, TempPoint.x, TempPoint.y );
    TempLine2.Create( ILSPosition.x, ILSPosition.y, 
                         m_Lens.m_x1, ( m_Lens.m_y1 + m_Lens.m_y2 ) / 2 );
    ILSPosition = LineIntersect( &TempLine, &TempLine2 );
    
    if( GraphParams.m_ILSSelectionMode )
      GraphParams.SetStyle( PS_SOLID, 2, GraphParams.m_SelectionColor );
    else
      GraphParams.SetStyle( PS_SOLID, 2, GraphParams.m_ILSColor );

    GlobalDC->Ellipse( ILSPosition.x - 2, ILSPosition.y - 2, ILSPosition.x + 2, ILSPosition.y + 2 );
    GraphParams.RestorePen();
  }
}
//////////////////////////////////////////////////////////////////////////////
BOOL CLens::IsClicked( CPoint* ClickPoint, int Accuracy )
{
  return m_Lens.IsOnSegment( ClickPoint, Accuracy );
}
//////////////////////////////////////////////////////////////////////////////
void CLens::ParallelMove( int x, int y )
{
  m_ObjectRegion.left += x;
  m_ObjectRegion.right += x;
  m_ObjectRegion.top += y;
  m_ObjectRegion.bottom += y;
  m_Lens.m_x1 += x;
  m_Lens.m_x2 += x;
  m_Lens.m_y1 += y;
  m_Lens.m_y2 += y;
}
//////////////////////////////////////////////////////////////////////////////
void CLens::Rotate( double Angle )
{
  m_FocalDistance += 50 * Angle;
  
  if( m_Name.IsEmpty() )
    LogString.Format( "Фокусное расстояние линзы: %d", m_FocalDistance );
  else
    LogString.Format( "Фокусное расстояние линзы \"%s\": %d", m_Name, m_FocalDistance );
}
//////////////////////////////////////////////////////////////////////////////
void CLens::ChangeSize( int DeltaSize )
{
  if( m_Lens.m_y1 > m_Lens.m_y2 )
    DeltaSize *= -1;
  
  m_Lens.m_y1 += DeltaSize;
  m_Lens.m_y2 -= DeltaSize;
  m_ObjectRegion.top = m_Lens.m_y1;
  m_ObjectRegion.bottom = m_Lens.m_y2;
  
  if( m_Name.IsEmpty() )
    LogString.Format( "Размер линзы: %d", m_Lens.m_y2 - m_Lens.m_y1 );
  else
    LogString.Format( "Размер линзы \"%s\": %d", m_Name, m_Lens.m_y2 - m_Lens.m_y1 );
}
//////////////////////////////////////////////////////////////////////////////
void CLens::Serialize( CArchive& Ar )
{
  if( Ar.IsStoring() )
  {
    Ar << T_LENS;
    Ar << m_Name;
    Ar << m_Lens.m_x1;
    Ar << m_Lens.m_y1;
    Ar << m_Lens.m_y2;  
    Ar << m_FocalDistance;
    Ar << m_ShowMainOpticAxis;
    Ar << m_ShowFocalPlanes;
  }
  else
  {
    Ar >> m_Name;
    Ar >> m_Lens.m_x1;
    Ar >> m_Lens.m_y1;
    Ar >> m_Lens.m_y2;  
    Ar >> m_FocalDistance;
    Ar >> m_ShowMainOpticAxis;
    Ar >> m_ShowFocalPlanes;
    m_Lens.m_x2 = m_Lens.m_x1;
    m_ObjectRegion.left = m_Lens.m_x1;
    m_ObjectRegion.right = m_Lens.m_x1;
    m_ObjectRegion.top = m_Lens.m_y1;
    m_ObjectRegion.bottom = m_Lens.m_y2;
  }
}