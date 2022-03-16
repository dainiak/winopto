#ifndef __COPTOBJECT_H__
#define __COPTOBJECT_H__

//////////////////////////////////////////////////////////////////////////////
//COptObject class definition:
//////////////////////////////////////////////////////////////////////////////
class COptObject
{
public:
  CString m_Name;
  CRect m_ObjectRegion;

  virtual void Draw( void ) = 0;
  virtual CPoint GetIntersectPoint( void ) = 0;
  virtual void CalculateRay( void ) = 0;
  virtual BOOL IsClicked( CPoint*, int ) = 0;
  virtual void ParallelMove( int, int ) = 0;
  virtual void Rotate( double ) = 0;
  virtual void ChangeSize( int ) = 0;
  virtual void Serialize( CArchive& ) = 0;
};

#endif
