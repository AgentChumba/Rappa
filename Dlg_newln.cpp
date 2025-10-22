// Dlg_newln.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_newln.h"
#include "linza.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_newln dialog


Dlg_newln::Dlg_newln(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_newln::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_newln)
	m_pr = 0.0;
	m_r1 = 0.0;
	m_r2 = 0.0;
	m_t = 0.0;
	m_h = 0.0;
	//}}AFX_DATA_INIT
}


void Dlg_newln::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_newln)
	DDX_Text(pDX, IDC_EDIT1, m_pr);
	DDX_Text(pDX, IDC_EDIT2, m_r1);
	DDX_Text(pDX, IDC_EDIT3, m_r2);
	DDX_Text(pDX, IDC_EDIT4, m_t);
	DDX_Text(pDX, IDC_EDIT5, m_h);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_newln, CDialog)
	//{{AFX_MSG_MAP(Dlg_newln)
	ON_BN_CLICKED(IDOK, OnOKNewLinz)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_newln message handlers

void Dlg_newln::OnOKNewLinz() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	linza_in_objektiv OkLinz(m_pr,m_r1,m_r2,m_h,m_t);
	newLinz=&OkLinz;
	
	Dlg_newln::OnOK();
}
