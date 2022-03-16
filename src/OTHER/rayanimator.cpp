#include <stdafx.h>
#include "crayanimator.h"
#include "globals.h"

//////////////////////////////////////////////////////////////////////////////
//CRayAnimator class member functions:
//////////////////////////////////////////////////////////////////////////////
CRayAnimator::CRayAnimator( void )
{
  m_IsInitialized = FALSE;
}
//////////////////////////////////////////////////////////////////////////////
void CRayAnimator::Initialize( CPoint* Point1, CPoint* Point2 )
{
  m_IsInitialized = TRUE;
  m_ALine.Create( Point1->x, Point1->y, Point2->x, Point2->y );
  
  if( abs( m_ALine.m_k ) < 1 )
  {  
    if( Point1->x < Point2->x )
      m_AHType = 0;
    else
      m_AHType = 1;
  
    m_TotalFrames = Point2->x;
    m_FrameCounter = Point1->x;
  }
  else
  {
    if( Point1->y < Point2->y )
      m_AHType = 2;
    else
      m_AHType = 3;

    m_TotalFrames = Point2->y;
    m_FrameCounter = Point1->y;
  }
}
//////////////////////////////////////////////////////////////////////////////
void CRayAnimator::AnimateRay( void )
{
  GraphParams.SetStyle( 1, 1, m_AColor );

  switch( m_AHType )
  {  
    case 0:
      DrawLine( m_FrameCounter, m_ALine.Gety( m_FrameCounter ),
                m_FrameCounter + 1, m_ALine.Gety( m_FrameCounter + 1 ) );
      m_FrameCounter++;
      break;

    case 1:
      DrawLine( m_FrameCounter, m_ALine.Gety( m_FrameCounter ),
                m_FrameCounter - 1, m_ALine.Gety( m_FrameCounter - 1 ) );
      m_FrameCounter--;
      break;

    case 2:
      DrawLine( m_ALine.Getx( m_FrameCounter ), m_FrameCounter, 
                m_ALine.Getx( m_FrameCounter + 1 ), m_FrameCounter + 1 );
      m_FrameCounter++;
      break;

    case 3:
      DrawLine( m_ALine.Getx( m_FrameCounter ), m_FrameCounter,
                m_ALine.Getx( m_FrameCounter - 1 ), m_FrameCounter - 1 );
      m_FrameCounter--;
  }
  
  if( m_FrameCounter == m_TotalFrames )
    m_IsInitialized = FALSE;
}
/*void CRayAnimator::AnimateRay( void )
{
  switch( m_AHType )
  {  
    case 0:
      GlobalDC->SetPixel( m_FrameCounter, m_ALine.Gety( m_FrameCounter ), m_AColor );
      m_FrameCounter++;
      break;

    case 1:
      GlobalDC->SetPixel( m_FrameCounter, m_ALine.Gety( m_FrameCounter ), m_AColor );
      m_FrameCounter--;
      break;

    case 2:
      GlobalDC->SetPixel( m_ALine.Getx( m_FrameCounter ), m_FrameCounter, m_AColor );
      m_FrameCounter++;
      break;

    case 3:
      GlobalDC->SetPixel( m_ALine.Getx( m_FrameCounter ), m_FrameCounter, m_AColor );
      m_FrameCounter--;
  }

  if( m_FrameCounter == m_TotalFrames )
    m_IsInitialized = FALSE;
}*/