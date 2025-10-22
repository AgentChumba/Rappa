#if !defined(AFX_DLG_NEWLN_H__3A36F584_8B5F_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_DLG_NEWLN_H__3A36F584_8B5F_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_newln.h : header file
//
#include "linza.h"
/////////////////////////////////////////////////////////////////////////////
// Dlg_newln dialog

class Dlg_newln : public CDialog
{
// Construction
public:
	Dlg_newln(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dlg_newln)
	enum { IDD = IDD_DLGNEWLINZ };
	double	m_pr;
	double	m_r1;
	double	m_r2;
	double	m_t;
	double	m_h;
	//}}AFX_DATA


	linza_in_objektiv* newLinz;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_newln)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_newln)
	afx_msg void OnOKNewLinz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_NEWLN_H__3A36F584_8B5F_11D2_AA49_006052052EA5__INCLUDED_)
