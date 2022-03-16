#include "stdafx.h"
#include <math.h>
#include "globals.h"
#include "coptlist.h"
#include "cflatmirror.h"
#include "clightblock.h"
#include "clightsource.h"
#include "clens.h"
#include "clightsegment.h"
#include <typeinfo>

COptList MainOptList;
CGraphicsParamStorage GraphParams;
COptObject* SelectedObject;
CRay CurrentRay;
CPoint CurrentLSPosition;
CPoint OldLSPosition;
CString LogString;
CRayAnimator RayAnimator;
int AnimationFlag;
CPoint ILSPosition;
BOOL ILSIsImgFlag;
CDC* GlobalDC;

//////////////////////////////////////////////////////////////////////////////
//Main functions of the kernel
//////////////////////////////////////////////////////////////////////////////
int GetOptObjectType( COptObject* Object )
{
  if( typeid( *Object ) == typeid( CFlatMirror ))
    return T_FLATMIRROR;

  if( typeid( *Object ) == typeid( CLens ))
    return T_LENS;

  if( typeid( *Object ) == typeid( CLightBlock ))
    return T_LIGHTBLOCK;

  if( typeid( *Object ) == typeid( CLightSource ))
    return T_LIGHTSOURCE;

  if( typeid( *Object ) == typeid( CLightSegment ))
    return T_LIGHTSEGMENT;

  return -1;
}
//////////////////////////////////////////////////////////////////////////////
void DrawSystem( void )
{
  MainOptList.GoToStart();
  
  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    MainOptList.GetElement()->Draw();
    MainOptList.Next();
  }
}
//////////////////////////////////////////////////////////////////////////////
void SetCurrentLightSource( CLightSource* TempLS )
{
  CurrentLSPosition.x = TempLS->m_Position.x;
  CurrentLSPosition.y = TempLS->m_Position.y;

  if( TempLS == SelectedObject )
    GraphParams.m_ILSSelectionMode = TRUE;
  else
    GraphParams.m_ILSSelectionMode = FALSE;

  if( abs( TempLS->m_RayAngle ) == 90 )
  {
    CurrentRay.m_k = 2;
    CurrentRay.m_b = TempLS->m_Position.x;
    CurrentRay.m_Direction = ( TempLS->m_RayAngle > 0 );
    CurrentRay.m_IsOrtogonal = TRUE;
  }
  else
  {
    CurrentRay.m_k = tan( TempLS->m_RayAngle * M_PI / 180 );
    CurrentRay.m_b = CurrentLSPosition.y - CurrentRay.m_k * CurrentLSPosition.x;
    
    if( abs( TempLS->m_RayAngle ) < 90 )
      CurrentRay.m_Direction = DIR_LR;
    else
      CurrentRay.m_Direction = DIR_RL;

    CurrentRay.m_IsOrtogonal = FALSE;
  }

  CurrentRay.m_RFlag = 1;
  GraphParams.SetColor( GS_RAY, TempLS->m_Color );
  GraphParams.SetColor( GS_RAYARROWS, TempLS->m_Color );
}//SetCurrentLightSource
//////////////////////////////////////////////////////////////////////////////
COptObject* GetNextIntersectedObject( void )
{
  int NewDistance, OldDistance;
  CPoint TempPoint;
  COptObject* NextObject;
  MainOptList.GoToStart();
  OldDistance = 65536;
  NextObject = NULL;

  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    TempPoint = MainOptList.GetElement()->GetIntersectPoint();

    if( TempPoint.x != -1000 )
    {
      NewDistance = GetDistance( &TempPoint, &CurrentLSPosition );

      if( NewDistance > 3 && NewDistance < OldDistance )
      {
        OldDistance = NewDistance;
        NextObject = MainOptList.GetElement();
      }
    }

    MainOptList.Next();
  }

  if( !NextObject )
  {
    int k = 0;
    OldDistance = 65536;

    for( int i = 0; i < 4; i++ )
    {
      TempPoint = GraphParams.m_ScreenLimits[i].GetIntersectPoint();

      if( TempPoint.x != -1000 )
      {
        NewDistance = GetDistance( &TempPoint, &CurrentLSPosition );

        if( NewDistance < OldDistance )
        {
          OldDistance = NewDistance;
          k = i;
        }
      }
    }
    NextObject = ( COptObject* )( &GraphParams.m_ScreenLimits[k] );
  }

  return NextObject;
}//GetNextIntersectedObject
//////////////////////////////////////////////////////////////////////////////
void CalculateSystem( BOOL ShowRay )
{
  COptObject* NextObject;

  while( CurrentRay.m_RFlag )
  {
    NextObject = GetNextIntersectedObject();
    NextObject->CalculateRay();

    if( GraphParams.m_ShowRays )
    {
      GraphParams.SetStyle( GS_RAY );    
      DrawLine( OldLSPosition.x, OldLSPosition.y, CurrentLSPosition.x, CurrentLSPosition.y );
      GraphParams.RestorePen();

      if( GraphParams.m_DrawRayArrows )
      {
        GraphParams.SetStyle( GS_RAYARROWS );
        DrawArrow( OldLSPosition.x, OldLSPosition.y, CurrentLSPosition.x, CurrentLSPosition.y, 7, M_PI / 6, 1 );
        GraphParams.RestorePen();
      }
    }
  }
}
//////////////////////////////////////////////////////////////////////////////
void CalculateSegment( CLightSegment* LightSegment )
{
  COptObject* NextObject;
  COptObject* NextObject2;
  CPoint xCurrentLSPosition, xCurrentLSPosition2;
  CPoint xILSPosition, xILSPosition2;
  CRay xCurrentRay, xCurrentRay2;
  BOOL xILSIsImgFlag;
  SetCurrentLightSource( LightSegment->m_End1 );
  ILSPosition = LightSegment->m_End1->m_Position;
  NextObject = GetNextIntersectedObject();
  NextObject->CalculateRay();
  xCurrentRay = CurrentRay;
  xCurrentLSPosition = CurrentLSPosition;
  xILSPosition = ILSPosition;
  xILSIsImgFlag = ILSIsImgFlag;
  SetCurrentLightSource( LightSegment->m_End2 );
  ILSPosition = LightSegment->m_End2->m_Position;
  NextObject2 = GetNextIntersectedObject();
  NextObject2->CalculateRay();
  xCurrentRay2 = CurrentRay;
  xCurrentLSPosition2 = CurrentLSPosition;
  xILSPosition2 = ILSPosition;

  if( LightSegment == SelectedObject )
    GraphParams.m_ILSSelectionMode = TRUE;
  else
    GraphParams.m_ILSSelectionMode = FALSE;

  while( xCurrentRay.m_RFlag && xCurrentRay2.m_RFlag && NextObject == NextObject2 &&
                                                        ILSIsImgFlag == xILSIsImgFlag )
  {
    if( GraphParams.m_ILSSelectionMode )
      GraphParams.SetStyle( PS_DASH, 1, GraphParams.m_SelectionColor );
    else
      GraphParams.SetStyle( PS_DASH, 1, GraphParams.m_ILSColor );

    DrawLine( xILSPosition.x, xILSPosition.y, xILSPosition2.x, xILSPosition2.y );
    DrawArrow( xILSPosition.x, xILSPosition.y, xILSPosition2.x, xILSPosition2.y, 8, M_PI / 6, FALSE );
    GraphParams.RestorePen();
    CurrentRay = xCurrentRay;
    CurrentLSPosition = xCurrentLSPosition;
    ILSPosition = xILSPosition;
    NextObject = GetNextIntersectedObject();
    NextObject->CalculateRay();
    xCurrentRay = CurrentRay;
    xCurrentLSPosition = CurrentLSPosition;
    xILSPosition = ILSPosition;
    xILSIsImgFlag = ILSIsImgFlag;
    CurrentRay = xCurrentRay2;
    CurrentLSPosition = xCurrentLSPosition2;
    ILSPosition = xILSPosition2;
    NextObject2 = GetNextIntersectedObject();
    NextObject2->CalculateRay();
    xCurrentRay2 = CurrentRay;
    xCurrentLSPosition2 = CurrentLSPosition;
    xILSPosition2 = ILSPosition;
  }
}//CalculateSegment
//////////////////////////////////////////////////////////////////////////////
void StartAnimation( CLightSource* LightSource )
{
  SetCurrentLightSource( LightSource );
  GraphParams.SetGlobalColor( RGB( 255, 255, 255 ) );
  CalculateSystem( TRUE );
  GraphParams.RestoreColors();
  SetCurrentLightSource( LightSource );
  OldLSPosition = CurrentLSPosition;
  RayAnimator.m_AColor = LightSource->m_Color;
}

