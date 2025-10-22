// Dlg_path_to_acad.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_path_to_acad.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_path_to_acad dialog


Dlg_path_to_acad::Dlg_path_to_acad(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_path_to_acad::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_path_to_acad)
	m_PathString = _T("");
	//}}AFX_DATA_INIT
}


void Dlg_path_to_acad::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_path_to_acad)
	DDX_Text(pDX, IDC_EDIT1, m_PathString);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_path_to_acad, CDialog)
	//{{AFX_MSG_MAP(Dlg_path_to_acad)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_path_to_acad message handlers
