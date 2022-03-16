#ifndef __CRAYANIMATOR_H__
#define __CRAYANIMATOR_H__

#include "geometry.h"
//////////////////////////////////////////////////////////////////////////////
//CRayAnimator class definition:
//////////////////////////////////////////////////////////////////////////////
class CRayAnimator
{
private:
  CLine m_ALine;
  int m_AHType;
  int m_FrameCounter;
  int m_TotalFrames;
  
public:
  COLORREF m_AColor;
  BOOL m_IsInitialized;

  void Initialize( CPoint*, CPoint* );
  void AnimateRay( void );

  CRayAnimator( void );
};

#endif