#if !defined(AFX_DLG_PATH_TO_ACAD_H__A915DB41_4592_11D3_917A_006052052EA5__INCLUDED_)
#define AFX_DLG_PATH_TO_ACAD_H__A915DB41_4592_11D3_917A_006052052EA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_path_to_acad.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dlg_path_to_acad dialog

class Dlg_path_to_acad : public CDialog
{
// Construction
public:
	Dlg_path_to_acad(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dlg_path_to_acad)
	enum { IDD = IDD_DLG_PATH_TO_ACAD };
	CString	m_PathString;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg_path_to_acad)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dlg_path_to_acad)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_PATH_TO_ACAD_H__A915DB41_4592_11D3_917A_006052052EA5__INCLUDED_)
