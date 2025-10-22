// Dlg_edit_ln.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_edit_ln.h"
#include "linza.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_edit_ln dialog


Dlg_edit_ln::Dlg_edit_ln(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_edit_ln::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_edit_ln)
	m_R1 = 0.0;
	m_R2 = 0.0;
	m_PR = 0.0;
	m_SpinString = _T("");
	m_T = 0.0;
	m_H = 0.0;
	//}}AFX_DATA_INIT
}


void Dlg_edit_ln::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_edit_ln)
	DDX_Text(pDX, IDC_EDIT1, m_R1);
	DDX_Text(pDX, IDC_EDIT2, m_R2);
	DDX_Text(pDX, IDC_EDIT5, m_PR);
	DDX_Text(pDX, IDC_NumbLinzSTATIC, m_SpinString);
	DDX_Text(pDX, IDC_EDIT3, m_T);
	DDX_Text(pDX, IDC_EDIT4, m_H);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_edit_ln, CDialog)
	//{{AFX_MSG_MAP(Dlg_edit_ln)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDOK, OnOK_EditLinz)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_edit_ln message handlers

BOOL Dlg_edit_ln::OnInitDialog() 
{

	
	// TODO: Add extra initialization here
	CSpinButtonCtrl* pSpin=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
		if ((m_Dlg_edit_LinzyToEdit->GetUpperBound())>=0){
//	POSITION pos=m_Dlg_edit_LinzyToEdit->GetHeadPosition();
	
			int iRange=m_Dlg_edit_LinzyToEdit->GetUpperBound();
	
			///  зараз  будзе пачынацца з апошняга
		linza_in_objektiv* LINZA=m_Dlg_edit_LinzyToEdit->GetAt((int)0);
			iG_posit=(int)0;
		m_R1=LINZA->radius1;
		m_R2=LINZA->radius2;
		m_H=LINZA->vysh;
		m_T=LINZA->tausczyna;
		m_PR=LINZA->pramejutak;

		/// зараз вызначаецца прамежутак пракруткі
		pSpin->SetRange(0,iRange);
		pSpin->SetPos((int) 0);
		m_SpinString.Format("%d",(int)1);
		}
	else pSpin->SetRange(0,0);

		CDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void Dlg_edit_ln::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
			if ((m_Dlg_edit_LinzyToEdit->GetUpperBound())>=0){
		linza_in_objektiv* LINZA;
		CSpinButtonCtrl* pSpin=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
		int ipos=(int)nPos;
			LINZA=m_Dlg_edit_LinzyToEdit->GetAt(ipos);
			iG_posit=ipos;/// захоўваем бягучы нумар для рэдагавання
			m_SpinString.Format("%d",++ipos);
		
		m_R1=LINZA->radius1;
		m_R2=LINZA->radius2;
		m_H=LINZA->vysh;
		m_T=LINZA->tausczyna;
		m_PR=LINZA->pramejutak;
	UpdateData(FALSE);
			};
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void Dlg_edit_ln::OnOK_EditLinz() 
{
	// TODO: Add your control notification handler code here
	if ((m_Dlg_edit_LinzyToEdit->GetUpperBound())>=0){
	double* temp;
	UpdateData(TRUE);
	linza_in_objektiv* LINZA=m_Dlg_edit_LinzyToEdit->GetAt(iG_posit);
	temp=&(LINZA->radius1);
	*temp=m_R1;
	LINZA->radius2=m_R2;
		LINZA->vysh=m_H;
		LINZA->tausczyna=m_T;
		LINZA->pramejutak=m_PR;
	};
	Dlg_edit_ln::OnOK();
}
