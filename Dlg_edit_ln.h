#if !defined(AFX_DLG_EDIT_LN_H__EEA81EA2_98BA_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_DLG_EDIT_LN_H__EEA81EA2_98BA_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_edit_ln.h : header file
//
#include "afxtempl.h"
#include "linza.h"
#include "stdafx.h"
/////////////////////////////////////////////////////////////////////////////
// Dlg_edit_ln dialog

class Dlg_edit_ln : public CDialog
{
// Construction
public:
	Dlg_edit_ln(CWnd* pParent = NULL);   // standard constructor
	CTypedPtrArray <CObArray, linza_in_objektiv*>* m_Dlg_edit_LinzyToEdit;
//	// глабальны (дл€ гэтага ды€логу)
					//	указальн≥к пазыцы≥ л≥нзы
	int iG_posit;

// Dialog Data
	//{{AFX_DATA(Dlg_edit_ln)
	enum { IDD = IDD_DIALOG_EDIT_LINZ };
	double	m_R1;
	double	m_R2;
	double	m_PR;
	CString	m_SpinString;
	double	m_T;
	double	m_H;
	//}}AFX_DATA
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_edit_ln)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_edit_ln)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnOK_EditLinz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_EDIT_LN_H__EEA81EA2_98BA_11D2_AA49_006052052EA5__INCLUDED_)
