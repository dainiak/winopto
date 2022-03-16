#include <stdafx.h>
#include "clightblock.h"
#include "globals.h"

//////////////////////////////////////////////////////////////////////////////
//CLightBlock class member functions:
//////////////////////////////////////////////////////////////////////////////
CLightBlock::CLightBlock( void )
{
  m_Block.Create( 0, 0, 0, 0 );
}
//////////////////////////////////////////////////////////////////////////////
void CLightBlock::Create( int x1, int y1, int x2, int y2 )
{
  m_ObjectRegion.left = Min( x1, x2 );
  m_ObjectRegion.right = Max( x1, x2 );
  m_ObjectRegion.top = Min( y1, y2 );
  m_ObjectRegion.bottom = Max( y1, y2 );
  m_Block.Create( x1, y1, x2, y2 );
  m_BlockLine.Create( x1, y1, x2, y2 );
}
//////////////////////////////////////////////////////////////////////////////
void CLightBlock::Draw( void )
{
  GraphParams.SetStyle( GS_LIGHTBLOCK );
  m_Block.Draw();
  GraphParams.RestorePen();
}
//////////////////////////////////////////////////////////////////////////////
CPoint CLightBlock::GetIntersectPoint( void )
{
  CPoint NewPoint;
  NewPoint = LineIntersect( &m_BlockLine, &CurrentRay );
  
  if( IsInRect( &NewPoint, &m_ObjectRegion ) && 
      IsValidDirection( &CurrentLSPosition, &NewPoint ))
    return NewPoint;

  NewPoint.x = -1000;
  return NewPoint;
}
//////////////////////////////////////////////////////////////////////////////
void CLightBlock::CalculateRay( void )
{
  OldLSPosition = CurrentLSPosition;
  CurrentLSPosition = LineIntersect( &m_BlockLine, &CurrentRay );
  CurrentRay.m_RFlag = 0;
}
//////////////////////////////////////////////////////////////////////////////
BOOL CLightBlock::IsClicked( CPoint* ClickPoint, int Accuracy )
{
  return m_Block.IsOnSegment( ClickPoint, Accuracy );
}
//////////////////////////////////////////////////////////////////////////////
void CLightBlock::ParallelMove( int x, int y )
{
  m_ObjectRegion.left += x;
  m_ObjectRegion.right += x;
  m_ObjectRegion.top += y;
  m_ObjectRegion.bottom += y;
  m_Block.m_x1 += x;
  m_Block.m_x2 += x;
  m_Block.m_y1 += y;
  m_Block.m_y2 += y;
  m_BlockLine.Create( m_Block.m_x1, m_Block.m_y1, m_Block.m_x2, m_Block.m_y2 );
}
//////////////////////////////////////////////////////////////////////////////
void CLightBlock::Rotate( double Angle )
{
  m_Block.RotateByCenter( Angle );
  m_BlockLine.Create( m_Block.m_x1, m_Block.m_y1, m_Block.m_x2, m_Block.m_y2 );
  m_ObjectRegion.left = Min( m_Block.m_x1, m_Block.m_x2 );
  m_ObjectRegion.right = Max( m_Block.m_x1, m_Block.m_x2 );
  m_ObjectRegion.top = Min( m_Block.m_y1, m_Block.m_y2 );
  m_ObjectRegion.bottom = Max( m_Block.m_y1, m_Block.m_y2 );
  
  if( m_Name.IsEmpty() )
    LogString.Format( "Поворот ширмы" );
  else
    LogString.Format( "Поворот ширмы \"%s\"", m_Name );
}
//////////////////////////////////////////////////////////////////////////////
void CLightBlock::ChangeSize( int DeltaSize )
{
  m_Block.ChangeSize( DeltaSize, &m_BlockLine );
  m_ObjectRegion.left = Min( m_Block.m_x1, m_Block.m_x2 );
  m_ObjectRegion.right = Max( m_Block.m_x1, m_Block.m_x2 );
  m_ObjectRegion.top = Min( m_Block.m_y1, m_Block.m_y2 );
  m_ObjectRegion.bottom = Max( m_Block.m_y1, m_Block.m_y2 );
  
  if( m_Name.IsEmpty() )
    LogString.Format( "Размер ширмы: %d", 
               ( int )GetDistance( m_Block.m_x1, m_Block.m_y1, m_Block.m_x2, m_Block.m_y2 ) );
  else
    LogString.Format( "Размер ширмы \"%s\": %d", m_Name, 
               ( int )GetDistance( m_Block.m_x1, m_Block.m_y1, m_Block.m_x2, m_Block.m_y2 ) );
}
//////////////////////////////////////////////////////////////////////////////
void CLightBlock::Serialize( CArchive& Ar )
{
  if( Ar.IsStoring() )
  {
    Ar << T_LIGHTBLOCK;
    Ar << m_Name;
    Ar << m_Block.m_x1;
    Ar << m_Block.m_y1;
    Ar << m_Block.m_x2;
    Ar << m_Block.m_y2;
  }
  else
  {
    Ar >> m_Name;
    Ar >> m_Block.m_x1;
    Ar >> m_Block.m_y1;
    Ar >> m_Block.m_x2;
    Ar >> m_Block.m_y2;
    Create( m_Block.m_x1, m_Block.m_y1, m_Block.m_x2, m_Block.m_y2 );
  }
}