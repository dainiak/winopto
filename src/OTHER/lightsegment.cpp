#include <stdafx.h>
#include "clightsegment.h"
#include "globals.h"

//////////////////////////////////////////////////////////////////////////////
//CLightSegment class member functions:
//////////////////////////////////////////////////////////////////////////////
void CLightSegment::Create( CLightSource* LS1, CLightSource* LS2 )
{
  m_End1 = LS1;
  m_End2 = LS2;
  m_SegmentLine.Create( m_End1->m_Position.x, m_End1->m_Position.y, 
                            m_End2->m_Position.x, m_End2->m_Position.y );
  m_ObjectRegion.left = Min( m_End1->m_Position.x, m_End2->m_Position.x );
  m_ObjectRegion.right = Max( m_End1->m_Position.x, m_End2->m_Position.x );
  m_ObjectRegion.top = Min( m_End1->m_Position.y, m_End2->m_Position.y );
  m_ObjectRegion.bottom = Max( m_End1->m_Position.y, m_End2->m_Position.y );
}
//////////////////////////////////////////////////////////////////////////////
void CLightSegment::Draw( void )
{
  if( !GraphParams.m_ShadowMode )
  {
    GraphParams.SetStyle( GS_LIGHTSEGMENT );
    DrawLine( m_End1->m_Position.x, m_End1->m_Position.y, 
                              m_End2->m_Position.x, m_End2->m_Position.y );
    DrawArrow( m_End1->m_Position.x, m_End1->m_Position.y, 
         m_End2->m_Position.x, m_End2->m_Position.y, 8, M_PI / 6, FALSE );
    GraphParams.RestorePen();
  }
}
//////////////////////////////////////////////////////////////////////////////
CPoint CLightSegment::GetIntersectPoint( void )
{
  CPoint NewPoint;
  NewPoint.x = -1000;
  return NewPoint;
}
//////////////////////////////////////////////////////////////////////////////
void CLightSegment::CalculateRay( void )
{
}
//////////////////////////////////////////////////////////////////////////////
BOOL CLightSegment::IsClicked( CPoint* ClickPoint, int Accuracy )
{
  CSegment NewSegment;
  NewSegment.Create( m_End1->m_Position.x, m_End1->m_Position.y, 
                            m_End2->m_Position.x, m_End2->m_Position.y );
  return NewSegment.IsOnSegment( ClickPoint, Accuracy );
}
//////////////////////////////////////////////////////////////////////////////
void CLightSegment::ParallelMove( int x, int y )
{
  m_End1->ParallelMove( x, y );
  m_End2->ParallelMove( x, y );
  m_SegmentLine.Create( m_End1->m_Position.x, m_End1->m_Position.y, 
                            m_End2->m_Position.x, m_End2->m_Position.y );
}
//////////////////////////////////////////////////////////////////////////////
void CLightSegment::Rotate( double Angle )
{
  CSegment NewSegment;
  NewSegment.Create( m_End1->m_Position.x, m_End1->m_Position.y, 
                            m_End2->m_Position.x, m_End2->m_Position.y );
  NewSegment.RotateByCenter( Angle );
  m_SegmentLine.Create( NewSegment.m_x1, NewSegment.m_y1, NewSegment.m_x2, NewSegment.m_y2 );
  m_End1->m_Position.x = NewSegment.m_x1;
  m_End1->m_Position.y = NewSegment.m_y1;
  m_End2->m_Position.x = NewSegment.m_x2;
  m_End2->m_Position.y = NewSegment.m_y2;
  m_ObjectRegion.left = Min( m_End1->m_Position.x, m_End2->m_Position.x );
  m_ObjectRegion.right = Max( m_End1->m_Position.x, m_End2->m_Position.x );
  m_ObjectRegion.top = Min( m_End1->m_Position.y, m_End2->m_Position.y );
  m_ObjectRegion.bottom = Max( m_End1->m_Position.y, m_End2->m_Position.y );
}
//////////////////////////////////////////////////////////////////////////////
void CLightSegment::ChangeSize( int DeltaSize )
{
  CSegment NewSegment;
  NewSegment.Create( m_End1->m_Position.x, m_End1->m_Position.y, 
                            m_End2->m_Position.x, m_End2->m_Position.y );
  NewSegment.ChangeSize( DeltaSize, &m_SegmentLine );
  m_End1->m_Position.x = NewSegment.m_x1;
  m_End1->m_Position.y = NewSegment.m_y1;
  m_End2->m_Position.x = NewSegment.m_x2;
  m_End2->m_Position.y = NewSegment.m_y2;
  m_ObjectRegion.left = Min( m_End1->m_Position.x, m_End2->m_Position.x );
  m_ObjectRegion.right = Max( m_End1->m_Position.x, m_End2->m_Position.x );
  m_ObjectRegion.top = Min( m_End1->m_Position.y, m_End2->m_Position.y );
  m_ObjectRegion.bottom = Max( m_End1->m_Position.y, m_End2->m_Position.y );
}
//////////////////////////////////////////////////////////////////////////////
void CLightSegment::Serialize( CArchive& Ar )
{
  if( Ar.IsStoring() )
  {
    Ar << T_LIGHTSEGMENT;
    Ar << GetObjectNumber( m_End1 );
    Ar << GetObjectNumber( m_End2 );
  }
  else
  {
    int k;
    Ar >> k;
    MainOptList.FreeAccess( k );
    m_End1 = ( CLightSource* ) ( LPVOID( MainOptList.GetElement() ));
    Ar >> k;
    MainOptList.FreeAccess( k );
    m_End2 = ( CLightSource* ) ( LPVOID( MainOptList.GetElement() ));
    Create( m_End1, m_End2 );
    MainOptList.GoToEnd();
  }
}