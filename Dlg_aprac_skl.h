#if !defined(AFX_DLG_APRAC_SKL_H__BC6E2F45_53B5_11D3_917A_006052052EA5__INCLUDED_)
#define AFX_DLG_APRAC_SKL_H__BC6E2F45_53B5_11D3_917A_006052052EA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_aprac_skl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dlg_aprac_skl dialog

class Dlg_aprac_skl : public CDialog
{
// Construction
public:
	Dlg_aprac_skl(CWnd* pParent = NULL);   // standard constructor
//	skleika* m_Dlg_LinzaSkl;
// Dialog Data
	//{{AFX_DATA(Dlg_aprac_skl)
	enum { IDD = IDD_DLG_APRAC_SKL };
	CString	m_dop;
	CString	m_mash;
	CString	m_namb;
	CString	m_f;
	CString	m_fplus;
	CString	m_sf;
	CString	m_sfshtr;
	CString	m_sfshtrplus;
	CString	m_oda;
	CString	m_odb;
	CString	m_str1;
	CString	m_str3;
	CString	m_str4;
	CString	m_str2;
	//}}AFX_DATA

CString farmat;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_aprac_skl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_aprac_skl)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioA4();
	afx_msg void OnRadioA3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_APRAC_SKL_H__BC6E2F45_53B5_11D3_917A_006052052EA5__INCLUDED_)
