// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "AutoOptic.h"

#include "ChildFrm.h"
#include "LinzView.h"
#include "AutoOpticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

//BOOL CChildFrame::OnCreateClient( LPCREATESTRUCT /*lpcs*/,
/*	CCreateContext* pContext)
{
	return m_wndSplitter.Create( this,
		2, 2,                 // TODO: adjust the number of rows, columns
		CSize( 10, 10 ),      // TODO: adjust the minimum pane size
		pContext );
}*/

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	VERIFY(m_wndSplitter.CreateStatic(this,2,1));
	VERIFY(m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CAutoOpticView),CSize(100,185),pContext));
	VERIFY(m_wndSplitter.CreateView(1,0,RUNTIME_CLASS(LinzView),CSize(50,30),pContext));
	
//CMDIFrameWnd::MDINext();
	return TRUE;
//		m_wndSplitter.Create( this,
//		2, 2,                 // TODO: adjust the number of rows, columns
///		CSize( 10, 10 ),      // TODO: adjust the minimum pane size
//		pContext );
//	return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
//	CMDIFrameWnd::MDINext();
//	cs.style =WS_OVERLAPPEDWINDOW&WS_MAXIMIZE;
//	cs.style =WS_MINIMIZE;
/*		m_ClassName=AfxRegisterWndClass
		(CS_HREDRAW|CS_VREDRAW|CS_NOCLOSE,0,
		(HBRUSH)::GetStockObject(WHITE_BRUSH),0);
	cs.lpszClass=m_ClassName;*/
//	HWND hwnd;
//	ShowWindow(SW_MAXIMIZE);
	return CMDIChildWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
