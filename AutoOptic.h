// AutoOptic.h : main header file for the AUTOOPTIC application
//

#if !defined(AFX_AUTOOPTIC_H__3F397CC6_959A_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_AUTOOPTIC_H__3F397CC6_959A_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticApp:
// See AutoOptic.cpp for the implementation of this class
//

class CAutoOpticApp : public CWinApp
{
public:
	CAutoOpticApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoOpticApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAutoOpticApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOOPTIC_H__3F397CC6_959A_11D2_AA49_006052052EA5__INCLUDED_)
