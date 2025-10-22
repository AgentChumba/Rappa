// AutoOpticView.h : interface of the CAutoOpticView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOOPTICVIEW_H__3F397CD0_959A_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_AUTOOPTICVIEW_H__3F397CD0_959A_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoOpticDoc.h"

class CAutoOpticCntrItem;

class CAutoOpticView : public CScrollView
{
protected: // create from serialization only
	CAutoOpticView();
	DECLARE_DYNCREATE(CAutoOpticView)

// Attributes
public:
	CAutoOpticDoc* GetDocument();
	// m_pSelection holds the selection to the current CAutoOpticCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CAutoOpticCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CAutoOpticCntrItem* m_pSelection;
/*protected:
	CString m_ClassName;*/
// Operations
private:
	COleDispatchDriver m_app;
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoOpticView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAutoOpticView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoOpticView)
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnLinz();
	afx_msg void OnAbvCallDlg();
	afx_msg void OnAbvMakeFile();
	afx_msg void OnAprac();
	afx_msg void OnMenuInsLinz();
	afx_msg void OnMenuDelLinz();
	afx_msg void OnUpdateAprac(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuInsLinz(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuDelLinz(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAbvMakeFile(CCmdUI* pCmdUI);
	afx_msg void OnMenuiloadexcel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AutoOpticView.cpp
inline CAutoOpticDoc* CAutoOpticView::GetDocument()
   { return (CAutoOpticDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOOPTICVIEW_H__3F397CD0_959A_11D2_AA49_006052052EA5__INCLUDED_)
