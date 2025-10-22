// D_linz1.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "D_linz1.h"
#include "AutoOpticDoc.h"
#include "AutoOpticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// D_linz1 dialog


D_linz1::D_linz1(CWnd* pParent /*=NULL*/)
	: CDialog(D_linz1::IDD, pParent)
{
	//{{AFX_DATA_INIT(D_linz1)
	m_r1 = 0.0;
	m_r2 = 0.0;
	m_t = 0.0;
	m_h = 0.0;
	m_mastb = 0.0;
	//}}AFX_DATA_INIT
}


void D_linz1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(D_linz1)
	DDX_Text(pDX, IDC_EDIT1, m_r1);
	DDX_Text(pDX, IDC_EDIT2, m_r2);
	DDX_Text(pDX, IDC_EDIT3, m_t);
	DDX_Text(pDX, IDC_EDIT4, m_h);
	DDX_Text(pDX, IDC_EDIT5, m_mastb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(D_linz1, CDialog)
	//{{AFX_MSG_MAP(D_linz1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// D_linz1 message handlers

void D_linz1::OnOK() 
{
	// TODO: Add extra validation here

		UpdateData(TRUE);
	//	COpticDoc* pDoc=GetDocument();
	

		if(m_mastb==0) m_mastb=1;
		m_r1=m_r1*m_mastb;
		m_r2=m_r2*m_mastb;
		m_h=m_h*m_mastb;
		m_t=m_t*m_mastb;
	linza_single linzaOne(m_r1,m_r2,m_h,m_t,m_mastb);
 //   linzaOne.created=123;
   	

	
	
	

	

	//	UpdateData(TRUE);
	
	LinzaInDlg=linzaOne;/// перадаем у пам€ць(аб'екту 
	LinzaInDlg.created=123;	//Ґ класе View) вын≥к≥ напрацаванага	
				//
	CDialog::OnOK();
}

BOOL D_linz1::OnInitDialog() 
{
	
	
	// TODO: Add extra initialization here
	if (LinzaInDlg.created==123){
		m_h=LinzaInDlg.vysh/LinzaInDlg.mastb;
		m_r1=LinzaInDlg.radius1/LinzaInDlg.mastb;
		m_r2=LinzaInDlg.radius2/LinzaInDlg.mastb;
		m_t=LinzaInDlg.tausczyna/LinzaInDlg.mastb;
		m_mastb=LinzaInDlg.mastb;
	UpdateData(FALSE);
	};

	CDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
