#include <stdafx.h>
#include "clightsource.h"
#include "globals.h"

//////////////////////////////////////////////////////////////////////////////
//CLightSource class member functions:
//////////////////////////////////////////////////////////////////////////////
void CLightSource::Draw( void )
{
  if( !GraphParams.m_ShadowMode )
  {
    GraphParams.SetColor( GS_LIGHTSOURCE, m_Color );
    GraphParams.SetStyle( GS_LIGHTSOURCE );
    GlobalDC->Ellipse( m_Position.x - 2, m_Position.y - 2, m_Position.x + 2, m_Position.y + 2 );
    GraphParams.RestorePen();
  }
}
//////////////////////////////////////////////////////////////////////////////
void CLightSource::Create( int x, int y, COLORREF Color, int Angle )
{
  m_Position.x = x;
  m_Position.y = y;
  m_ObjectRegion.left = x;
  m_ObjectRegion.right = x;
  m_ObjectRegion.top = y;
  m_ObjectRegion.bottom = y;
  m_Color = Color;
  m_RayAngle = Angle;
}
//////////////////////////////////////////////////////////////////////////////
CPoint CLightSource::GetIntersectPoint( void )
{
  CPoint NewPoint;
  NewPoint.x = -1000;
  return NewPoint;
}
//////////////////////////////////////////////////////////////////////////////
void CLightSource::CalculateRay( void )
{
}
//////////////////////////////////////////////////////////////////////////////
BOOL CLightSource::IsClicked( CPoint* ClickPoint, int Accuracy )
{
  if( ClickPoint->x < m_Position.x + Accuracy && ClickPoint->x > m_Position.x - Accuracy &&
      ClickPoint->y < m_Position.y + Accuracy && ClickPoint->y > m_Position.y - Accuracy )
    return 1;
  
  return 0;
}
//////////////////////////////////////////////////////////////////////////////
void CLightSource::ParallelMove( int x, int y )
{
  m_ObjectRegion.left += x;
  m_ObjectRegion.right += x;
  m_ObjectRegion.top += y;
  m_ObjectRegion.bottom += y;
  m_Position.x += x;
  m_Position.y += y;
}
//////////////////////////////////////////////////////////////////////////////
void CLightSource::Rotate( double Angle )
{
  m_RayAngle += 50 * Angle;

  if( m_RayAngle > 180 )
    m_RayAngle = - 179;

  if( m_RayAngle < -180 )
    m_RayAngle = 179;

  if( m_Name.IsEmpty() )
    LogString.Format( "Ray direction: %d degrees", m_RayAngle );
  else
    LogString.Format( "Light source \"%s\" ray direction: %d degrees", m_Name, m_RayAngle );
}
//////////////////////////////////////////////////////////////////////////////
void CLightSource::ChangeSize( int )
{
  LogString.Empty();
}
//////////////////////////////////////////////////////////////////////////////
CLightSource::CLightSource( void )
{
  m_Color = RGB( 255, 200, 0 );
  m_RayAngle = 0;
  m_Position.x = 0;
  m_Position.y = 0;
}
//////////////////////////////////////////////////////////////////////////////
void CLightSource::Serialize( CArchive& Ar )
{
  if( Ar.IsStoring() )
  {
    Ar << T_LIGHTSOURCE;
    Ar << m_Name;
    Ar << m_Position.x;
    Ar << m_Position.y;
    Ar << m_RayAngle;
    Ar << m_Color;
  }
  else
  {
    Ar >> m_Name;
    Ar >> m_Position.x;
    Ar >> m_Position.y;
    Ar >> m_RayAngle;
    Ar >> m_Color;
    Create( m_Position.x, m_Position.y, m_Color, m_RayAngle );
  }
}