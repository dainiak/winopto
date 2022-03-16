#ifndef __CLIGHTSOURCE_H__
#define __CLIGHTSOURCE_H__

#include "coptobject.h"

class CLightSource:public COptObject
{ 
public:
  void Create( int, int, COLORREF, int );
  void Draw( void );
  CPoint GetIntersectPoint( void );
  void CalculateRay( void );
  BOOL IsClicked( CPoint*, int );
  void ParallelMove( int, int );
  void Rotate( double );
  void ChangeSize( int );
  void Serialize( CArchive& );

  CPoint m_Position;
  int m_RayAngle;
  COLORREF m_Color;
  
  CLightSource( void );
};

#endif