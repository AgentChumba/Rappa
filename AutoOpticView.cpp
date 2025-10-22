// AutoOpticView.cpp : implementation of the CAutoOpticView class
//

#include "stdafx.h"
#include "AutoOptic.h"

#include "AutoOpticDoc.h"
#include "CntrItem.h"
#include "AutoOpticView.h"
#include "D_linz1.h "
#include "Dlg_aprc.h "
#include "Dlg_abektv.h "
#include "Dlg_newln.h "
#include "Dlg_del_linz.h "
#include "Dlg_ins_linz.h "
#include "linza.h"
#include "Dlg_vybar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticView

IMPLEMENT_DYNCREATE(CAutoOpticView, CScrollView)

BEGIN_MESSAGE_MAP(CAutoOpticView, CScrollView)
	//{{AFX_MSG_MAP(CAutoOpticView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_COMMAND(ID_Linz, OnLinz)
	ON_COMMAND(ID_ABV, OnAbvCallDlg)
	ON_COMMAND(ID_AbvMakeFile, OnAbvMakeFile)
	ON_COMMAND(ID_Aprac, OnAprac)
	ON_COMMAND(ID_MenuInsLinz, OnMenuInsLinz)
	ON_COMMAND(ID_MenuDelLinz, OnMenuDelLinz)
	ON_UPDATE_COMMAND_UI(ID_Aprac, OnUpdateAprac)
	ON_UPDATE_COMMAND_UI(ID_MenuInsLinz, OnUpdateMenuInsLinz)
	ON_UPDATE_COMMAND_UI(ID_MenuDelLinz, OnUpdateMenuDelLinz)
	ON_UPDATE_COMMAND_UI(ID_AbvMakeFile, OnUpdateAbvMakeFile)
	ON_COMMAND(ID_MENUILOADEXCEL, OnMenuiloadexcel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticView construction/destruction

CAutoOpticView::CAutoOpticView()
{
	m_pSelection = NULL;
	// TODO: add construction code here

}

CAutoOpticView::~CAutoOpticView()
{
}

BOOL CAutoOpticView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
/*		m_ClassName=AfxRegisterWndClass
		(CS_HREDRAW|CS_VREDRAW|WS_MAXIMIZE,0,
		(HBRUSH)::GetStockObject(WHITE_BRUSH),0);
	cs.lpszClass=m_ClassName;*/
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticView drawing

void CAutoOpticView::OnDraw(CDC* pDC)
{
	CAutoOpticDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	// TODO: also draw all OLE items in the document

	// Draw the selection at an arbitrary position.  This code should be
	//  removed once your real drawing code is implemented.  This position
	//  corresponds exactly to the rectangle returned by CAutoOpticCntrItem,
	//  to give the effect of in-place editing.

	// TODO: remove this code when final draw code is complete.

	if (m_pSelection == NULL)
	{
		POSITION pos = pDoc->GetStartPosition();
		m_pSelection = (CAutoOpticCntrItem*)pDoc->GetNextClientItem(pos);
	}
	if (m_pSelection != NULL)
		m_pSelection->Draw(pDC, CRect(10, 10, 210, 210));

	if ((pDoc->m_NaborLinz.GetUpperBound())>=0){
	int MaxEl=pDoc->m_NaborLinz.GetUpperBound();
			int y=-10;
			int namb=0;
			int Index=0;
			int posit=MaxEl-Index;
			CString SData;
			while ((posit)>=0){

		linza_in_objektiv* LINZA=pDoc->m_NaborLinz.GetAt(Index);

		SData.Format("                               T %3.5f",LINZA->pramejutak);

		pDC->TextOut(0,y,SData); /// выведзе частку дадзеных
				/// аб*екту, €к≥ захоҐваецца Ґ дакуманце

		y=y-50;
		namb=namb+1;
		SData.Format("є %d  R1 %3.3f  R2 %3.3f  T %3.3f H %3.2f",namb,LINZA->radius1,
			LINZA->radius2, LINZA->tausczyna, LINZA->vysh);

		pDC->TextOut(0,y,SData); /// выведзе частку дадзеных
				/// аб*екту, €к≥ захоҐваецца Ґ дакуманце
		y=y-50;
		Index++;
		posit=MaxEl-Index;

	}
	}
	else if ((pDoc->AdnaLinza.created)==(int)123){
	int y=-10;
		linza_single LINZA=pDoc->AdnaLinza;
		CString SVdata;
		SVdata.Format("R1 %3.3f  R2 %3.3f  T %3.3f H %3.2f",
			LINZA.radius1/LINZA.mastb,LINZA.radius2/LINZA.mastb,
			LINZA.tausczyna/LINZA.mastb, LINZA.vysh/LINZA.mastb);

		pDC->TextOut(0,y,SVdata);
	};
}

void CAutoOpticView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
//GetParentFrame()->RecalcLayout();
	
	// TODO: remove this code when final selection model code is written
	m_pSelection = NULL;    // initialize selection

	CSize sizeTotal;
	sizeTotal.cx = 2100;
	sizeTotal.cy = 2970;
	SetScrollSizes(MM_LOMETRIC, sizeTotal);
//	ResizeParentToFit();
	
}

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticView printing

