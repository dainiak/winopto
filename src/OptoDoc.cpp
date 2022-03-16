// OptoDoc.cpp : implementation of the COptoDoc class
//

#include "stdafx.h"
#include "Opto.h"

#include "OptoDoc.h"
#include "other\globals.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptoDoc

IMPLEMENT_DYNCREATE(COptoDoc, CDocument)

BEGIN_MESSAGE_MAP(COptoDoc, CDocument)
	//{{AFX_MSG_MAP(COptoDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptoDoc construction/destruction

COptoDoc::COptoDoc()
{
}

COptoDoc::~COptoDoc()
{
}

BOOL COptoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COptoDoc serialization

void COptoDoc::Serialize(CArchive& ar)
{
}

/////////////////////////////////////////////////////////////////////////////
// COptoDoc diagnostics

#ifdef _DEBUG
void COptoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COptoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COptoDoc commands
