#include <stdafx.h>
#include <math.h>
#include "globals.h"

//////////////////////////////////////////////////////////////////////////////
//Additional necessary functions:
//////////////////////////////////////////////////////////////////////////////
/*double abs( double x )
{
  return ( x > 0 ? x : -x );
}*/
//////////////////////////////////////////////////////////////////////////////
int Max( int a, int b )
{
  return ( a > b ? a : b );
}
int Min( int a, int b )
{
  return( a < b ? a : b );
}
//////////////////////////////////////////////////////////////////////////////
double Min( double a, double b )  //Specially for ZoomFit feature
{
  return( a < b ? a : b );
}
//////////////////////////////////////////////////////////////////////////////
int FFix( float x )
{
  if( int( x * 10 ) % 10 < 5 )
    return int( x );
  else
    return int( x + 1 );
}
//////////////////////////////////////////////////////////////////////////////
BOOL IsInRect( CPoint* Point, CRect* Rectangle )
{
  if(( Point->x >= Rectangle->left - 1 ) && ( Point->x <= Rectangle->right + 1 ) &&
    ( Point->y >= Rectangle->top - 1 ) && ( Point->y <= Rectangle->bottom + 1 ))
    return 1;

  return 0;
}
//////////////////////////////////////////////////////////////////////////////
double GetDistance( CPoint* Point1, CPoint* Point2 )
{
	double t = double( ( Point2->x - Point1->x ) * ( Point2->x - Point1->x ) +
                      ( Point2->y - Point1->y ) * ( Point2->y - Point1->y ));
  return sqrt( t );
}
//////////////////////////////////////////////////////////////////////////////
double GetDistance( int x1, int y1, int x2, int y2 )
{
	double t = ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 );
  return sqrt( t );
}
//////////////////////////////////////////////////////////////////////////////
CPoint GetSymmetricPoint( CPoint* Point, CLine* Line )
{
  CPoint NewPoint;
  
  if( Line->m_IsOrtogonal )
  {
    NewPoint.x = 2 * Line->m_b - Point->x;
    NewPoint.y = Point->y;
    return NewPoint;
  }

  NewPoint.x = ( Line->m_k * ( 2 * Point->y - 2 * Line->m_b - Point->x * Line->m_k ) + Point->x ) /
                                  ( 1 + Line->m_k * Line->m_k );
  NewPoint.y = ( Line->m_k * ( 2 * Point->x + Line->m_k * Point->y ) + 2 * Line->m_b - Point->y ) /
                                  ( 1 + Line->m_k * Line->m_k );
  return NewPoint;
}
//////////////////////////////////////////////////////////////////////////////
void DrawLine( int x1, int y1, int x2, int y2 )
{
  GlobalDC->MoveTo( x1, y1 );
  GlobalDC->LineTo( x2, y2 );
}
//////////////////////////////////////////////////////////////////////////////
void DrawArrow( int x1, int y1, int x2, int y2, int Length, double Angle, BOOL Middle = 1 )
{
  int NewX;
  int NewY;

  if( Middle )
  {
    NewX = ( x1 + x2 ) / 2;
    NewY = ( y1 + y2 ) / 2;
  }
  else
  {
    NewX = x2;
    NewY = y2;
  }

	double tx = x2 - x1;
	double ty = y2 - y1;

  double BaseAngle = atan2( tx, ty) + M_PI;
  DrawLine( NewX, NewY, NewX + Length * sin( BaseAngle + Angle ), 
           NewY + Length * cos( BaseAngle + Angle ));
  DrawLine( NewX, NewY, NewX + Length * sin( BaseAngle - Angle ), 
           NewY + Length * cos( BaseAngle - Angle ));
}
//////////////////////////////////////////////////////////////////////////////
//CLine class member functions:
//////////////////////////////////////////////////////////////////////////////
CLine::CLine( void )
{
  m_IsOrtogonal = FALSE;
  m_k = 0;
  m_b = 0;
}
//////////////////////////////////////////////////////////////////////////////
int CLine::Gety( int x )
{
  if( m_IsOrtogonal )
    AfxMessageBox("Internal Error: GETY", 1, 0 );

  return int( m_k * x + m_b );
}
//////////////////////////////////////////////////////////////////////////////
int CLine::Getx( int y )
{
  if( m_IsOrtogonal )
    return m_b;

  return int( ( y - m_b ) / m_k );
}
//////////////////////////////////////////////////////////////////////////////
void CLine::Create( int x1, int y1, int x2, int y2 )
{
  if( x2 == x1 )
  {
    m_IsOrtogonal = TRUE;
	  m_b = x1;
    m_k = 2;
  }
  else
  {
    m_IsOrtogonal = FALSE;
    m_k = double( y2 - y1 ) / ( x2 - x1 );
    m_b = ( y1 - m_k * x1 );
  }
}


