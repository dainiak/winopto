#ifndef __OPTENUMS_H__
#define __OPTENUMS_H__

//////////////////////////////////////////////////////////////////////////////
//Optic objects codes enumeration and parameters class
//////////////////////////////////////////////////////////////////////////////
enum OPTICSTYLES           //Optic objects styles enumeration
{
  GS_LIGHTSOURCE,
  GS_RAY,
  GS_RAYARROWS,
  GS_LIGHTBLOCK,
  GS_FLATMIRROR,
  GS_SPHERICALMIRROR,
  GS_CONVERGINGLENS,
  GS_DIVERGINGLENS,
  GS_FOCALPLANES,
  GS_MOA,
  GS_LIGHTSEGMENT
};
//////////////////////////////////////////////////////////////////////////////
enum OPTICOBJECTS          //Optic objects styles enumeration
{
  T_LIGHTSOURCE,
  T_LENS,
  T_FLATMIRROR,
  T_LIGHTBLOCK,
  T_LIGHTSEGMENT
};

#define SHOW_RAY 1
#define HIDE_RAY 0

#define DIR_LR 0
#define DIR_RL 1

#define M_PI 3.141592654

#endif