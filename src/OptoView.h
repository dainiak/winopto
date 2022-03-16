// OptoView.h : interface of the COptoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPTOVIEW_H__0E204BAB_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
#define AFX_OPTOVIEW_H__0E204BAB_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PriorityDlg.h"
#include "other\globals.h"

class COptoView : public CScrollView
{
protected: // create from serialization only
	COptoView();
	DECLARE_DYNCREATE(COptoView)
  COptObject* m_ActiveObject;
  CPoint m_PrevCoords;
  int m_MouseFlags;
  int m_ClickAccuracy;
  BOOL m_DrawShadow;
  int m_AnimationFrequency;
  CLightSource* m_SelectedLightSource;
  CLightSource* m_AnimationLightSource;
  int m_LSSelectFlag;
  CPriorityDlg m_ObjDlg;
  BOOL m_IsObjDlgActive;
  CString m_CurrentFileName;
  
// Attributes
public:
	COptoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COptoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COptoView)
	afx_msg void OnZoomDecrease();
	afx_msg void OnZoomIncrease();
	afx_msg void OnCreateFlatmirror();
	afx_msg void OnCreateLens();
	afx_msg void OnCreateLightblock();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileNew();
	afx_msg void OnProperties();
	afx_msg void OnCreateLightsource();
	afx_msg void OnSaveColorscheme();
	afx_msg void OnLoadColorscheme();
	afx_msg void OnAnimationStart();
	afx_msg void OnAnimationStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOptimize();
	afx_msg void OnAnimationPause();
	afx_msg void OnZoomFit();
	afx_msg void OnUpdateAnimationStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAnimationStop(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAnimationPause(CCmdUI* pCmdUI);
	afx_msg void OnUpdateZoomDecrease(CCmdUI* pCmdUI);
	afx_msg void OnUpdateZoomFit(CCmdUI* pCmdUI);
	afx_msg void OnUpdateZoomIncrease(CCmdUI* pCmdUI);
	afx_msg void OnCreateLightsegment();
	afx_msg void OnSelectAnimls();
	afx_msg void OnUpdateCreateLightsegment(CCmdUI* pCmdUI);
	afx_msg void OnHideRays();
	afx_msg void OnUpdateHideRays(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSelectAnimls(CCmdUI* pCmdUI);
	afx_msg void OnShowObjdlg();
	afx_msg void OnUpdateShowObjdlg(CCmdUI* pCmdUI);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OptoView.cpp
inline COptoDoc* COptoView::GetDocument()
   { return (COptoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTOVIEW_H__0E204BAB_E5B0_11D5_9494_F9E35B0B261A__INCLUDED_)
