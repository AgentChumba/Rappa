// Dlg_aprc.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_aprc.h"
#include "linza.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_aprc dialog


Dlg_aprc::Dlg_aprc(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_aprc::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_aprc)
	m_dop = _T("");
	m_pasadk = _T("");
	m_dacentr = 0.0;
	m_check1 = FALSE;
	m_check2 = FALSE;
	m_str1 = _T("");
	m_str2 = _T("");
	m_str3 = _T("");
	m_str4 = _T("");
	m_namb = _T("");
	m_mash = _T("");
	m_f = _T("");
	m_fplus = _T("");
	m_sf = _T("");
	m_sfshtr = _T("");
	m_sfshtrplus = _T("");
	m_oda = _T("");
	m_odb = _T("");
	farmat="a4";
	material="_zvycz";
	m_markaSkla = _T("");
	//}}AFX_DATA_INIT

}


void Dlg_aprc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_aprc)
	DDX_Control(pDX, IDC_COMBO7, m_combmater);
	DDX_Control(pDX, IDC_COMBO6, m_comb6);
	DDX_Control(pDX, IDC_COMBO5, m_comb5);
	DDX_Control(pDX, IDC_COMBO4, m_comb4);
	DDX_Control(pDX, IDC_COMBO3, m_comb3);
	DDX_Control(pDX, IDC_COMBO2, m_comb2);
	DDX_Control(pDX, IDC_COMBO1, m_comb1);
	DDX_Text(pDX, IDC_EDIT1, m_dop);
	DDX_Text(pDX, IDC_EDIT2, m_pasadk);
	DDX_Text(pDX, IDC_EDIT3, m_dacentr);
	DDX_Check(pDX, IDC_CHECK1, m_check1);
	DDX_Check(pDX, IDC_CHECK2, m_check2);
	DDX_Text(pDX, IDC_EDIT4STR1, m_str1);
	DDX_Text(pDX, IDC_EDIT5STR2, m_str2);
	DDX_Text(pDX, IDC_EDIT6STR3, m_str3);
	DDX_Text(pDX, IDC_EDIT7STR4, m_str4);
	DDX_Text(pDX, IDC_EDIT8, m_namb);
	DDX_Text(pDX, IDC_EDIT9, m_mash);
	DDX_Text(pDX, IDC_EDIT10, m_f);
	DDX_Text(pDX, IDC_EDIT11, m_fplus);
	DDX_Text(pDX, IDC_EDIT12, m_sf);
	DDX_Text(pDX, IDC_EDIT13, m_sfshtr);
	DDX_Text(pDX, IDC_EDIT14, m_sfshtrplus);
	DDX_Text(pDX, IDC_EDIT15, m_oda);
	DDX_Text(pDX, IDC_EDIT16, m_odb);
	DDX_Text(pDX, IDC_EDIT17, m_markaSkla);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_aprc, CDialog)
	//{{AFX_MSG_MAP(Dlg_aprc)
	ON_BN_CLICKED(IDOK, OnApracOK)
	ON_BN_CLICKED(IDCANCEL, OnCancelAprac)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1Prasv)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2Prasv)
	ON_BN_CLICKED(IDC_RADIO1, OnRadioA4)
	ON_BN_CLICKED(IDC_RADIO2, OnRadioA3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg_aprc message handlers



void Dlg_aprc::OnApracOK() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CStdioFile OutFile("dateWR.scr", CFile::modeCreate |CFile::modeWrite);
	OutFile.Close();
//	linza_single* P_to_linza=&linzaOne;
	linza_single* P_to_linza=LinzaInDlg2;

	LinzaInDlg2->maluj_kontur(70,200,LinzaInDlg2);

	
	LinzaInDlg2->radius_dimension(LinzaInDlg2->pOL,LinzaInDlg2->vysh,
		LinzaInDlg2->radius1/LinzaInDlg2->mastb);
	LinzaInDlg2->radius_dimension(LinzaInDlg2->pOR,LinzaInDlg2->vysh,
		LinzaInDlg2->radius2/LinzaInDlg2->mastb);

	LinzaInDlg2->linear_dimension(LinzaInDlg2->pointA, LinzaInDlg2->pointB,
		30,(LinzaInDlg2->pointB.x-LinzaInDlg2->pointA.x)/LinzaInDlg2->mastb,"","*");
	// памеры па краю

	LinzaInDlg2->linear_dimension(LinzaInDlg2->pOL, LinzaInDlg2->pOR,
		((int)(-LinzaInDlg2->vysh)-12),(LinzaInDlg2->pOR.x-LinzaInDlg2->pOL.x)/LinzaInDlg2->mastb,"","%%p"+m_dop);
	// памеры па таҐшчыне

	LinzaInDlg2->linear_dimension(LinzaInDlg2->pointB, LinzaInDlg2->pointD,
		52,(LinzaInDlg2->pointB.y-LinzaInDlg2->pointD.y)/LinzaInDlg2->mastb,"%%c",m_pasadk);
	// памеры па ды€метру


   
	if (LinzaInDlg2->radius1){
		if (LinzaInDlg2->radius2){

		if ((LinzaInDlg2->radius1*LinzaInDlg2->radius2)>0){
	// памеры па агульнай таҐшчыне
			int smesz;
			if (LinzaInDlg2->pointC.x<LinzaInDlg2->pOL.x){
			LinzaInDlg2->kl=LinzaInDlg2->pointC;
			smesz=-20;}
			else {
				LinzaInDlg2->kl=LinzaInDlg2->pOL;
				smesz=-(int)(LinzaInDlg2->vysh)-20;}
			if (LinzaInDlg2->pointD.x>LinzaInDlg2->pOR.x)
			LinzaInDlg2->kp=LinzaInDlg2->pointD;
			else LinzaInDlg2->kp=LinzaInDlg2->pOR;
		LinzaInDlg2->linear_dimension(LinzaInDlg2->kl, LinzaInDlg2->kp,
		smesz,(LinzaInDlg2->kp.x-LinzaInDlg2->kl.x)/LinzaInDlg2->mastb,"","*");
		}
		}
	}

	
	LinzaInDlg2->sztryhouka(LinzaInDlg2->pOR,45);


	if(LinzaInDlg2->radius1<0) LinzaInDlg2->maluj_line(LinzaInDlg2->pointA, LinzaInDlg2->pointC);
	if(LinzaInDlg2->radius2>0) LinzaInDlg2->maluj_line(LinzaInDlg2->pointB, LinzaInDlg2->pointD);

	LinzaInDlg2->maluj_os(LinzaInDlg2->pOL,LinzaInDlg2->pOR);

	// нанос€цца значк≥ пол≥роҐк≥
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius1, 3.5,
		LinzaInDlg2->pOL.x, LinzaInDlg2->pOL.y, 0);	
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kl,"rzl");
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius2, 3.5,
		LinzaInDlg2->pOR.x, LinzaInDlg2->pOR.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kp,"rzr");

	// нанос€цца значк≥ прасв€тленн€
	if(m_check1==TRUE){
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius1, 15,
		LinzaInDlg2->pOL.x, LinzaInDlg2->pOL.y, -2);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kl,"prasv");}
	if(m_check2==TRUE){
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius2, 15,
		LinzaInDlg2->pOR.x, LinzaInDlg2->pOR.y, 2);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kp,"prasv");}

		// нанос€цца значк≥ базавых паверхн€Ґ
	if(LinzaInDlg2->radius1==0){
	/// база на плоскай першай паверхн≥
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius1, -10.5,
		LinzaInDlg2->pOL.x, LinzaInDlg2->pOL.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kl,"bazal");
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius2, -19,
		LinzaInDlg2->pOR.x, LinzaInDlg2->pOR.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kp,"nobazeb");

	LinzaInDlg2->kins=LinzaInDlg2->pOR;
	InitDecPoint(LinzaInDlg2,
		LinzaInDlg2->radius2, "dacentrav"); 
	}
  else 
		if(LinzaInDlg2->radius2==0){
	/// база на плоскай другой паверхн≥
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius2, -10.5,
		LinzaInDlg2->pOR.x, LinzaInDlg2->pOR.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kp,"bazap");
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius1, -19,
		LinzaInDlg2->pOL.x, LinzaInDlg2->pOL.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kl,"nobazea");

	LinzaInDlg2->kins=LinzaInDlg2->pOL;
	InitDecPoint(LinzaInDlg2,
		LinzaInDlg2->radius1, "dacentrbv"); 
		}
		else 
		if((fabs(LinzaInDlg2->radius2))>(fabs(LinzaInDlg2->radius1))){
	/// база на другой паверхн≥
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius2, -10.5,
		LinzaInDlg2->pOR.x, LinzaInDlg2->pOR.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kp,"bazap");
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius1, -19,
		LinzaInDlg2->pOL.x, LinzaInDlg2->pOL.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kl,"nobazea");

	LinzaInDlg2->kins=LinzaInDlg2->pOL;
	InitDecPoint(LinzaInDlg2,
		LinzaInDlg2->radius1, "dacentrbv"); 
		}
		else {
	/// база на першай паверхн≥
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius1, -10.5,
		LinzaInDlg2->pOL.x, LinzaInDlg2->pOL.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kl,"bazal");
	InitInsertPoint(LinzaInDlg2, LinzaInDlg2->radius2, -19,
		LinzaInDlg2->pOR.x, LinzaInDlg2->pOR.y, 0);
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kp,"nobazeb");

	LinzaInDlg2->kins=LinzaInDlg2->pOR;	
	InitDecPoint(LinzaInDlg2,
		LinzaInDlg2->radius2, "dacentrav"); 
		}

	/// нан€сенне значка базы на ды€метр
		LinzaInDlg2->kp.x=LinzaInDlg2->pointD.x+45;
		LinzaInDlg2->kp.y=LinzaInDlg2->pointD.y;
		LinzaInDlg2->InsertBlock(LinzaInDlg2->kp,"bazadiam");
	
	///// ‘аск≥
	CString StrVugal;
	CString& vugal=StrVugal;
	CString StrFask;
	CString& fask=StrFask;
	
	m_comb3.GetLBText(m_comb3.GetCurSel(),vugal);
	if(StrVugal!=""){
	m_comb1.GetLBText(m_comb1.GetCurSel(),fask);
	LinzaInDlg2->faski(LinzaInDlg2->pointA, -20, 25, StrFask,  StrVugal);
	m_comb2.GetLBText(m_comb2.GetCurSel(),fask);
	LinzaInDlg2->TextStr(LinzaInDlg2->pointA, -36, 28, "+"+StrFask, "standard",2.5,0,6);
	}


	m_comb6.GetLBText(m_comb6.GetCurSel(),vugal);
	if(StrVugal!=""){
	m_comb4.GetLBText(m_comb4.GetCurSel(),fask);
	LinzaInDlg2->faski(LinzaInDlg2->pointB, 20, 25, StrFask,  StrVugal);
	m_comb5.GetLBText(m_comb5.GetCurSel(),fask);
	LinzaInDlg2->TextStr(LinzaInDlg2->pointB, 26, 28, "+"+StrFask,"standard",2.5,0,6);
	}

	/////  тэкставы подп≥с да краслюнка
	LinzaInDlg2->kins.x=30;
	LinzaInDlg2->kins.y=130;
	int istr;
	if (m_str1!=""){
		LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_str1,"R0",5,0,140);}
	if (m_str2!=""){
		istr=1+int((m_str1.GetLength())/40);
		LinzaInDlg2->kins.y=LinzaInDlg2->kins.y-8.4*istr;
		LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_str2,"R0",5,0,140);}
	if (m_str3!=""){
		istr=1+int((m_str2.GetLength())/40);
		LinzaInDlg2->kins.y=LinzaInDlg2->kins.y-8*istr;
		LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_str3,"R0",5,0,140);}
	if (m_str4!=""){
		istr=1+int((m_str3.GetLength())/40);
		LinzaInDlg2->kins.y=LinzaInDlg2->kins.y-8*istr;
		LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_str4,"R0",5,0,140);}
	/////  подп≥с назва машыны
	LinzaInDlg2->kins.x=3;
	LinzaInDlg2->kins.y=150;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_mash,"R0",4,90,20);
	/////  подп≥с Ѕ–ј— верхн≥
	LinzaInDlg2->kins.x=75;
	LinzaInDlg2->kins.y=282;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_namb,"R0",5,180,60);
	
	int deltaX=0;
	if (farmat=="a4")deltaX=0;
	if (farmat=="a3")deltaX=202;
	{
	/////  подп≥с Ѕ–ј— н≥жн≥
	LinzaInDlg2->kins.x=83+deltaX;
	LinzaInDlg2->kins.y=55;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_namb,"R0",5,0,60);
	
	
	
	
	int deltaY=0;
	int deltaKvarcX=0;
	int mater=m_combmater.GetCurSel();
	{
		if (mater==0) {deltaY=-6; material="_zvycz";} ;
		if (mater==1) {deltaY=-15; deltaKvarcX=14; material="_kvarc";};
		if (mater==2) {deltaY=0; material="_fluar";};
	///// f' плюс допуск на €го
	if (m_f!=""){
	LinzaInDlg2->kins.x=170+deltaX;
	LinzaInDlg2->kins.y=181+deltaY;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_f+"%%p"+m_fplus,"R0",4,0,30);
	}
	//// Sf
	//LinzaInDlg2->kins.x=170;
	if (m_sf!=""){
	LinzaInDlg2->kins.y=174+deltaY;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_sf,"R0",4,0,30);
	}

	//// S'f'
	if(m_sfshtr!=""){
	LinzaInDlg2->kins.y=167+deltaY;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_sfshtr+"%%p"+m_sfshtrplus,"R0",4,0,30);
	}

	//// OdA
	if (m_oda!=""){
	LinzaInDlg2->kins.y=160+deltaY;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_oda,"R0",4,0,30);
	}

	//// OdB
	if (m_odb!=""){
	LinzaInDlg2->kins.y=153+deltaY;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_odb,"R0",4,0,30);
	}
	
	if (m_markaSkla!=""){
	LinzaInDlg2->kins.x=114+deltaX+deltaKvarcX;
	LinzaInDlg2->kins.y=19;
	LinzaInDlg2->TextStr(LinzaInDlg2->kins,0,0,m_markaSkla,"R0",5,0,60);
	}
	}
	}
	CDialog::OnOK();
	
	CString msg;
		msg="‘айл згенераваны пасп€хова\nћожна перадаваць у AutoCad";
		AfxMessageBox(msg,MB_ICONINFORMATION);
}

