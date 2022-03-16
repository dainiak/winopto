#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

//////////////////////////////////////////////////////////////////////////////
//CLine class definition:
//////////////////////////////////////////////////////////////////////////////
class CLine
{
public:
  //Coefficients of the line y=kx+m_b
  double m_k;
  double m_b;
  BOOL m_IsOrtogonal;

  //These functions compute y(x) and x(y)
  int Gety( int );
  int Getx( int );
  void Create( int, int, int, int );

  CLine( void ); 
};

class CRay:public CLine 
{
public:
  int m_Direction;
  int m_RFlag;
  CRay( void );
  void Create( int, int, int, int );
};

//////////////////////////////////////////////////////////////////////////////
//CSegment class definition:
//////////////////////////////////////////////////////////////////////////////
class CSegment
{
public:
  int m_x1, m_y1;
  int m_x2, m_y2;

  void Create( int, int, int, int ); 
  CPoint GetMiddlePoint( void );
  CLine GetParentLine( void );
  BOOL IsOnSegment( CPoint*, double );
  void Draw( void );
  void RotateByCenter( double );
  void ChangeSize( int, CLine* );
};

int Max( int, int );
int Min( int, int );
double Min( double, double );
int FFix( float );
BOOL IsInRect( CPoint*, CRect* );
double GetDistance( CPoint*, CPoint* );
double GetDistance( int, int, int, int );
CPoint GetSymmetricPoint( CPoint*, CLine* );
void DrawLine( int, int, int, int );
void DrawArrow( int, int, int, int, int, double, BOOL );
CPoint LineIntersect( CLine*, CLine* );
CLine GetOrtogonal( CLine*, CPoint* );
double GetAngle( CLine*, CLine* );
BOOL IsValidDirection( CPoint*, CPoint* );

#endif