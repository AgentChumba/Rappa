#if !defined(AFX_DLG_INS_LINZ_H__9C1FC5A3_9FC4_11D2_AA4A_006052052EA5__INCLUDED_)
#define AFX_DLG_INS_LINZ_H__9C1FC5A3_9FC4_11D2_AA4A_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_ins_linz.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dlg_ins_linz dialog

class Dlg_ins_linz : public CDialog
{
// Construction
public:
	Dlg_ins_linz(CWnd* pParent = NULL);   // standard constructor
	int iMaxRange;
	int PosToIns;
// Dialog Data
	//{{AFX_DATA(Dlg_ins_linz)
	enum { IDD = IDD_DLG_INSLINZ };
	CString	m_SpinString;
	double	m_PR;
	double	m_R1;
	double	m_R2;
	double	m_T;
	double	m_H;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_ins_linz)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_ins_linz)
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_INS_LINZ_H__9C1FC5A3_9FC4_11D2_AA4A_006052052EA5__INCLUDED_)
