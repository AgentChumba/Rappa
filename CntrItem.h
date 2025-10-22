// CntrItem.h : interface of the CAutoOpticCntrItem class
//

#if !defined(AFX_CNTRITEM_H__3F397CD3_959A_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_CNTRITEM_H__3F397CD3_959A_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CAutoOpticDoc;
class CAutoOpticView;

class CAutoOpticCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CAutoOpticCntrItem)

// Constructors
public:
	CAutoOpticCntrItem(CAutoOpticDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CAutoOpticDoc* GetDocument()
		{ return (CAutoOpticDoc*)COleClientItem::GetDocument(); }
	CAutoOpticView* GetActiveView()
		{ return (CAutoOpticView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoOpticCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CAutoOpticCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__3F397CD3_959A_11D2_AA49_006052052EA5__INCLUDED_)