BOOL CAutoOpticView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAutoOpticView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAutoOpticView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CAutoOpticView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CScrollView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CAutoOpticView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CAutoOpticCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CAutoOpticView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CAutoOpticCntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CAutoOpticCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CAutoOpticDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CAutoOpticCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);

		// If item created from class list (not from file) then launch
		//  the server to edit the item.
		if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CAutoOpticView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CAutoOpticView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CScrollView::OnSetFocus(pOldWnd);
}

void CAutoOpticView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticView diagnostics

#ifdef _DEBUG
void CAutoOpticView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAutoOpticView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CAutoOpticDoc* CAutoOpticView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoOpticDoc)));
	return (CAutoOpticDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticView message handlers

void CAutoOpticView::OnLinz() 
{
	// TODO: Add your command handler code here
	CAutoOpticDoc* pDoc=GetDocument();
	D_linz1 LinzDlg;
	LinzDlg.LinzaInDlg=pDoc->AdnaLinza;
	UpdateData(TRUE);
	int result=LinzDlg.DoModal();
	if (result==IDOK)
	{
		/// кал≥ станаҐчы вын≥к зм€ненн€ дадзеных
		
		pDoc->AdnaLinza=LinzDlg.LinzaInDlg; 
		/// у дакуманце будзе захоувацца Ґвесь аб*ект л≥нза
	
			UpdateData(TRUE); 
	Invalidate();	
 OnAprac();
	}
	
	
}

void CAutoOpticView::OnAbvCallDlg() 
{
	// TODO: Add your command handler code here

	CAutoOpticDoc* pDoc=GetDocument();



	Dlg_abektv CreateAb;   //// выкл≥каецца ды€логавае вакно 
						 ///    стварэнн€ аб`ектыву	
	CreateAb.m_LinzyToEdit=&(pDoc->m_NaborLinz);//
	// 
	CreateAb.m_x_orig=pDoc->x_orig;
	CreateAb.m_y_orig=pDoc->y_orig;
	int result=CreateAb.DoModal();
	if (result==IDOK){
		
		pDoc->x_orig=CreateAb.m_x_orig;
		pDoc->y_orig=CreateAb.m_y_orig;
		if (((&CreateAb.m_NovyjaLinzy)->GetSize()>=0) ){
			int MaxEl=(&CreateAb.m_NovyjaLinzy)->GetUpperBound();
			int Index=0;
			int ipos=MaxEl-Index;
			while ((ipos)>=0){
				linza_in_objektiv* LINZA=(&CreateAb.m_NovyjaLinzy)->GetAt(Index);
				linza_in_objektiv* OneNew = new linza_in_objektiv();
				*OneNew = *LINZA;
				pDoc->m_NaborLinz.Add(OneNew);
				//(&CreateAb.m_NovyjaLinzy)->GetNext(pos);
				Index++;
				ipos=MaxEl-Index;
				};
		};
	};
	Invalidate();
	pDoc->UpdateAllViews(NULL,0L,NULL);
}

void CAutoOpticView::OnAbvMakeFile() 
{
	// TODO: Add your command handler code here
	CStdioFile OutFile("dateWR.scr", CFile::modeCreate |CFile::modeWrite);
		OutFile.Close();

		CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
		if ((pDoc->m_NaborLinz.GetUpperBound())>=0){
			double i=pDoc->x_orig;
			double y=pDoc->y_orig;
			int ipos=0;
			int IMaxEl=pDoc->m_NaborLinz.GetUpperBound();
			int razn=IMaxEl-ipos;
			linza_in_objektiv* LINZA;
			int Naklon=45;
			while ((razn)>=0){

		LINZA=pDoc->m_NaborLinz.GetAt(ipos);
		i=i+LINZA->pramejutak;
		LINZA->maluj_kontur(i,y,LINZA);	
		LINZA->sztryhouka(LINZA->pOR,Naklon);

		i=i+LINZA->tausczyna;
		ipos++;
		razn=IMaxEl-ipos;
		Naklon=Naklon+90;
	};
			LINZA->pOL.x=pDoc->x_orig;
			LINZA->maluj_os(LINZA->pOL,LINZA->pOR);
			LINZA->linear_dimension(LINZA->pOL,LINZA->pOR,-100,
				(LINZA->pOR.x-LINZA->pOL.x),"","");
	
			
//		pDoc->path_to_acad="";
//		pDoc->path_to_acad="d:\\autocad R14\\acad";
		pDoc->command_switches="";
		pDoc->command_switches="//nologo /t ";
		pDoc->command_switches+="a_0";
		pDoc->command_switches+=" /b dateWR.scr";
		pDoc->ready=TRUE;
	
			CString msg;
		msg="‘айл згенераваны пасп€хова\nћожна перадаваць у AutoCad";
		AfxMessageBox(msg,MB_ICONINFORMATION);
		}
	
}

void CAutoOpticView::OnAprac() 
{
	// TODO: Add your command handler code here
	Dlg_aprc CreateAprac;

	CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);

	CreateAprac.LinzaInDlg2=&(pDoc->AdnaLinza);
	int result=CreateAprac.DoModal();
	if (result==IDOK)
	{
		Invalidate();
//		pDoc->path_to_acad="";
//		pDoc->path_to_acad="d:\\autocad R14\\acad";
		pDoc->command_switches="";
		pDoc->command_switches="//nologo /t ";
		pDoc->command_switches+=CreateAprac.farmat+CreateAprac.material;
		pDoc->command_switches+=" /b dateWR.scr";
		pDoc->ready=TRUE;
	//command_switches="//nologo /t ";
	};

	if (result==IDCANCEL)
	{
		Invalidate();
		OnLinz();
	};

}



