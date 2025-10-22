// Dlg_vybar_skl.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_vybar_skl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_vybar_skl dialog


Dlg_vybar_skl::Dlg_vybar_skl(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_vybar_skl::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_vybar_skl)
	m_SpinStringSkleika = _T("");
	m_sL1_R1 = _T("");
	m_sL1_R2 = _T("");
	m_sL1_T = _T("");
	m_sL1_H = _T("");
	m_sL2_R1 = _T("");
	m_sL2_R2 = _T("");
	m_sL2_T = _T("");
	m_sL2_H = _T("");
	m_mastb = 0.0;
	//}}AFX_DATA_INIT
}


void Dlg_vybar_skl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_vybar_skl)
	DDX_Text(pDX, IDC_NUMARSKLEIKI, m_SpinStringSkleika);
	DDX_Text(pDX, IDC_ST_L1_R1, m_sL1_R1);
	DDX_Text(pDX, IDC_ST_L1_R2, m_sL1_R2);
	DDX_Text(pDX, IDC_ST_L1_T, m_sL1_T);
	DDX_Text(pDX, IDC_ST_L1_H, m_sL1_H);
	DDX_Text(pDX, IDC_ST_L2_R1, m_sL2_R1);
	DDX_Text(pDX, IDC_ST_L2_R2, m_sL2_R2);
	DDX_Text(pDX, IDC_ST_L2_T, m_sL2_T);
	DDX_Text(pDX, IDC_ST_L2_H, m_sL2_H);
	DDX_Text(pDX, IDC_EDIT_MASTB, m_mastb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_vybar_skl, CDialog)
	//{{AFX_MSG_MAP(Dlg_vybar_skl)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_vybar_skl message handlers

BOOL Dlg_vybar_skl::OnInitDialog() 
{
		CSpinButtonCtrl* pSpin=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);

		if ((m_Dlg_NaborSkleek->GetUpperBound())>=0){
	
			int iRange=m_Dlg_NaborSkleek->GetUpperBound();
	
			///  зараз  будзе пачынацца з першага
		skleika* SKLEIKA=m_Dlg_NaborSkleek->GetAt((int)0);
		
		if ((SKLEIKA->linza[0])!=NULL){
		m_sL1_R1.Format("%3.3f",SKLEIKA->linza[0]->radius1);
		m_sL1_R2.Format("%3.3f",SKLEIKA->linza[0]->radius2);
		m_sL1_H.Format("%3.3f",SKLEIKA->linza[0]->vysh);
		m_sL1_T.Format("%3.3f",SKLEIKA->linza[0]->tausczyna);
		}
		if ((SKLEIKA->linza[1])!=NULL){
		m_sL2_R1.Format("%3.3f",SKLEIKA->linza[1]->radius1);
		m_sL2_R2.Format("%3.3f",SKLEIKA->linza[1]->radius2);
		m_sL2_H.Format("%3.3f",SKLEIKA->linza[1]->vysh);
		m_sL2_T.Format("%3.3f",SKLEIKA->linza[1]->tausczyna);
		}
		if ((SKLEIKA->linza[2])!=NULL){/*
		m_sL3_R1.Format("%3.3f",SKLEIKA->linza[2]->radius1);
		m_sL3_R2.Format("%3.3f",SKLEIKA->linza[2]->radius2);
		m_sL3_H.Format("%3.3f",SKLEIKA->linza[2]->vysh);
		m_sL3_T.Format("%3.3f",SKLEIKA->linza[2]->tausczyna);*/
		}
	//	m_sPR.Format("%3.3f",SKLEIKA->pramejutak);
		
		UpdateData(FALSE);
		/// зараз вызначаецца прамежутак пракрутк≥
		pSpin->SetRange(0,iRange);
		pSpin->SetPos((int) 0);
		NumToVybar=0;
		m_mastb=1;
		m_SpinStringSkleika.Format("%d",(int)1);
		}
	else pSpin->SetRange(0,0);

		CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Dlg_vybar_skl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
		if ((m_Dlg_NaborSkleek->GetUpperBound())>=0){
		skleika* SKLEIKA;
		CSpinButtonCtrl* pSpin=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
		int ipos=(int)nPos;
			SKLEIKA=m_Dlg_NaborSkleek->GetAt(ipos);
			NumToVybar=ipos;  /// захоҐваем б€гучы нумар дл€ выдаленн€
			m_SpinStringSkleika.Format("%d",++ipos);
	
			if ((SKLEIKA->linza[0])!=NULL){
		m_sL1_R1.Format("%3.3f",SKLEIKA->linza[0]->radius1);
		m_sL1_R2.Format("%3.3f",SKLEIKA->linza[0]->radius2);
		m_sL1_H.Format("%3.3f",SKLEIKA->linza[0]->vysh);
		m_sL1_T.Format("%3.3f",SKLEIKA->linza[0]->tausczyna);
		}
			if ((SKLEIKA->linza[1])!=NULL){
		m_sL2_R1.Format("%3.3f",SKLEIKA->linza[1]->radius1);
		m_sL2_R2.Format("%3.3f",SKLEIKA->linza[1]->radius2);
		m_sL2_H.Format("%3.3f",SKLEIKA->linza[1]->vysh);
		m_sL2_T.Format("%3.3f",SKLEIKA->linza[1]->tausczyna);
		}
		if ((SKLEIKA->linza[2])!=NULL){/*
		m_sL3_R1.Format("%3.3f",SKLEIKA->linza[2]->radius1);
		m_sL3_R2.Format("%3.3f",SKLEIKA->linza[2]->radius2);
		m_sL3_H.Format("%3.3f",SKLEIKA->linza[2]->vysh);
		m_sL3_T.Format("%3.3f",SKLEIKA->linza[2]->tausczyna);*/
		}


			UpdateData(FALSE);

		}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
