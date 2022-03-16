#include "stdafx.h"
#include "Opto.h"
#include "MainFrm.h"
#include "ObjPrpDialogs.h"
#include "LSourcePropertiesDlg.h"
#include "LBlockPropertiesDlg.h"
#include "LensPropertiesDlg.h"
#include "FMirrorPropertiesDlg.h"
#include "other\clens.h"
#include "other\cflatmirror.h"
#include "other\clightblock.h"
#include "other\clightsource.h"

int ChangeLensProperties( LPVOID WhatLens )
{
  CLens* Lens = ( CLens* )WhatLens;
  CLensPropertiesDlg LPDlg;
  LPDlg.m_LensName = Lens->m_Name;
  LPDlg.m_LensX = Lens->m_Lens.m_x1;
  LPDlg.m_LensTop = Lens->m_Lens.m_y1;
  LPDlg.m_LensBottom = Lens->m_Lens.m_y2;
  LPDlg.m_LensFocalDistance = Lens->m_FocalDistance;
  LPDlg.m_ShowFP = Lens->m_ShowFocalPlanes;
  LPDlg.m_ShowMOA = Lens->m_ShowMainOpticAxis;

  if( LPDlg.DoModal() == IDOK )
  {       
    Lens->Create( LPDlg.m_LensX, LPDlg.m_LensTop, LPDlg.m_LensBottom, LPDlg.m_LensFocalDistance );
    Lens->m_Name = LPDlg.m_LensName;
    Lens->m_ShowFocalPlanes = LPDlg.m_ShowFP;
    Lens->m_ShowMainOpticAxis = LPDlg.m_ShowMOA;
    return 1;
  }
  return 0;
}

int ChangeFMirrorProperties( LPVOID WhatFlatMirror )
{
  CFlatMirror* FlatMirror = ( CFlatMirror* )WhatFlatMirror;
  CFMirrorPropertiesDlg FMPDlg;
  FMPDlg.m_MirrorName = FlatMirror->m_Name;
  FMPDlg.m_MirrorX1 = FlatMirror->m_FlatMirror.m_x1;
  FMPDlg.m_MirrorY1 = FlatMirror->m_FlatMirror.m_y1;
  FMPDlg.m_MirrorX2 = FlatMirror->m_FlatMirror.m_x2;
  FMPDlg.m_MirrorY2 = FlatMirror->m_FlatMirror.m_y2;

  if( FMPDlg.DoModal() == IDOK )
  {
    FlatMirror->Create( FMPDlg.m_MirrorX1, FMPDlg.m_MirrorY1, FMPDlg.m_MirrorX2, FMPDlg.m_MirrorY2 );
    FlatMirror->m_Name = FMPDlg.m_MirrorName;
    return 1;
  }
  return 0;
}

int ChangeLBlockProperties( LPVOID WhatLightBlock )
{
  CLightBlock* LightBlock = ( CLightBlock* )WhatLightBlock;
  CLBlockPropertiesDlg LBPDlg;
  LBPDlg.m_BlockName = LightBlock->m_Name;
  LBPDlg.m_BlockX1 = LightBlock->m_Block.m_x1;
  LBPDlg.m_BlockY1 = LightBlock->m_Block.m_y1;
  LBPDlg.m_BlockX2 = LightBlock->m_Block.m_x2;
  LBPDlg.m_BlockY2 = LightBlock->m_Block.m_y2;

  if( LBPDlg.DoModal() == IDOK )
  {
    LightBlock->Create( LBPDlg.m_BlockX1, LBPDlg.m_BlockY1, LBPDlg.m_BlockX2, LBPDlg.m_BlockY2 );
    LightBlock->m_Name = LBPDlg.m_BlockName;
    return 1;
  }
  return 0;
}

int ChangeLSourceProperties( LPVOID WhatLightSource )
{
  CLightSource* LightSource = ( CLightSource* )WhatLightSource;
  CLSourcePropertiesDlg LSPDlg;
  LSPDlg.m_LSName = LightSource->m_Name;
  LSPDlg.m_LSAngle = LightSource->m_RayAngle;
  LSPDlg.m_LSX = LightSource->m_Position.x;
  LSPDlg.m_LSY = LightSource->m_Position.y;
  LSPDlg.m_LSColor = LightSource->m_Color;

  if( LSPDlg.DoModal() == IDOK )
  {
    LightSource->Create( LSPDlg.m_LSX, LSPDlg.m_LSY, LSPDlg.m_LSColor, LSPDlg.m_LSAngle );
    LightSource->m_Name = LSPDlg.m_LSName;
    return 1;
  }
  return 0;
}