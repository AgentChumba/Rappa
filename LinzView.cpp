// multScrView.cpp : implementation of the CMultScrView class
//

#include "stdafx.h"
//#include "multScr.h"

//#include "multScrDoc.h"
#include "LinzView.h"
#include "linza.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultScrView

IMPLEMENT_DYNCREATE(LinzView, CScrollView)

BEGIN_MESSAGE_MAP(LinzView, CScrollView)
	//{{AFX_MSG_MAP(LinzView)
//	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
//	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
//	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	//}}AFX_MSG_MAP
	// Standard printing commands
	END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultScrView construction/destruction

LinzView::LinzView()
{
	// TODO: add construction code here

}

LinzView::~LinzView()
{
}

BOOL LinzView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);

}

/////////////////////////////////////////////////////////////////////////////
// CMultScrView drawing

void LinzView::OnDraw(CDC* pDC)
{
	CAutoOpticDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	CString outline,str;
/*	int i,j,k;
	j=pDoc->str1.GetLength();
	for(i=0; i<j; i++ ){
		k=pDoc->str1[i]&0x00ff;
		str.Format("%02x ",k);
		outline+=str;
	}
	pDC->TextOut(120,100,outline);

	outline=pDoc->str2;
	pDC->TextOut(0,120,outline);*/

	if ((pDoc->AdnaLinza.created)==(int)123){
	int y=-10;
		linza_single LINZA=pDoc->AdnaLinza;
		CString SVdata;
		SVdata.Format("R1 %3.3f  R2 %3.3f  T %3.3f H %3.2f",
			LINZA.radius1/LINZA.mastb,LINZA.radius2/LINZA.mastb,
			LINZA.tausczyna/LINZA.mastb, LINZA.vysh/LINZA.mastb);

		pDC->TextOut(0,y,SVdata);
	};

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMultScrView printing

BOOL LinzView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void LinzView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void LinzView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMultScrView diagnostics

#ifdef _DEBUG
void LinzView::AssertValid() const
{
	CScrollView::AssertValid();
}

void LinzView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CAutoOpticDoc* LinzView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoOpticDoc)));
	return (CAutoOpticDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultScrView message handlers

void LinzView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CSize sizeTotal;
	sizeTotal.cx = 100;
	sizeTotal.cy = 20;
	SetScrollSizes(MM_LOMETRIC, sizeTotal);
}