//////////////////////////////////////////////////////////////////////////////
//CSegment class member functions:
//////////////////////////////////////////////////////////////////////////////
void CSegment::Create( int x1, int y1, int x2, int y2 )
{
  m_x1 = x1;
  m_y1 = y1;
  m_x2 = x2;
  m_y2 = y2;
}
//////////////////////////////////////////////////////////////////////////////
CPoint CSegment::GetMiddlePoint( void )
{
  CPoint NewPoint;

  NewPoint.x = ( m_x1 + m_x2 ) / 2;
  NewPoint.y = ( m_y1 + m_y2 ) / 2;

  return NewPoint;
}
//////////////////////////////////////////////////////////////////////////////
CLine CSegment::GetParentLine( void )
{
  CLine NewLine;

  NewLine.Create( m_x1, m_y1, m_x2, m_y2 );

  return NewLine;
}
//////////////////////////////////////////////////////////////////////////////
BOOL CSegment::IsOnSegment( CPoint* Point, double Accuracy )
{
  if( Point->x < Min( m_x1, m_x2 ) - Accuracy || Point->x > Max( m_x1, m_x2 ) + Accuracy ||
      Point->y < Min( m_y1, m_y2 ) - Accuracy || Point->y > Max( m_y1, m_y2 ) + Accuracy )
    return 0;
  
  if( m_x1 == m_x2 )
  {
    if( Point->x < m_x1 + Accuracy && Point->x > m_x1 - Accuracy && 
    Point->y >= Min( m_y1, m_y2 ) && Point->y <= Max( m_y1, m_y2 ))
      return 1;
  }
  else
  {
    CLine NewLine;
    NewLine.Create( m_x1, m_y1, m_x2, m_y2 );

    if( abs( NewLine.m_k ) <= 1 )
    {
      if( Point->y > NewLine.Gety( Point->x ) - Accuracy && Point->y < NewLine.Gety( Point->x ) + Accuracy )
        return 1;
    }
    else
    {
      if( Point->x > NewLine.Getx( Point->y ) - Accuracy && Point->x < NewLine.Getx( Point->y ) + Accuracy )
        return 1;
    }
  }  

  return 0;
}
//////////////////////////////////////////////////////////////////////////////
void CSegment::Draw( void )
{
  DrawLine( m_x1, m_y1, m_x2, m_y2 );
}
//////////////////////////////////////////////////////////////////////////////
void CSegment::RotateByCenter( double Angle )
{
  float MidX = ( m_x1 + m_x2 ) / 2.0;
  float MidY = ( m_y1 + m_y2 ) / 2.0;
  int new_x, new_y;
  new_x = FFix(( m_x1 - MidX ) * cos( Angle ) - ( m_y1 - MidY ) * sin( Angle ) + MidX );
  new_y = FFix(( m_x1 - MidX ) * sin( Angle ) + ( m_y1 - MidY ) * cos( Angle ) + MidY );
  m_x1 = new_x;
  m_y1 = new_y;
  new_x = FFix(( m_x2 - MidX ) * cos( Angle ) - ( m_y2 - MidY ) * sin( Angle ) + MidX );
  new_y = FFix(( m_x2 - MidX ) * sin( Angle ) + ( m_y2 - MidY ) * cos( Angle ) + MidY );
  m_x2 = new_x;
  m_y2 = new_y;
}
//////////////////////////////////////////////////////////////////////////////
void CSegment::ChangeSize( int DeltaSize, CLine* NewLine )
{
  if( abs( NewLine->m_k ) <= 1 )
  {
    if( m_x1 > m_x2 )
      DeltaSize *= -1;

    m_x1 += DeltaSize;
    m_x2 -= DeltaSize;
    m_y1 = NewLine->Gety( m_x1 );
    m_y2 = NewLine->Gety( m_x2 );
  }
  else
  {
    if( m_y1 > m_y2 )
      DeltaSize *= -1;

    m_y1 += DeltaSize;
    m_y2 -= DeltaSize;
    m_x1 = NewLine->Getx( m_y1 );
    m_x2 = NewLine->Getx( m_y2 );
  }
}
//////////////////////////////////////////////////////////////////////////////
//Additional functions that operate with lines:
//////////////////////////////////////////////////////////////////////////////
CPoint LineIntersect( CLine* Line1, CLine* Line2 )
{
  CPoint IntersectPoint;

  if( Line1->m_IsOrtogonal && Line2->m_IsOrtogonal || Line1->m_k == Line2->m_k )
  {
    IntersectPoint.x = -1000;
    return IntersectPoint;
  }

  if( Line1->m_IsOrtogonal )
  {
    IntersectPoint.x = Line1->m_b;
    IntersectPoint.y = Line2->Gety( Line1->m_b );
    return IntersectPoint;
  }

  if( Line2->m_IsOrtogonal )
  {
    IntersectPoint.x = Line2->m_b;
    IntersectPoint.y = Line1->Gety( Line2->m_b );
    return IntersectPoint;
  }

  IntersectPoint.x = int(( Line1->m_b - Line2->m_b ) / ( Line2->m_k - Line1->m_k ));
  IntersectPoint.y = int(( Line1->m_k * Line2->m_b - Line2->m_k * Line1->m_b ) / 
                                                       ( Line1->m_k - Line2->m_k ));
  return IntersectPoint;
}  
//////////////////////////////////////////////////////////////////////////////
CLine GetOrtogonal( CLine* SourceLine, CPoint* ControlPoint )
{
  CLine OrtogonalLine;

  if( SourceLine->m_IsOrtogonal )
  {
    OrtogonalLine.m_k = 0;
    OrtogonalLine.m_b = ControlPoint->y;
    return OrtogonalLine;
  }

  if( SourceLine->m_k == 0 )
  {
    OrtogonalLine.m_IsOrtogonal = 1;
    OrtogonalLine.m_b = ControlPoint->x;
    return OrtogonalLine;
  }

  OrtogonalLine.m_k = -1 / SourceLine->m_k;
  OrtogonalLine.m_b = int( ControlPoint->y - OrtogonalLine.m_k * ControlPoint->x );
  return OrtogonalLine;
}
//////////////////////////////////////////////////////////////////////////////
double GetAngle( CLine* Line1, CLine* Line2 )
{
  if( Line1->m_IsOrtogonal && Line2->m_IsOrtogonal )
    return -1;

  if( Line1->m_IsOrtogonal )
    return M_PI/2 - atan( Line2->m_k );

  if( Line2->m_IsOrtogonal )
    return M_PI/2 - atan( Line1->m_k );

  double Angle = abs( atan( Line1->m_k ) - atan( Line2->m_k ) );

  if( Angle > M_PI/2 ) 
    Angle = M_PI - Angle;

  return Angle;
}

//////////////////////////////////////////////////////////////////////////////
//CRay class:
//////////////////////////////////////////////////////////////////////////////
CRay::CRay( void )
{
  m_RFlag = 1;
  m_IsOrtogonal = FALSE;
}
//////////////////////////////////////////////////////////////////////////////
void CRay::Create( int x1, int y1, int x2, int y2 )
{
  if( x2 == x1 )
  {
    m_IsOrtogonal = TRUE;
	  m_b = x1;

    if( y1 > y2 )
      m_Direction = DIR_LR;
    else
      m_Direction = DIR_RL;
  }
  else
  {
    m_IsOrtogonal = FALSE;
    m_k = double( y2 - y1 ) / ( x2 - x1 );
    m_b = ( y1 - m_k * x1 );
    m_Direction = ( x1 > x2 );
  }
}
//////////////////////////////////////////////////////////////////////////////
BOOL IsValidDirection( CPoint* Point1, CPoint* Point2 )
{
  if( Point1->x == Point2->x )
  {
    if( CurrentRay.m_Direction - ( Point2->y < Point1->y ))
      return TRUE;
    
    return FALSE;
  }
  else
    if( CurrentRay.m_Direction - ( Point2->x > Point1->x ))
      return TRUE;

  return FALSE;
}