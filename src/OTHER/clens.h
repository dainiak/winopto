#ifndef __CLENS_H__
#define __CLENS_H__

#include "coptobject.h"
#include "geometry.h"

class CLens:public COptObject
{
public:	
  void Create( int, int, int, int );
  void Draw( void );
  CPoint GetIntersectPoint( void );
  void CalculateRay( void );
  BOOL IsClicked( CPoint*, int );
  void ParallelMove( int, int );
  void Rotate( double );
  void ChangeSize( int );
  void Serialize( CArchive& );

  CSegment m_Lens;
  int m_FocalDistance;
  int m_ShowFocalPlanes;
  int m_ShowMainOpticAxis;

  CLens( void );
};

#endif