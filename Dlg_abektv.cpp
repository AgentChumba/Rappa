// Dlg_abektv.cpp : implementation file
//

#include "stdafx.h"
#include "AutoOptic.h"
#include "Dlg_abektv.h"
#include "Dlg_newln.h"
#include "Dlg_edit_ln.h"
#include "linza.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dlg_abektv dialog


Dlg_abektv::Dlg_abektv(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_abektv::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg_abektv)
	m_x_orig = 0.0;
	m_y_orig = 0.0;
	//}}AFX_DATA_INIT
}


void Dlg_abektv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg_abektv)
	DDX_Text(pDX, IDC_EDIT1, m_x_orig);
	DDX_Text(pDX, IDC_EDIT2, m_y_orig);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dlg_abektv, CDialog)
	//{{AFX_MSG_MAP(Dlg_abektv)
	ON_BN_CLICKED(IDC_CALLDLG_ADDLNZ, OnCalldlgAddlnz)
	ON_BN_CLICKED(IDOK, OnOKabektiv)
	ON_BN_CLICKED(IDC_CALLDLG_EDLINZ, OnCalldlgEdlinz)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
void Dlg_abektv::AddOneLinz(linza_in_objektiv* AdnaLn)
{
	linza_in_objektiv* NovaLn=new linza_in_objektiv();
	* NovaLn=* AdnaLn;
	m_NovyjaLinzy.Add(NovaLn);

};

void Dlg_abektv::OnCalldlgAddlnz() 
{
	// TODO: Add your control notification handler code here
	Dlg_newln CreateNewlinz;
		int result=CreateNewlinz.DoModal();
		if (result==IDOK)
		{
	//		///
///////  л≥нза з ды€логавага вакна Dlg_newln дабаҐл€ецца Ґ List
		
		AddOneLinz(CreateNewlinz.newLinz);

		};
		
	}

void Dlg_abektv::OnOKabektiv() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	CDialog::OnOK();
};

void Dlg_abektv::OnCalldlgEdlinz() 
{
	// TODO: Add your control notification handler code here
	Dlg_edit_ln EditLinz;
	EditLinz.m_Dlg_edit_LinzyToEdit=m_LinzyToEdit;
	int result=EditLinz.DoModal();
	
}
