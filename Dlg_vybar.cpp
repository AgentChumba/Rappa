// Dlg_vybar.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_vybar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_vybar dialog


Dlg_vybar::Dlg_vybar(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_vybar::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_vybar)
		// NOTE: the ClassWizard will add member initialization here
	m_sH = _T("");
	m_sPR = _T("");
	m_sR1 = _T("");
	m_sR2 = _T("");
	m_sT = _T("");
	m_SpinString = _T("");
	//}}AFX_DATA_INIT
}


void Dlg_vybar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_vybar)
	DDX_Text(pDX, IDC_ST_H, m_sH);
	DDX_Text(pDX, IDC_ST_PR, m_sPR);
	DDX_Text(pDX, IDC_ST_R1, m_sR1);
	DDX_Text(pDX, IDC_ST_R2, m_sR2);
	DDX_Text(pDX, IDC_ST_T, m_sT);
	DDX_Text(pDX, IDC_LINZNAMBDEL, m_SpinString);
	//}}AFX_DATA_MAP
}



BEGIN_MESSAGE_MAP(Dlg_vybar, CDialog)
	//{{AFX_MSG_MAP(Dlg_vybar)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_vybar message handlers
void Dlg_vybar::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
		if ((m_Dlg_LinzaToMal->GetUpperBound())>=0){
		linza_in_objektiv* LINZA;
		CSpinButtonCtrl* pSpin=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
		int ipos=(int)nPos;
			LINZA=m_Dlg_LinzaToMal->GetAt(ipos);
			NumToDel=ipos;  /// захоҐваем б€гучы нумар дл€ выдаленн€
			m_SpinString.Format("%d",++ipos);
		
		m_sR1.Format("%3.3f",LINZA->radius1);
		m_sR2.Format("%3.3f",LINZA->radius2);
		m_sH.Format("%3.3f",LINZA->vysh);
		m_sT.Format("%3.3f",LINZA->tausczyna);
		m_sPR.Format("%3.3f",LINZA->pramejutak);
	UpdateData(FALSE);
			};
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL Dlg_vybar::OnInitDialog() 
{
	
	// TODO: Add extra initialization here
		CSpinButtonCtrl* pSpin=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);

		if ((m_Dlg_LinzaToMal->GetUpperBound())>=0){
	
			int iRange=m_Dlg_LinzaToMal->GetUpperBound();
	
			///  зараз  будзе пачынацца з першага
		linza_in_objektiv* LINZA=m_Dlg_LinzaToMal->GetAt((int)0);
	//		iG_posit=(int)0;
		m_sR1.Format("%3.3f",LINZA->radius1);
		m_sR2.Format("%3.3f",LINZA->radius2);
		m_sH.Format("%3.3f",LINZA->vysh);
		m_sT.Format("%3.3f",LINZA->tausczyna);
		m_sPR.Format("%3.3f",LINZA->pramejutak);
		
	UpdateData(FALSE);
		/// зараз вызначаецца прамежутак пракрутк≥
		pSpin->SetRange(0,iRange);
		pSpin->SetPos((int) 0);
		NumToDel=0;
		m_SpinString.Format("%d",(int)1);
		}
	else pSpin->SetRange(0,0);

		CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