void Dlg_aprc::OnCancelAprac() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CDialog::OnCancel();
}


BOOL Dlg_aprc::OnInitDialog() 
{
		if (LinzaInDlg2->created==123){
		m_dop="0.05";
		m_pasadk="f12";
		m_dacentr=0.03;
	if (LinzaInDlg2->skleivaem1==TRUE) m_check1=FALSE; else m_check1=TRUE;
	if (LinzaInDlg2->skleivaem2==TRUE) m_check2=FALSE; else m_check2=TRUE;
	
	m_namb="Ѕ–ј—";
	m_mash="Ёћ-";
	m_str1="1.* –азмеры дл€ справок";
	m_str2="2. ѕокрытие матовых паверхностей и фасок эмалью ’—-1107√ћ черна€";
	m_str3="3.  - просветление   <0.5";
	m_markaSkla="";
	m_f="";	m_fplus="";
	m_sf="";
	m_sfshtr=""; m_sfshtrplus="";
	m_oda=""; m_odb="";

	}
	CDialog::OnInitDialog();
	if (LinzaInDlg2->created==123){
		m_comb1.AddString("");
		m_comb1.AddString("0.1");
		m_comb1.AddString("0.2");
		m_comb1.AddString("0.3");
		m_comb1.AddString("0.4");
		m_comb1.AddString("0.5");
	m_comb1.AddString("0.7");
	m_comb1.AddString("0.8");
	m_comb1.AddString("1.0");
	m_comb1.AddString("1.2");
	m_comb1.AddString("1.5");
//	m_comb1.SetCurSel(1);

	m_comb2.AddString("");
	m_comb2.AddString("0.1");
	m_comb2.AddString("0.2");
	m_comb2.AddString("0.3");
	m_comb2.AddString("0.5");
	m_comb2.AddString("0.7");
	m_comb2.AddString("0.8");
	m_comb2.AddString("1.0");
	m_comb2.AddString("1.5");
//	m_comb2.SetCurSel(1);

	m_comb3.AddString("");	
	m_comb3.AddString("30");
	m_comb3.AddString("45");
	m_comb3.AddString("60");
	m_comb3.AddString("90");
	m_comb3.SetCurSel(1);


	m_comb4.AddString("");
	m_comb4.AddString("0.1");
	m_comb4.AddString("0.2");
	m_comb4.AddString("0.3");
	m_comb4.AddString("0.4");
	m_comb4.AddString("0.5");
	m_comb4.AddString("0.7");
	m_comb4.AddString("0.8");
	m_comb4.AddString("1.0");
	m_comb4.AddString("1.2");
	m_comb4.AddString("1.5");
//	m_comb4.SetCurSel(7);

	m_comb5.AddString("");
	m_comb5.AddString("0.1");
	m_comb5.AddString("0.2");
	m_comb5.AddString("0.3");
	m_comb5.AddString("0.5");
	m_comb5.AddString("0.7");
	m_comb5.AddString("0.8");
	m_comb5.AddString("1.0");
	m_comb5.AddString("1.5");
//	m_comb5.SetCurSel(7);

	m_comb6.AddString("");	
	m_comb6.AddString("30");
	m_comb6.AddString("45");
	m_comb6.AddString("60");
	m_comb6.AddString("90");
	m_comb6.SetCurSel(4);
		
	if(m_check1==TRUE){
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<10){
		m_comb1.SetCurSel(1);
		m_comb2.SetCurSel(2);}
		else if (diam<18){
			m_comb1.SetCurSel(2);
			m_comb2.SetCurSel(2);}
		else if (diam<50){
			m_comb1.SetCurSel(3);
			m_comb2.SetCurSel(3);}
		else if (diam<120){
			m_comb1.SetCurSel(5);
			m_comb2.SetCurSel(4);}
		else if (diam<260){
			m_comb1.SetCurSel(6);
			m_comb2.SetCurSel(5);}
		else if (diam<360){
			m_comb1.SetCurSel(8);
			m_comb2.SetCurSel(6);}
		else if (diam<500){
			m_comb1.SetCurSel(9);
			m_comb2.SetCurSel(7);}
		else {
			m_comb1.SetCurSel(10);
			m_comb2.SetCurSel(8);}
	}else {
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<18){
		m_comb1.SetCurSel(1);
		m_comb2.SetCurSel(2);}
		else if (diam<80){
			m_comb1.SetCurSel(2);
			m_comb2.SetCurSel(2);}
		else if (diam<260){
			m_comb1.SetCurSel(3);
			m_comb2.SetCurSel(3);}
		else if (diam<360){
			m_comb1.SetCurSel(5);
			m_comb2.SetCurSel(4);}
		else if (diam<500){
			m_comb1.SetCurSel(7);
			m_comb2.SetCurSel(6);}
		else {
			m_comb1.SetCurSel(8);
			m_comb2.SetCurSel(7);}
	};

	if(m_check2==TRUE){
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<10){
		m_comb4.SetCurSel(1);
		m_comb5.SetCurSel(2);}
		else if (diam<18){
			m_comb4.SetCurSel(2);
			m_comb5.SetCurSel(2);}
		else if (diam<50){
			m_comb4.SetCurSel(3);
			m_comb5.SetCurSel(3);}
		else if (diam<120){
			m_comb4.SetCurSel(5);
			m_comb5.SetCurSel(4);}
		else if (diam<260){
			m_comb4.SetCurSel(6);
			m_comb5.SetCurSel(5);}
		else if (diam<360){
			m_comb4.SetCurSel(8);
			m_comb5.SetCurSel(6);}
		else if (diam<500){
			m_comb4.SetCurSel(9);
			m_comb5.SetCurSel(7);}
		else {
			m_comb4.SetCurSel(10);
			m_comb5.SetCurSel(8);}
	}else {
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<18){
		m_comb4.SetCurSel(1);
		m_comb5.SetCurSel(2);}
		else if (diam<80){
			m_comb4.SetCurSel(2);
			m_comb5.SetCurSel(2);}
		else if (diam<260){
			m_comb4.SetCurSel(3);
			m_comb5.SetCurSel(3);}
		else if (diam<360){
			m_comb4.SetCurSel(5);
			m_comb5.SetCurSel(4);}
		else if (diam<500){
			m_comb4.SetCurSel(7);
			m_comb5.SetCurSel(6);}
		else {
			m_comb4.SetCurSel(8);
			m_comb5.SetCurSel(7);}
	};

	if (LinzaInDlg2->radius1==0)
	m_comb3.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius1)<0.6)
	m_comb3.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius1)<1.5){
		if(LinzaInDlg2->radius1>0) m_comb3.SetCurSel(1); else m_comb3.SetCurSel(3);
	}else {
		if(LinzaInDlg2->radius1>0){
		m_comb1.SetCurSel(0);
		m_comb2.SetCurSel(0);
		m_comb3.SetCurSel(0);}
		else m_comb3.SetCurSel(4);} 

	if (LinzaInDlg2->radius2==0)
	m_comb6.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius2)<0.6)
	m_comb6.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius2)<1.5){
		if(LinzaInDlg2->radius2<0) m_comb6.SetCurSel(1); else m_comb6.SetCurSel(3);
	}else {
		if(LinzaInDlg2->radius2<0){
		m_comb4.SetCurSel(0);
		m_comb5.SetCurSel(0);
		m_comb6.SetCurSel(0);}
		else m_comb6.SetCurSel(4);} 
	
	
	//// ≥н≥цы€л≥зацы€ матэр'€лу
	m_combmater.AddString("Ўкло");
	m_combmater.AddString(" варц");
	m_combmater.AddString("‘люарыт");
	m_combmater.SetCurSel(0);
}
		//// ≥н≥цы€л≥зацы€ факусоҐ ≥ св ды€метраҐ
		m_f="";
		m_fplus="";
		m_sf="";
		m_sfshtr="";
		m_sfshtrplus="";
		m_oda="";
		m_odb="";

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void Dlg_aprc::InitInsertPoint(linza_single* pLinzSin,double R, double h, double x, double y, double xsmesz)

