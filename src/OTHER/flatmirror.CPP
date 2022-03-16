#include <stdafx.h>
#include "globals.h"
#include "cflatmirror.h"

//////////////////////////////////////////////////////////////////////////////
//CFlatMirror class member functions:
//////////////////////////////////////////////////////////////////////////////
CFlatMirror::CFlatMirror( void )
{
  m_FlatMirror.Create( 0, 0, 0, 0 );
}
//////////////////////////////////////////////////////////////////////////////
void CFlatMirror::Create( int x1, int y1, int x2, int y2 )
{
  m_ObjectRegion.left = Min( x1, x2 );
  m_ObjectRegion.right = Max( x1, x2 );
  m_ObjectRegion.top = Min( y1, y2 );
  m_ObjectRegion.bottom = Max( y1, y2 );
  m_FlatMirror.Create( x1, y1, x2, y2 );
  m_MirrorLine.Create( x1, y1, x2, y2 );
}
//////////////////////////////////////////////////////////////////////////////
void CFlatMirror::Draw( void )
{
  GraphParams.SetStyle( GS_FLATMIRROR );
  m_FlatMirror.Draw();
  GraphParams.RestorePen();
}
//////////////////////////////////////////////////////////////////////////////
CPoint CFlatMirror::GetIntersectPoint( void )
{
  CPoint NewPoint;
  CLine MirrorLine;
  MirrorLine = m_FlatMirror.GetParentLine();
  NewPoint = LineIntersect( &MirrorLine, &CurrentRay );
  
  if( IsInRect( &NewPoint, &m_ObjectRegion ) && 
      IsValidDirection( &CurrentLSPosition, &NewPoint ))
    return NewPoint;

  NewPoint.x = -1000;
  return NewPoint;
}
//////////////////////////////////////////////////////////////////////////////
void CFlatMirror::CalculateRay( void )
{
  CPoint NewPoint;
  CPoint Reflection;
  NewPoint = LineIntersect( &m_MirrorLine, &CurrentRay );
  Reflection = GetSymmetricPoint( &CurrentLSPosition, &m_MirrorLine );
  CurrentRay.Create( Reflection.x, Reflection.y, NewPoint.x, NewPoint.y );
  OldLSPosition = CurrentLSPosition;
  CurrentLSPosition = NewPoint;

  if( GraphParams.m_DrawILS && !AnimationFlag )
  {
    ILSIsImgFlag = TRUE;
    ILSPosition = GetSymmetricPoint( &ILSPosition, &m_MirrorLine );
    
    if( GraphParams.m_ILSSelectionMode )
      GraphParams.SetGlobalColor( GraphParams.m_SelectionColor );

    GraphParams.SetStyle( PS_SOLID, 2, GraphParams.m_ILSColor );
    GlobalDC->Ellipse( ILSPosition.x - 2, ILSPosition.y - 2, ILSPosition.x + 2, ILSPosition.y + 2 );
    GraphParams.RestorePen();
    
    if( GraphParams.m_ShowRays )
    {
      GraphParams.SetStyle( PS_DASH, 1, GraphParams.m_ILSColor );
      DrawLine( NewPoint.x, NewPoint.y, ILSPosition.x, ILSPosition.y );
      GraphParams.RestorePen();
    }

    if( GraphParams.m_ILSSelectionMode )
      GraphParams.RestoreColors();
  }
}
//////////////////////////////////////////////////////////////////////////////
BOOL CFlatMirror::IsClicked( CPoint* ClickPoint, int Accuracy )
{
  return m_FlatMirror.IsOnSegment( ClickPoint, Accuracy );
}
//////////////////////////////////////////////////////////////////////////////
void CFlatMirror::ParallelMove( int x, int y )
{
  m_ObjectRegion.left += x;
  m_ObjectRegion.right += x;
  m_ObjectRegion.top += y;
  m_ObjectRegion.bottom += y;
  m_FlatMirror.m_x1 += x;
  m_FlatMirror.m_x2 += x;
  m_FlatMirror.m_y1 += y;
  m_FlatMirror.m_y2 += y;
  m_MirrorLine.Create( m_FlatMirror.m_x1, m_FlatMirror.m_y1, m_FlatMirror.m_x2, m_FlatMirror.m_y2 );
}
//////////////////////////////////////////////////////////////////////////////
void CFlatMirror::Rotate( double Angle )
{
  m_FlatMirror.RotateByCenter( Angle );
  m_MirrorLine.Create( m_FlatMirror.m_x1, m_FlatMirror.m_y1, m_FlatMirror.m_x2, m_FlatMirror.m_y2 );
  m_ObjectRegion.left = Min( m_FlatMirror.m_x1, m_FlatMirror.m_x2 );
  m_ObjectRegion.right = Max( m_FlatMirror.m_x1, m_FlatMirror.m_x2 );
  m_ObjectRegion.top = Min( m_FlatMirror.m_y1, m_FlatMirror.m_y2 );
  m_ObjectRegion.bottom = Max( m_FlatMirror.m_y1, m_FlatMirror.m_y2 );
  
  if( m_Name.IsEmpty() )
    LogString.Format( "Mirror rotation" );
  else
    LogString.Format( "Mirror rotation \"%s\"", m_Name );
}
//////////////////////////////////////////////////////////////////////////////
void CFlatMirror::ChangeSize( int DeltaSize )
{
  m_FlatMirror.ChangeSize( DeltaSize, &m_MirrorLine );
  m_ObjectRegion.left = Min( m_FlatMirror.m_x1, m_FlatMirror.m_x2 );
  m_ObjectRegion.right = Max( m_FlatMirror.m_x1, m_FlatMirror.m_x2 );
  m_ObjectRegion.top = Min( m_FlatMirror.m_y1, m_FlatMirror.m_y2 );
  m_ObjectRegion.bottom = Max( m_FlatMirror.m_y1, m_FlatMirror.m_y2 );
  
  if( m_Name.IsEmpty() )
    LogString.Format( "Mirror size: %d", 
    ( int )GetDistance( m_FlatMirror.m_x1, m_FlatMirror.m_y1, m_FlatMirror.m_x2, m_FlatMirror.m_y2 ));
  else
    LogString.Format( "Mirror size \"%s\": %d", m_Name, 
    ( int )GetDistance( m_FlatMirror.m_x1, m_FlatMirror.m_y1, m_FlatMirror.m_x2, m_FlatMirror.m_y2 ));
}
//////////////////////////////////////////////////////////////////////////////
void CFlatMirror::Serialize( CArchive& Ar )
{
  if( Ar.IsStoring() )
  {
    Ar << T_FLATMIRROR;
    Ar << m_Name;
    Ar << m_FlatMirror.m_x1;
    Ar << m_FlatMirror.m_y1;
    Ar << m_FlatMirror.m_x2;
    Ar << m_FlatMirror.m_y2;
  }
  else
  {
    Ar >> m_Name;
    Ar >> m_FlatMirror.m_x1;
    Ar >> m_FlatMirror.m_y1;
    Ar >> m_FlatMirror.m_x2;
    Ar >> m_FlatMirror.m_y2;
    Create( m_FlatMirror.m_x1, m_FlatMirror.m_y1, m_FlatMirror.m_x2, m_FlatMirror.m_y2 );
  }
}