void CAutoOpticView::OnMenuInsLinz() 
{
	// TODO: Add your command handler code here
	CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
		if ((pDoc->m_NaborLinz.GetUpperBound())>=0){
			int MaxEl=pDoc->m_NaborLinz.GetUpperBound();
		Dlg_ins_linz InsLinz;
		InsLinz.iMaxRange=MaxEl;//вызначыл≥ ды€пазон пракрутк≥
	int result=InsLinz.DoModal();
	if (result==IDOK){
		linza_in_objektiv* NovaLn=new linza_in_objektiv(InsLinz.m_PR,InsLinz.m_R1,
								InsLinz.m_R2,InsLinz.m_H,InsLinz.m_T);
		pDoc->m_NaborLinz.InsertAt(InsLinz.PosToIns-1,NovaLn);
	};
		Invalidate();
		};
	
}

void CAutoOpticView::OnMenuDelLinz() 
{
	// TODO: Add your command handler code here
	CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
	if ((pDoc->m_NaborLinz.GetUpperBound())>=0){
		Dlg_del_linz DelLinz;
		DelLinz.m_Dlg_LinzaToDel=&(pDoc->m_NaborLinz);
	int result=DelLinz.DoModal();
	if (result==IDOK){
		delete pDoc->m_NaborLinz.GetAt(DelLinz.NumToDel);
		pDoc->m_NaborLinz.RemoveAt(DelLinz.NumToDel);
		Invalidate();
		pDoc->UpdateAllViews(NULL,0L,NULL);
	}
	}
}

void CAutoOpticView::OnUpdateAprac(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
		BOOL stvorana;
		stvorana=FALSE;
		if(pDoc->AdnaLinza.created==123)stvorana=TRUE;
		pCmdUI->Enable(stvorana);
}

void CAutoOpticView::OnUpdateMenuInsLinz(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
		pCmdUI->Enable((pDoc->m_NaborLinz.GetUpperBound())>=0);
	
}

void CAutoOpticView::OnUpdateMenuDelLinz(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
		pCmdUI->Enable((pDoc->m_NaborLinz.GetUpperBound())>=0);
	
}

void CAutoOpticView::OnUpdateAbvMakeFile(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		CAutoOpticDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
		pCmdUI->Enable((pDoc->m_NaborLinz.GetUpperBound())>=0);
	
}

//void CAutoOpticView::OnMenuVybar() 
//{
	// TODO: Add your command handler code here
//		CAutoOpticDoc* pDoc=GetDocument();
//		ASSERT_VALID(pDoc);
/*	if ((pDoc->m_NaborLinz.GetUpperBound())>=0){
	
		 
	Dlg_vybar dlgVybar;

dlgVybar.m_Dlg_LinzaToDel=&(pDoc->m_NaborLinz);
	
	int result=dlgVybar.DoModal();
		if (result==IDOK){
	
	}
	}*/
		//	Invalidate();
//}

void CAutoOpticView::OnMenuiloadexcel() 
{
	// TODO: Add your command handler code here
	LPDISPATCH pDisp;
   LPUNKNOWN pUnk;
   CLSID clsid;
   TRACE("Entering CEx24dView::OnExcelLoad\n");
   BeginWaitCursor();
   ::CLSIDFromProgID(L"Excel.Application.8", &clsid); // from registry
   if(::GetActiveObject(clsid, NULL, &pUnk) == S_OK) {
// if(::GetActiveObject(excelClsid, NULL, &pUnk) == S_OK) {
      TRACE("attaching\n");
      VERIFY(pUnk->QueryInterface(IID_IDispatch,
            (void**) &pDisp) == S_OK);
      m_app.AttachDispatch(pDisp);
//	  m_app.DoVerb(OLEIVERB_SHOW,this);
      pUnk->Release();
	 // pDisp.Visible=TRUE;
	//  Application.Visible = True
   } 
   else {
      TRACE("creating\n");
      VERIFY(m_app.CreateDispatch("Excel.Application.8") == TRUE);
//    VERIFY(m_app.CreateDispatch(excelClsid) == TRUE);
   }
   EndWaitCursor();
	
}