//// вызначае кропку ҐстаҐк≥ блокаҐ кшталту прасв€тленне, Rz	
{
	// xsmesz вызначае на скольк≥ адступ≥ць у бок, напрыклад пры прасв€тленн≥
	// h перадае на скольк≥ адступ≥ць па Y
	// x,y н€суць ≥нфармацыю аб полюснай кропцы дуг≥

	double delta_x;
	//double y;
	if(R<0) 
	{
		delta_x=R+sqrt((R*R)-(h*h))+xsmesz;
	//	y=h;
		//y2=h;
	}
	else
	if(R>0)
	{
		delta_x=R-sqrt((R*R)-(h*h))+xsmesz;
	//	y=h;
		//y2=-h;
	}
	else
	{
		delta_x=xsmesz;
	//	y=h;
	//	y2=h;
	}

	/// двум кропкам, куды можна устаҐл€ць,
	/// првсвайваем адное й тоеж значэнне
	pLinzSin->kl.x=x+delta_x;
	pLinzSin->kl.y=y+h;

	pLinzSin->kp.x=x+delta_x;
	pLinzSin->kp.y=y+h;
	
	}

void Dlg_aprc::InitDecPoint(linza_single* Linz,double R,CString block)
	 
/// 
{// linz* kkk
	// 
	double Delta;
	double xtext,ytext;
		if(R>0)
		{Delta=50;
		Linz->kins.x=Linz->pOR.x+Delta;
		Linz->kins.y=Linz->pOL.y;
		Linz->InsertBlock(Linz->kins,block);

			xtext=Linz->kins.x-23;
			ytext=Linz->kins.y-18.7;
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			CString OutString;
			OutFile.SeekToEnd();
				OutFile.WriteString("-mtext\n");
	OutString.Format("%3.3f,%3.3f\n",
		xtext, ytext);
	OutFile.WriteString(OutString);
OutString.Format("style\n%s\nheight\n%d\nrotation\n%d\nwidth\n%d\n",
		"standard",(int)3,(int)0,(int)12);
	OutFile.WriteString(OutString);
	
	//OutFile.WriteString("width\n15\n");
		OutString.Format("%1.2f\n\n",m_dacentr);
	OutFile.WriteString(OutString);

		}
		else 
		{
			Delta=-50;
			Linz->kins.x=Linz->pOL.x+Delta;
			Linz->kins.y=Linz->pOL.y;
			Linz->InsertBlock(Linz->kins,block+"1");
		
		xtext=Linz->kins.x+12;
			ytext=Linz->kins.y-18.7;
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			CString OutString;
			OutFile.SeekToEnd();
				OutFile.WriteString("-mtext\n");
	OutString.Format("%3.3f,%3.3f\n",
		xtext, ytext);
	OutFile.WriteString(OutString);
	OutString.Format("style\n%s\nheight\n%d\nrotation\n%d\nwidth\n%d\n",
		"standard",(int)3,(int)0,(int)12);
	OutFile.WriteString(OutString);
	//OutFile.WriteString("width\n15\n");
		OutString.Format("%1.2f\n\n",m_dacentr);
	OutFile.WriteString(OutString);}

}


