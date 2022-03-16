#include "optenums.h"
#include "geometry.h"
#include "coptlist.h"
#include "coptobject.h"
#include "clightsource.h"
#include "crayanimator.h"
#include "cgfxparamst.h"

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

//////////////////////////////////////////////////////////////////////////////
//Global variables
//////////////////////////////////////////////////////////////////////////////
extern COptList MainOptList;
extern CGraphicsParamStorage GraphParams;
extern COptObject* SelectedObject;
extern CString LogString;
extern CDC* GlobalDC;
extern int AnimationFlag;
extern CRay CurrentRay;
extern CPoint CurrentLSPosition;
extern CPoint OldLSPosition;
extern CString LogString;
extern CRayAnimator RayAnimator;
extern CPoint ILSPosition;
extern BOOL ILSIsImgFlag;

void DrawSystem( void );
void CalculateSystem( BOOL );
void CalculateScene( void );
COptObject* CheckWhatIsClicked( CPoint*, int );
void AddBorderLightBlocks( CRect* );
int GetOptObjectType( COptObject* );
void SerializeScene( CArchive& );
CRect GetSystemSize( void );
void StartAnimation( CLightSource* );
void AnimateSystem( void );
void ResetAnimator( void );
void OptimizeSystemLocation( int, int );
double Min( double, double );
void ValidateLightSegments( CLightSource* );
void CalculateSceneSegments( void );
int GetObjectNumber( COptObject* );

#endif