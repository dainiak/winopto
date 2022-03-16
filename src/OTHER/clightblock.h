#ifndef __CLIGHTBLOCK_H__
#define __CLIGHTBLOCK_H__

#include "coptobject.h"
#include "geometry.h"

class CLightBlock:public COptObject
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
  
  CSegment m_Block;
  CLine m_BlockLine;

  CLightBlock( void );
};

#endif