void Dlg_aprc::OnCheck1Prasv() 
{ 
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	if(m_check1==TRUE){
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<10){
		m_comb1.SetCurSel(1);
		m_comb2.SetCurSel(2);}
		else if (diam<18){
			m_comb1.SetCurSel(2);
			m_comb2.SetCurSel(2);}
		else if (diam<50){
			m_comb1.SetCurSel(3);
			m_comb2.SetCurSel(3);}
		else if (diam<120){
			m_comb1.SetCurSel(5);
			m_comb2.SetCurSel(4);}
		else if (diam<260){
			m_comb1.SetCurSel(6);
			m_comb2.SetCurSel(5);}
		else if (diam<360){
			m_comb1.SetCurSel(8);
			m_comb2.SetCurSel(6);}
		else if (diam<500){
			m_comb1.SetCurSel(9);
			m_comb2.SetCurSel(7);}
		else {
			m_comb1.SetCurSel(10);
			m_comb2.SetCurSel(8);}
	}else {
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<18){
		m_comb1.SetCurSel(1);
		m_comb2.SetCurSel(2);}
		else if (diam<80){
			m_comb1.SetCurSel(2);
			m_comb2.SetCurSel(2);}
		else if (diam<260){
			m_comb1.SetCurSel(3);
			m_comb2.SetCurSel(3);}
		else if (diam<360){
			m_comb1.SetCurSel(5);
			m_comb2.SetCurSel(4);}
		else if (diam<500){
			m_comb1.SetCurSel(7);
			m_comb2.SetCurSel(6);}
		else {
			m_comb1.SetCurSel(8);
			m_comb2.SetCurSel(7);}
	};
		
	if (LinzaInDlg2->radius1==0)
	m_comb3.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius1)<0.6)
	m_comb3.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius1)<1.5){
		if(LinzaInDlg2->radius1>0) m_comb3.SetCurSel(1); else m_comb3.SetCurSel(3);
	}else {
		m_comb1.SetCurSel(0);
		m_comb2.SetCurSel(0);
		m_comb3.SetCurSel(0);
	}
}

