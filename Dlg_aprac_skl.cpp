// Dlg_aprac_skl.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_aprac_skl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_aprac_skl dialog


Dlg_aprac_skl::Dlg_aprac_skl(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_aprac_skl::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_aprac_skl)
	m_dop = _T("");
	m_mash = _T("");
	m_namb = _T("");
	m_f = _T("");
	m_fplus = _T("");
	m_sf = _T("");
	m_sfshtr = _T("");
	m_sfshtrplus = _T("");
	m_oda = _T("");
	m_odb = _T("");
	m_str1 = _T("");
	m_str3 = _T("");
	m_str4 = _T("");
	m_str2 = _T("");
	//}}AFX_DATA_INIT
	farmat="a4";
}


void Dlg_aprac_skl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_aprac_skl)
	DDX_Text(pDX, IDC_EDIT1, m_dop);
	DDX_Text(pDX, IDC_EDIT9, m_mash);
	DDX_Text(pDX, IDC_EDIT8, m_namb);
	DDX_Text(pDX, IDC_EDIT10, m_f);
	DDX_Text(pDX, IDC_EDIT11, m_fplus);
	DDX_Text(pDX, IDC_EDIT12, m_sf);
	DDX_Text(pDX, IDC_EDIT13, m_sfshtr);
	DDX_Text(pDX, IDC_EDIT14, m_sfshtrplus);
	DDX_Text(pDX, IDC_EDIT15, m_oda);
	DDX_Text(pDX, IDC_EDIT16, m_odb);
	DDX_Text(pDX, IDC_EDIT4STR1, m_str1);
	DDX_Text(pDX, IDC_EDIT6STR3, m_str3);
	DDX_Text(pDX, IDC_EDIT7STR4, m_str4);
	DDX_Text(pDX, IDC_EDIT5STR2, m_str2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_aprac_skl, CDialog)
	//{{AFX_MSG_MAP(Dlg_aprac_skl)
	ON_BN_CLICKED(IDC_RADIO1, OnRadioA4)
	ON_BN_CLICKED(IDC_RADIO2, OnRadioA3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_aprac_skl message handlers

BOOL Dlg_aprac_skl::OnInitDialog() 
{
	m_dop="0.05";
	/*	m_pasadk="f12";
		m_dacentr=0.03;
	if (LinzaInDlg2->skleivaem1==TRUE) m_check1=FALSE; else m_check1=TRUE;
	if (LinzaInDlg2->skleivaem2==TRUE) m_check2=FALSE; else m_check2=TRUE;
	*/
	m_namb="БРАС";
	m_mash="ЭМ-";
	m_str1="1.* Размеры для справок";
	m_str2="2. Поз. 1 и 2 клеить бальзамином М ГОСТ 14887-80";
	m_str3="3. Покрытие матовых паверхностей и фасок эмалью ХС-1107ГМ черная";
//	m_markaSkla="";


		m_f="";
		m_fplus="";
		m_sf="";
		m_sfshtr="";
		m_sfshtrplus="";
		m_oda="";
		m_odb="";
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Dlg_aprac_skl::OnRadioA4() 
{
	// TODO: Add your control notification handler code here
	farmat="a4";
}

void Dlg_aprac_skl::OnRadioA3() 
{
	// TODO: Add your control notification handler code here
	farmat="a3";
}