//////////////////////////////////////////////////////////////////////////////
void AnimateSystem( void )
{
  if( RayAnimator.m_IsInitialized )
    RayAnimator.AnimateRay();
  else 
    if( CurrentRay.m_RFlag )
    {
	    if( GraphParams.m_DrawRayArrows && OldLSPosition != CurrentLSPosition )
      {
        GraphParams.SetStyle( GS_RAYARROWS );
        DrawArrow( OldLSPosition.x, OldLSPosition.y, CurrentLSPosition.x, CurrentLSPosition.y, 7, M_PI / 6, 1 );
        GraphParams.RestorePen();
      }

      COptObject* NextObject;
      NextObject = GetNextIntersectedObject();
      NextObject->CalculateRay();
      RayAnimator.Initialize( &OldLSPosition, &CurrentLSPosition );
    }
    else
      AnimationFlag = 0;
}
//////////////////////////////////////////////////////////////////////////////
void ResetAnimator( void )
{
  RayAnimator.m_IsInitialized = FALSE;
}
//////////////////////////////////////////////////////////////////////////////
void CalculateScene( void )
{
  COptObject* TempObject;
  int i;

  for( i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    MainOptList.FreeAccess( i );
    TempObject = MainOptList.GetElement();
    
    if( GetOptObjectType( TempObject ) == T_LIGHTSOURCE )
    {
      if( GraphParams.m_DrawILS )
        ILSPosition = ( ( CLightSource* )( ( LPVOID ) TempObject ) )->m_Position;
      SetCurrentLightSource( ( CLightSource* )( ( LPVOID ) TempObject ) );
      CalculateSystem( TRUE );
    }
    
    MainOptList.Next();
  }
}
//////////////////////////////////////////////////////////////////////////////
void CalculateSceneSegments( void )
{
  MainOptList.GoToStart();
  
  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    MainOptList.FreeAccess( i );

    if( GetOptObjectType( MainOptList.GetElement() ) == T_LIGHTSEGMENT )
      CalculateSegment(( CLightSegment* )( LPVOID( MainOptList.GetElement() )));
  }  
}
//////////////////////////////////////////////////////////////////////////////
COptObject* CheckWhatIsClicked( CPoint* ClickPoint, int Accuracy )
{
  COptObject* TempObject;
  MainOptList.GoToStart();
  
  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    TempObject = MainOptList.GetElement();

    if( TempObject->IsClicked( ClickPoint, Accuracy ) ) 
      return TempObject;

    MainOptList.Next();
  }
  
  return NULL;
}
//////////////////////////////////////////////////////////////////////////////
void AddBorderLightBlocks( CRect* Border )
{
  int CoordArray[4][4];
  CoordArray[0][0] = CoordArray[1][0] = CoordArray[2][0] = CoordArray[2][2] = Border->left;
  CoordArray[0][1] = CoordArray[0][3] = CoordArray[2][1] = CoordArray[3][1] = Border->top;
  CoordArray[0][2] = CoordArray[1][2] = CoordArray[3][0] = CoordArray[3][2] = Border->right;
  CoordArray[1][1] = CoordArray[1][3] = CoordArray[2][3] = CoordArray[3][3] = Border->bottom;

  for( int i = 0; i < 4; i++ )
  {
    CLightBlock* BorderLightBlock;
    BorderLightBlock = new CLightBlock;
    BorderLightBlock->Create( CoordArray[i][0], CoordArray[i][1], CoordArray[i][2], CoordArray[i][3] );
    MainOptList.AddElement();
    MainOptList.SetElement( ( COptObject* )BorderLightBlock );
  }
}
//////////////////////////////////////////////////////////////////////////////
void SerializeScene( CArchive& Archive )
{
  int n;
  int i;
  int t;
  
  if( Archive.IsStoring() )
  {
    n = MainOptList.GetNumOfElements();
    Archive << n;
    MainOptList.GoToStart();
    
    for( i = 0; i < n; i++ )
    {
      MainOptList.FreeAccess( i );
      MainOptList.GetElement()->Serialize( Archive );
    }

    Archive << GraphParams.m_Zoom;
    Archive << GraphParams.m_DrawILS;
    Archive << GraphParams.m_DrawRayArrows;
    Archive << GraphParams.m_ShowRays;
  }
  else
  {
    MainOptList.Clear();
    Archive >> n;
    
    for( i = 0; i < n; i++ )
    {
      MainOptList.AddElement();
      Archive >> t;
      
      switch( t )
      {
        case T_LIGHTSOURCE:
          CLightSource* TempLS;
          TempLS = new CLightSource;
          TempLS->Serialize( Archive );
          MainOptList.SetElement( ( COptObject* )TempLS );
          break;

        case T_FLATMIRROR:
          CFlatMirror* TempFM;
          TempFM = new CFlatMirror;
          TempFM->Serialize( Archive );
          MainOptList.SetElement( ( COptObject* )TempFM );
          break;

        case T_LIGHTBLOCK:
          CLightBlock* TempLB;
          TempLB = new CLightBlock;
          TempLB->Serialize( Archive );
          MainOptList.SetElement( ( COptObject* )TempLB );
          break;

        case T_LENS:
          CLens* TempLens;
          TempLens = new CLens;
          TempLens->Serialize( Archive );
          MainOptList.SetElement( ( COptObject* )TempLens );
          break;

        case T_LIGHTSEGMENT:
          CLightSegment* TempLSegment;
          TempLSegment = new CLightSegment;
          TempLSegment->Serialize( Archive );
          MainOptList.SetElement( ( COptObject* )TempLSegment );
      }
    }

    Archive >> GraphParams.m_Zoom;
    Archive >> GraphParams.m_DrawILS;
    Archive >> GraphParams.m_DrawRayArrows;
    Archive >> GraphParams.m_ShowRays;
  }
}//SerializeScene
//////////////////////////////////////////////////////////////////////////////
CRect GetSystemSize( void )
{
  CRect SizeRect;
  COptObject* TempElement;
  MainOptList.GoToStart();

  if( MainOptList.GetNumOfElements() )
    SizeRect = MainOptList.GetElement()->m_ObjectRegion;
  else
  {
    SizeRect.SetRectEmpty();
  }
  
  for( int i = 1; i < MainOptList.GetNumOfElements(); i++ )
  {
    MainOptList.Next();
    TempElement = MainOptList.GetElement();
    SizeRect.left = Min( SizeRect.left, TempElement->m_ObjectRegion.left );
    SizeRect.right = Max( SizeRect.right, TempElement->m_ObjectRegion.right );
    SizeRect.bottom = Max( SizeRect.bottom, TempElement->m_ObjectRegion.bottom );
    SizeRect.top = Min( SizeRect.top, TempElement->m_ObjectRegion.top );
  }
  
  return SizeRect;
}//GetSystemSize
//////////////////////////////////////////////////////////////////////////////
void OptimizeSystemLocation( int x, int y )
{
  CRect Rect;
  Rect = GetSystemSize();
  MainOptList.GoToStart();
  
  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    if( GetOptObjectType( MainOptList.GetElement() ) != T_LIGHTSEGMENT )
      MainOptList.GetElement()->ParallelMove( x - Rect.left, y - Rect.top );
    
    MainOptList.Next();
  }
}
//////////////////////////////////////////////////////////////////////////////
void ValidateLightSegments( CLightSource* LSource )
{
  CLightSegment* TempLSegment;
  int n = GetObjectNumber( ( COptObject * )LSource );
  MainOptList.GoToStart();

  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    if( GetOptObjectType( MainOptList.GetElement() ) == T_LIGHTSEGMENT )
    {
      TempLSegment = ( CLightSegment* )( LPVOID( MainOptList.GetElement() ));

      if( LSource == TempLSegment->m_End1 || LSource == TempLSegment->m_End2 )
        MainOptList.RemoveCurrentElement();
    }

    MainOptList.Next();
  }

  MainOptList.FreeAccess( n );
}
//////////////////////////////////////////////////////////////////////////////
int GetObjectNumber( COptObject* Object )
{
  MainOptList.GoToStart();

  for( int i = 0; i < MainOptList.GetNumOfElements(); i++ )
  {
    if( MainOptList.GetElement() == Object )
      return i;

    MainOptList.Next();
  }
  return -1;
}