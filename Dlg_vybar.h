#if !defined(AFX_DLG_VYBAR_H__A25CE701_C70F_11D2_AA4A_006052052EA5__INCLUDED_)
#define AFX_DLG_VYBAR_H__A25CE701_C70F_11D2_AA4A_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_vybar.h : header file
//
#include "afxtempl.h"
#include "linza.h"


/////////////////////////////////////////////////////////////////////////////
// Dlg_vybar dialog

class Dlg_vybar : public CDialog
{
// Construction
public:
	Dlg_vybar(CWnd* pParent = NULL);   // standard constructor
	CTypedPtrArray <CObArray, linza_in_objektiv*>* m_Dlg_LinzaToMal;
	int NumToDel;
// Dialog Data
	//{{AFX_DATA(Dlg_vybar)
	enum { IDD = IDD_VYBAR };
	CString	m_sH;
	CString	m_sPR;
	CString	m_sR1;
	CString	m_sR2;
	CString	m_sT;
	CString	m_SpinString;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_vybar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_vybar)
		// NOTE: the ClassWizard will add member functions here
		afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
		virtual BOOL OnInitDialog();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_VYBAR_H__A25CE701_C70F_11D2_AA4A_006052052EA5__INCLUDED_)