void Dlg_aprc::OnCheck2Prasv() 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
		if(m_check2==TRUE){
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<10){
		m_comb4.SetCurSel(1);
		m_comb5.SetCurSel(2);}
		else if (diam<18){
			m_comb4.SetCurSel(2);
			m_comb5.SetCurSel(2);}
		else if (diam<50){
			m_comb4.SetCurSel(3);
			m_comb5.SetCurSel(3);}
		else if (diam<120){
			m_comb4.SetCurSel(5);
			m_comb5.SetCurSel(4);}
		else if (diam<260){
			m_comb4.SetCurSel(6);
			m_comb5.SetCurSel(5);}
		else if (diam<360){
			m_comb4.SetCurSel(8);
			m_comb5.SetCurSel(6);}
		else if (diam<500){
			m_comb4.SetCurSel(9);
			m_comb5.SetCurSel(7);}
		else {
			m_comb4.SetCurSel(10);
			m_comb5.SetCurSel(8);}
	}else {
		double diam=(2*LinzaInDlg2->vysh/LinzaInDlg2->mastb);
		if (diam<18){
		m_comb4.SetCurSel(1);
		m_comb5.SetCurSel(2);}
		else if (diam<80){
			m_comb4.SetCurSel(2);
			m_comb5.SetCurSel(2);}
		else if (diam<260){
			m_comb4.SetCurSel(3);
			m_comb5.SetCurSel(3);}
		else if (diam<360){
			m_comb4.SetCurSel(5);
			m_comb5.SetCurSel(4);}
		else if (diam<500){
			m_comb4.SetCurSel(7);
			m_comb5.SetCurSel(6);}
		else {
			m_comb4.SetCurSel(8);
			m_comb5.SetCurSel(7);}
	};

		if (LinzaInDlg2->radius2==0)
	m_comb6.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius2)<0.6)
	m_comb6.SetCurSel(2);
	else if(fabs(2*LinzaInDlg2->vysh/LinzaInDlg2->radius2)<1.5){
		if(LinzaInDlg2->radius2<0) m_comb6.SetCurSel(1); else m_comb6.SetCurSel(3);
	}else {
		m_comb4.SetCurSel(0);
		m_comb5.SetCurSel(0);
		m_comb6.SetCurSel(0);}
}

void Dlg_aprc::OnRadioA4() 
{
	// TODO: Add your control notification handler code here
	farmat="a4";
}

void Dlg_aprc::OnRadioA3() 
{
	// TODO: Add your control notification handler code here
	farmat="a3";
}
