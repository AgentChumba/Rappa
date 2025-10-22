// Dlg_ins_linz.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_ins_linz.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_ins_linz dialog


Dlg_ins_linz::Dlg_ins_linz(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_ins_linz::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_ins_linz)
	m_SpinString = _T("");
	m_PR = 0.0;
	m_R1 = 0.0;
	m_R2 = 0.0;
	m_T = 0.0;
	m_H = 0.0;
	//}}AFX_DATA_INIT
//	iMaxRange=MRang;
}


void Dlg_ins_linz::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_ins_linz)
	DDX_Text(pDX, IDC_ST_INS_STR, m_SpinString);
	DDX_Text(pDX, IDC_EDIT1, m_PR);
	DDX_Text(pDX, IDC_EDIT2, m_R1);
	DDX_Text(pDX, IDC_EDIT3, m_R2);
	DDX_Text(pDX, IDC_EDIT4, m_T);
	DDX_Text(pDX, IDC_EDIT5, m_H);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_ins_linz, CDialog)
	//{{AFX_MSG_MAP(Dlg_ins_linz)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_ins_linz message handlers

void Dlg_ins_linz::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	PosToIns=(int)nPos;
	m_SpinString.Format("%d",++PosToIns);
	UpdateData(FALSE);
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL Dlg_ins_linz::OnInitDialog() 
{
	CSpinButtonCtrl* pSpin=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN3);

		/// зараз вызначаецца прамежутак пракруткі
		pSpin->SetRange(0,iMaxRange);
		pSpin->SetPos((int) 0);
		m_SpinString.Format("%d",(int)1);
		/// пачатковае значэнне
		PosToIns=1;
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

