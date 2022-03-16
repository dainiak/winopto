# Microsoft Developer Studio Project File - Name="Opto" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Opto - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Opto.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Opto.mak" CFG="Opto - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Opto - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Opto - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Opto - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Opto - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Opto - Win32 Release"
# Name "Opto - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Other\flatmirror.cpp
# End Source File
# Begin Source File

SOURCE=.\FMirrorPropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GeneralPropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\geometry.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\gfxparamst.cpp
# End Source File
# Begin Source File

SOURCE=.\LBlockPropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\lens.cpp
# End Source File
# Begin Source File

SOURCE=.\LensPropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\lightblock.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\lightsegment.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\lightsource.cpp
# End Source File
# Begin Source File

SOURCE=.\LSourcePropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjPrpDialogs.cpp
# End Source File
# Begin Source File

SOURCE=.\OptimizeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\optkernel.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\optlist.cpp
# End Source File
# Begin Source File

SOURCE=.\Opto.cpp
# End Source File
# Begin Source File

SOURCE=.\Opto.rc
# End Source File
# Begin Source File

SOURCE=.\OptoDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\OptoView.cpp
# End Source File
# Begin Source File

SOURCE=.\PriorityDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Other\rayanimator.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Other\cflatmirror.h
# End Source File
# Begin Source File

SOURCE=.\Other\cgfxparamst.h
# End Source File
# Begin Source File

SOURCE=.\Other\clens.h
# End Source File
# Begin Source File

SOURCE=.\Other\clightblock.h
# End Source File
# Begin Source File

SOURCE=.\Other\clightsegment.h
# End Source File
# Begin Source File

SOURCE=.\Other\clightsource.h
# End Source File
# Begin Source File

SOURCE=.\Other\coptlist.h
# End Source File
# Begin Source File

SOURCE=.\Other\coptobject.h
# End Source File
# Begin Source File

SOURCE=.\Other\crayanimator.h
# End Source File
# Begin Source File

SOURCE=.\FMirrorPropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\GeneralPropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\Other\geometry.h
# End Source File
# Begin Source File

SOURCE=.\Other\globals.h
# End Source File
# Begin Source File

SOURCE=.\LBlockPropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\LensPropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\LSourcePropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\ObjPrpDialogs.h
# End Source File
# Begin Source File

SOURCE=.\Other\optenums.h
# End Source File
# Begin Source File

SOURCE=.\OptimizeDlg.h
# End Source File
# Begin Source File

SOURCE=.\Other\optkernel.h
# End Source File
# Begin Source File

SOURCE=.\Opto.h
# End Source File
# Begin Source File

SOURCE=.\OptoDoc.h
# End Source File
# Begin Source File

SOURCE=.\OptoView.h
# End Source File
# Begin Source File

SOURCE=.\PriorityDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\mainframe3.ico
# End Source File
# Begin Source File

SOURCE=.\res\Opto.ico
# End Source File
# Begin Source File

SOURCE=.\res\Opto.rc2
# End Source File
# Begin Source File

SOURCE=.\res\OptoDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# End Target
# End Project
