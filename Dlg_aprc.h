#if !defined(AFX_DLG_APRC_H__CA168562_89C2_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_DLG_APRC_H__CA168562_89C2_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_aprc.h : header file
//

#include <afxwin.h>
#include "linza.h"

/////////////////////////////////////////////////////////////////////////////
// Dlg_aprc dialog

class Dlg_aprc : public CDialog
{
// Construction
public:
	Dlg_aprc(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dlg_aprc)
	enum { IDD = IDD_APRACOUKA };
	CComboBox	m_combmater;
	CComboBox	m_comb6;
	CComboBox	m_comb5;
	CComboBox	m_comb4;
	CComboBox	m_comb3;
	CComboBox	m_comb2;
	CComboBox	m_comb1;
	CString	m_dop;
	CString	m_pasadk;
	double	m_dacentr;
	BOOL	m_check1;
	BOOL	m_check2;
	CString	m_str1;
	CString	m_str2;
	CString	m_str3;
	CString	m_str4;
	CString	m_namb;
	CString	m_mash;
	CString	m_f;
	CString	m_fplus;
	CString	m_sf;
	CString	m_sfshtr;
	CString	m_sfshtrplus;
	CString	m_oda;
	CString	m_odb;
	CString	m_markaSkla;
	//}}AFX_DATA

	linza_single* LinzaInDlg2;
	CString material;
	CString farmat;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_aprc)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
// Implementation
protected:
	void InitInsertPoint(linza_single* pLinzSin, double R, double h, double x, double y, double xsmesz);
	void InitDecPoint(linza_single* Linz,double R, CString block);
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_aprc)
	afx_msg void OnApracOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelAprac();
	afx_msg void OnCheck1Prasv();
	afx_msg void OnCheck2Prasv();
	afx_msg void OnRadioA4();
	afx_msg void OnRadioA3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_APRC_H__CA168562_89C2_11D2_AA49_006052052EA5__INCLUDED_)
