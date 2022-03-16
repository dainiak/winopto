; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLSourcePropertiesDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "opto.h"
LastPage=0

ClassCount=12
Class1=CFMirrorPropertiesDlg
Class2=CGeneralPropertiesDlg
Class3=CLBlockPropertiesDlg
Class4=CLensPropertiesDlg
Class5=CLSourcePropertiesDlg
Class6=CMainFrame
Class7=COptoApp
Class8=CAboutDlg
Class9=COptoDoc
Class10=COptoView
Class11=CPriorityDlg

ResourceCount=10
Resource1=IDD_LIGHTSOURCE
Resource2=IDD_ABOUTBOX
Resource3=IDD_SETPRIORITY
Resource4=IDR_MAINFRAME
Resource5=IDD_FLATMIRROR
Resource6=IDD_LENS
Resource7=IDD_GENERALPROPERTIES
Resource8=IDD_OPTIMIZEDLG
Resource9=IDD_LIGHTBLOCK
Class12=COptimizeDlg
Resource10=IDR_MAINFRAME (English (U.S.))

[CLS:CFMirrorPropertiesDlg]
Type=0
BaseClass=CDialog
HeaderFile=FMirrorPropertiesDlg.h
ImplementationFile=FMirrorPropertiesDlg.cpp
Filter=D
VirtualFilter=dWC

[CLS:CGeneralPropertiesDlg]
Type=0
BaseClass=CDialog
HeaderFile=GeneralPropertiesDlg.h
ImplementationFile=GeneralPropertiesDlg.cpp
LastObject=CGeneralPropertiesDlg
Filter=D
VirtualFilter=dWC

[CLS:CLBlockPropertiesDlg]
Type=0
BaseClass=CDialog
HeaderFile=LBlockPropertiesDlg.h
ImplementationFile=LBlockPropertiesDlg.cpp
Filter=D
VirtualFilter=dWC

[CLS:CLensPropertiesDlg]
Type=0
BaseClass=CDialog
HeaderFile=LensPropertiesDlg.h
ImplementationFile=LensPropertiesDlg.cpp
Filter=D
VirtualFilter=dWC

[CLS:CLSourcePropertiesDlg]
Type=0
BaseClass=CDialog
HeaderFile=LSourcePropertiesDlg.h
ImplementationFile=LSourcePropertiesDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_LS_COLOR

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=ID_FILE_SAVETOWMF

[CLS:COptoApp]
Type=0
BaseClass=CWinApp
HeaderFile=Opto.h
ImplementationFile=Opto.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Opto.cpp
ImplementationFile=Opto.cpp

[CLS:COptoDoc]
Type=0
BaseClass=CDocument
HeaderFile=OptoDoc.h
ImplementationFile=OptoDoc.cpp

[CLS:COptoView]
Type=0
BaseClass=CScrollView
HeaderFile=OptoView.h
ImplementationFile=OptoView.cpp
Filter=C
VirtualFilter=VWC
LastObject=COptoView

[CLS:CPriorityDlg]
Type=0
BaseClass=CDialog
HeaderFile=PriorityDlg.h
ImplementationFile=PriorityDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_OBJLIST

[DLG:IDD_FLATMIRROR]
Type=1
Class=CFMirrorPropertiesDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FMIRROR_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_FMIRROR_X1,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_FMIRROR_Y1,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_FMIRROR_X2,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_FMIRROR_Y2,edit,1350631552

[DLG:IDD_GENERALPROPERTIES]
Type=1
Class=CGeneralPropertiesDlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_DRAWSHADOW,button,1342242819
Control5=IDC_SHOWRAYARROWS,button,1342242819
Control6=IDC_SHOWILS,button,1342242819
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CLICKACCURACY,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_ANIM_FREQ,edit,1350631552
Control11=IDC_STATIC,button,1342177287
Control12=IDC_FMIRROR_COLOR_BUTTON,button,1342242816
Control13=IDC_LBLOCK_COLOR_BUTTON,button,1342242816
Control14=IDC_DIVLENS_COLOR_BUTTON,button,1342242816
Control15=IDC_CONLENS_COLOR_BUTTON,button,1342242816
Control16=IDC_ILSCOLOR,button,1342242816
Control17=IDC_CSEGCOLOR,button,1342242816
Control18=IDC_SEL_COLOR,button,1342242816
Control19=IDC_SELECT_ILS,button,1342242819

[DLG:IDD_LIGHTBLOCK]
Type=1
Class=CLBlockPropertiesDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LBLOCK_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_LBLOCK_X1,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_LBLOCK_Y1,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_LBLOCK_X2,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_LBLOCK_Y2,edit,1350631552

[DLG:IDD_LENS]
Type=1
Class=CLensPropertiesDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LENS_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LENS_X,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_LENS_TOP,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_LENS_BOTTOM,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_LENS_FDIST,edit,1350631552
Control13=IDC_LENS_SHOWMOA,button,1342242819
Control14=IDC_LENS_SHOW_FP,button,1342242819

[DLG:IDD_LIGHTSOURCE]
Type=1
Class=CLSourcePropertiesDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LS_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_LS_X,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_LS_Y,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_LS_ANGLE,edit,1350631552
Control12=IDC_LS_COLOR,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308481
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308353

[DLG:IDD_SETPRIORITY]
Type=1
Class=CPriorityDlg
ControlCount=1
Control1=IDC_OBJLIST,listbox,1352728833

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_CREATE_LENS
Command7=ID_CREATE_FLATMIRROR
Command8=ID_CREATE_LIGHTBLOCK
Command9=ID_CREATE_LIGHTSOURCE
Command10=ID_CREATE_LIGHTSEGMENT
Command11=ID_OPTIMIZE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_SHOW_OBJDLG
Command15=ID_ZOOM_DECREASE
Command16=ID_ZOOM_INCREASE
Command17=ID_ZOOM_FIT
Command18=ID_HIDE_RAYS
Command19=ID_PROPERTIES
Command20=ID_SAVE_COLORSCHEME
Command21=ID_LOAD_COLORSCHEME
Command22=ID_ANIMATION_START
Command23=ID_ANIMATION_STOP
Command24=ID_ANIMATION_PAUSE
Command25=ID_SELECT_ANIMLS
Command26=ID_APP_ABOUT
CommandCount=26

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_ZOOM_INCREASE
Command5=ID_ZOOM_DECREASE
Command6=ID_ZOOM_FIT
Command7=ID_CREATE_LIGHTSOURCE
Command8=ID_CREATE_LIGHTSEGMENT
Command9=ID_CREATE_FLATMIRROR
Command10=ID_CREATE_LENS
Command11=ID_CREATE_LIGHTBLOCK
Command12=ID_ANIMATION_START
Command13=ID_ANIMATION_STOP
Command14=ID_ANIMATION_PAUSE
CommandCount=14

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_SAVE
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_NEXT_PANE
Command9=ID_PREV_PANE
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_EDIT_CUT
Command13=ID_EDIT_UNDO
CommandCount=13

[DLG:IDD_OPTIMIZEDLG]
Type=1
Class=COptimizeDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_OPTIMIZELEFT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_OPTIMIZETOP,edit,1350631552

[CLS:COptimizeDlg]
Type=0
HeaderFile=OptimizeDlg.h
ImplementationFile=OptimizeDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=COptimizeDlg

