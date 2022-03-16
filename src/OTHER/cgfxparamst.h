#ifndef __CGRAPHICSPARAMSTORAGE_H__
#define __CGRAPHICSPARAMSTORAGE_H__

#include "geometry.h"
#include "clightblock.h"

//////////////////////////////////////////////////////////////////////////////
//CGraphicsParamStorage class definition:
//////////////////////////////////////////////////////////////////////////////
class CGraphicsParamStorage
{
private:
  COLORREF m_ColorArray[11];
  int m_WidthArray[11];
  int m_StyleArray[11];
  CPen* m_TempPen;
  COLORREF m_GlobalColor;
  BOOL m_UseGlobalColor;
public:  
  BOOL m_ShadowMode;
  CLightBlock m_ScreenLimits[4];
  BOOL m_DrawRayArrows;
  BOOL m_DrawILS;
  BOOL m_ShowRays;
  COLORREF m_ILSColor;
  COLORREF m_SelectionColor;
  BOOL m_ILSSelectionMode;
  BOOL m_SelectILS;
  double m_Zoom;

  void SetStyle( int );
  void SetStyle( int, int, COLORREF );
  void SetGlobalColor( COLORREF );
  void RestoreColors( void );
  void RestorePen( void );
  void SetColor( int, COLORREF );
  void SetScreenLimits( int, int, int, int );
  void SetObjectColor( int );
  void SerializeStyles( CArchive& );
  
  CGraphicsParamStorage( void );
};

#endif