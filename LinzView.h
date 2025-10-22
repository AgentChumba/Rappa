// LinzView.h : interface of the CMultScrView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTSCRVIEW_H__AD6FC825_C287_11D2_AA4A_006052052EA5__INCLUDED_)
#define AFX_MULTSCRVIEW_H__AD6FC825_C287_11D2_AA4A_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoOpticDoc.h"

class LinzView : public CScrollView
{
protected: // create from serialization only
	LinzView();
	DECLARE_DYNCREATE(LinzView)

// Attributes
public:
	CAutoOpticDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LinzView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~LinzView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(LinzView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in multScrView.cpp
inline CAutoOpticDoc* LinzView::GetDocument()
   { return (CAutoOpticDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTSCRVIEW_H__AD6FC825_C287_11D2_AA4A_006052052EA5__INCLUDED_)
