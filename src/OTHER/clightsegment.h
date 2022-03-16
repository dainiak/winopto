#ifndef __CLIGHTSEGMENT_H__
#define __CLIGHTSEGMENT_H__

#include "coptobject.h"
#include "geometry.h"
#include "clightsource.h"

class CLightSegment:public COptObject
{
public:
  void Create( CLightSource*, CLightSource* );
  void Draw( void );
  CPoint GetIntersectPoint( void );
  void CalculateRay( void );
  BOOL IsClicked( CPoint*, int );
  void ParallelMove( int, int );
  void Rotate( double );
  void ChangeSize( int );
  void Serialize( CArchive& );

  CLightSource* m_End1;
  CLightSource* m_End2;
  CLine m_SegmentLine;
};

#endif