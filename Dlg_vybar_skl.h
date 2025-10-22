#if !defined(AFX_DLG_VYBAR_SKL_H__BC6E2F41_53B5_11D3_917A_006052052EA5__INCLUDED_)
#define AFX_DLG_VYBAR_SKL_H__BC6E2F41_53B5_11D3_917A_006052052EA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_vybar_skl.h : header file
//

#include "afxtempl.h"
#include "linza.h"
/////////////////////////////////////////////////////////////////////////////
// Dlg_vybar_skl dialog

class Dlg_vybar_skl : public CDialog
{
// Construction
public:
	Dlg_vybar_skl(CWnd* pParent = NULL);   // standard constructor
	CTypedPtrArray <CObArray, skleika*>* m_Dlg_NaborSkleek;
	int NumToVybar;
// Dialog Data
	//{{AFX_DATA(Dlg_vybar_skl)
	enum { IDD = IDD_DLG_VYBAR_SKL };
	CString	m_SpinStringSkleika;
	CString	m_sL1_R1;
	CString	m_sL1_R2;
	CString	m_sL1_T;
	CString	m_sL1_H;
	CString	m_sL2_R1;
	CString	m_sL2_R2;
	CString	m_sL2_T;
	CString	m_sL2_H;
	double	m_mastb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_vybar_skl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_vybar_skl)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_VYBAR_SKL_H__BC6E2F41_53B5_11D3_917A_006052052EA5__INCLUDED_)
