#if !defined(AFX_DLG_DEL_LINZ_H__3738F502_9E69_11D2_AA4A_006052052EA5__INCLUDED_)
#define AFX_DLG_DEL_LINZ_H__3738F502_9E69_11D2_AA4A_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_del_linz.h : header file
//
#include "afxtempl.h"
#include "linza.h"
/////////////////////////////////////////////////////////////////////////////
// Dlg_del_linz dialog

class Dlg_del_linz : public CDialog
{
// Construction
public:
	Dlg_del_linz(CWnd* pParent = NULL);   // standard constructor
	CTypedPtrArray <CObArray, linza_in_objektiv*>* m_Dlg_LinzaToDel;
	int NumToDel;
// Dialog Data
	//{{AFX_DATA(Dlg_del_linz)
	enum { IDD = IDD_DLG_DELLINZ };
	//enum { IDD = IDD_DLG_VYBLINZ };
	CString	m_sH;
	CString	m_sPR;
	CString	m_sR1;
	CString	m_sR2;
	CString	m_sT;
	CString	m_SpinString;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_del_linz)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_del_linz)
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_DEL_LINZ_H__3738F502_9E69_11D2_AA4A_006052052EA5__INCLUDED_)
