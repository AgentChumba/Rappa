#if !defined(AFX_DLG_ABEKTV_H__3A36F582_8B5F_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_DLG_ABEKTV_H__3A36F582_8B5F_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_abektv.h : header file
//

#include "afxtempl.h"
#include "linza.h"
/////////////////////////////////////////////////////////////////////////////
// Dlg_abektv dialog

class Dlg_abektv : public CDialog
{
// Construction
public:
	Dlg_abektv(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dlg_abektv)
	enum { IDD = IDD_ABEKTV };
	double	m_x_orig;
	double	m_y_orig;
	//}}AFX_DATA

	CTypedPtrArray <CObArray, linza_in_objektiv*> m_NovyjaLinzy;
	CTypedPtrArray <CObArray, linza_in_objektiv*>* m_LinzyToEdit;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_abektv)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	void AddOneLinz(linza_in_objektiv* AdnaLn);
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_abektv)
	afx_msg void OnCalldlgAddlnz();
	afx_msg void OnOKabektiv();
	afx_msg void OnCalldlgEdlinz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_ABEKTV_H__3A36F582_8B5F_11D2_AA49_006052052EA5__INCLUDED_)
