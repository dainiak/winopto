#ifndef __CFLATMIRROR_H__
#define __CFLATMIRROR_H__

#include "coptobject.h"
#include "geometry.h"

class CFlatMirror:public COptObject
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

  CSegment m_FlatMirror;
  CLine m_MirrorLine;

  CFlatMirror( void );
};

#endif