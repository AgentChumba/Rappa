#if !defined(AFX_D_LINZ1_H__997F7899_892C_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_D_LINZ1_H__997F7899_892C_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// D_linz1.h : header file
//

#include "linza.h"
/////////////////////////////////////////////////////////////////////////////
// D_linz1 dialog

class D_linz1 : public CDialog
{
// Construction
public:
	D_linz1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(D_linz1)
	enum { IDD = IDD_LINZ1 };
	double	m_r1;
	double	m_r2;
	double	m_t;
	double	m_h;
	double	m_mastb;
//	BOOL m_skl1;
//	BOOL m_skl2;
	//}}AFX_DATA

	linza_single LinzaInDlg;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(D_linz1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(D_linz1)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_D_LINZ1_H__997F7899_892C_11D2_AA49_006052052EA5__INCLUDED_)
