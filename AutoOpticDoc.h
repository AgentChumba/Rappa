// AutoOpticDoc.h : interface of the CAutoOpticDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOOPTICDOC_H__3F397CCE_959A_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_AUTOOPTICDOC_H__3F397CCE_959A_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "linza.h"
#include "afxtempl.h"


class CAutoOpticDoc : public COleDocument
{
protected: // create from serialization only
	CAutoOpticDoc();
	DECLARE_DYNCREATE(CAutoOpticDoc)

// Attributes
public:
	linza_single AdnaLinza;
	skleika* LinzaSkl;
//	CString SData;
	double x_orig;
	double y_orig;
//	double mastbSkl;
	CString path_to_acad;// шл€х дзе знаходз≥цца acad
	CString command_switches;/// параметры дл€ каманднай строчк≥
	BOOL ready;/// файл гатовы дл€ трансл€цы≥
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoOpticDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAutoOpticDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CTypedPtrArray <CObArray, linza_in_objektiv*> m_NaborLinz;
	CTypedPtrArray <CObArray, skleika*> m_NaborSkleek;


protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoOpticDoc)
	afx_msg void OnMenuTransl();
	afx_msg void OnUpdateMenuitemtransl(CCmdUI* pCmdUI);
	afx_msg void OnMenuVybar();
	afx_msg void OnUpdateMenuVybar(CCmdUI* pCmdUI);
	afx_msg void OnMenuZagruzic();
	afx_msg void OnMenuitemNastr();
	afx_msg void OnMenuVybarSkl();
	afx_msg void OnMenuApracSkl();
	afx_msg void OnUpdateMENUVybSkl(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMENUapracSkl(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOOPTICDOC_H__3F397CCE_959A_11D2_AA49_006052052EA5__INCLUDED_)
