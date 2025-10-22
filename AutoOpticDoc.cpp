// AutoOpticDoc.cpp : implementation of the CAutoOpticDoc class
//

#include "stdafx.h"
#include <afxdlgs.h>
#include "AutoOptic.h"

#include "AutoOpticDoc.h"
#include "CntrItem.h"
#include "process.h"
#include "Dlg_del_linz.h"
#include "Dlg_vybar.h"
#include "Dlg_vybar_skl.h"
#include "Dlg_aprac_skl.h"
#include "Dlg_path_to_acad.h"
#include "AutoOpticView.h"
#include <stdlib.h> 
#include <malloc.h>
#include <math.h>
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticDoc

IMPLEMENT_DYNCREATE(CAutoOpticDoc, COleDocument)

BEGIN_MESSAGE_MAP(CAutoOpticDoc, COleDocument)
	//{{AFX_MSG_MAP(CAutoOpticDoc)
	ON_COMMAND(ID_MENUITEMTRANSL, OnMenuTransl)
	ON_UPDATE_COMMAND_UI(ID_MENUITEMTRANSL, OnUpdateMenuitemtransl)
	ON_COMMAND(ID_MENUVYBAR, OnMenuVybar)
	ON_UPDATE_COMMAND_UI(ID_MENUVYBAR, OnUpdateMenuVybar)
	ON_COMMAND(ID_MENUZAGRUZIC, OnMenuZagruzic)
	ON_COMMAND(ID_MENUITEMNASTR, OnMenuitemNastr)
	ON_COMMAND(ID_MENUVybSkl, OnMenuVybarSkl)
	ON_COMMAND(ID_MENUapracSkl, OnMenuApracSkl)
	ON_UPDATE_COMMAND_UI(ID_MENUVybSkl, OnUpdateMENUVybSkl)
	ON_UPDATE_COMMAND_UI(ID_MENUapracSkl, OnUpdateMENUapracSkl)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, COleDocument::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticDoc construction/destruction

CAutoOpticDoc::CAutoOpticDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here
	x_orig=(double)100;
	y_orig=(double)100;
	LinzaSkl=NULL;
	ready=FALSE;
	
	CStdioFile InFile("path.txt", CFile::modeCreate |CFile::modeNoTruncate|CFile::modeRead);
	InFile.ReadString(path_to_acad);
		InFile.Close();
}

CAutoOpticDoc::~CAutoOpticDoc()
{
}

BOOL CAutoOpticDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
		
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAutoOpticDoc serialization

void CAutoOpticDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	//	m_NaborLinz.Serialize(ar);
	//	m_NaborSkleek.Serialize(ar);
	//	ar<<m_NaborLinz.Serialize(ar)<<m_NaborSkleek.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
	//	m_NaborLinz.Serialize(ar);
	//	m_NaborSkleek.Serialize(ar);
	}
m_NaborLinz.Serialize(ar);
//m_NaborSkleek.Serialize(ar);

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
//	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticDoc diagnostics

#ifdef _DEBUG
void CAutoOpticDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CAutoOpticDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoOpticDoc commands

void CAutoOpticDoc::OnMenuTransl() 
{
	// TODO: Add your command handler code here

	 _spawnlp(_P_WAIT,path_to_acad,command_switches,NULL);
}

void CAutoOpticDoc::OnUpdateMenuitemtransl(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(ready);
}


void CAutoOpticDoc::OnMenuVybar() 
{
	// TODO: Add your command handler code here
		if ((m_NaborLinz.GetUpperBound())>=0){
			 
	Dlg_vybar dlgVybar;

dlgVybar.m_Dlg_LinzaToMal=&(m_NaborLinz);
	
	int result=dlgVybar.DoModal();
		if (result==IDOK){
			//CWnd::Invalidate();
			linza_in_objektiv* LINZA;
	LINZA=m_NaborLinz.GetAt(dlgVybar.NumToDel);
	AdnaLinza.vysh=LINZA->vysh;
	AdnaLinza.radius1=LINZA->radius1;
	AdnaLinza.radius2=LINZA->radius2;
	AdnaLinza.tausczyna=LINZA->tausczyna;
	AdnaLinza.mastb=1;
	AdnaLinza.created=123;
	AdnaLinza.skleivaem1=LINZA->skleivaem1;
	AdnaLinza.skleivaem2=LINZA->skleivaem2;
	}
  	UpdateAllViews(NULL,0L,NULL);
	}
}

void CAutoOpticDoc::OnUpdateMenuVybar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable((m_NaborLinz.GetUpperBound())>=0);
}

void CAutoOpticDoc::OnMenuZagruzic() 
{
	// TODO: Add your command handler code here
//
//
		CFileDialog opDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"(*.atc)|*.atc| (*.txt)|*.txt| (*.*)|*.*|",NULL);
	int result=opDlg.DoModal();
	if (result==IDOK){
		CString name=(const char*)opDlg.GetPathName( );
		CString extension=opDlg.GetFileExt( );
	
	if (extension=="atc"){
			FILE *stream;
			stream = fopen( name, "r+b" );

	short int Namb;
	Namb=1;
	fread( &Namb, 2, 1, stream );
//	int nBytesRead =Expromt.Read(pbuf,2);sizeof( short int )
	double  lll;
	double  liczba;
	
	int colki=(int)Namb;

	double*	Radiusy=(double*) malloc((sizeof( double ))*colki);
	for (int i=0; i<colki; i++){////Запаўняецца масіў радыюсаў
	
		fread( &lll, 8, 1, stream );
		liczba=lll;
	Radiusy[i]=liczba;
	}	

	double* Tausczyny=(double*) malloc((sizeof( double ))*(colki));
//	Tausczyny[0]=0;
	for (i=0; i<(colki); i++){////Запаўняецца масіў таўшчыняў
		fread( &lll, 8, 1, stream );
		liczba=lll;
	Tausczyny[i]=liczba;
	};
//	Tausczyny[colki+1]=0;

	double* Vyszyni=(double*) malloc((sizeof( double ))*colki);
	for (i=0; i<colki; i++){////Запаўняецца масіў вышыняў
		fread( &lll, 8, 1, stream );
		liczba=lll;
	Vyszyni[i]=liczba;
	};

  double* Pakazaln=(double*) malloc((sizeof( double ))*(colki+1));
	for (i=0; i<(colki+1); i++){////Запаўняецца масіў паказальнікаў
		fread( &lll, 8, 1, stream );
		liczba=lll;
	Pakazaln[i]=liczba;
	};
	fclose( stream );
	
////////////////////////////////////////////////////////
double Sreda=Pakazaln[0];
	//// Разбор радыюсаў на склейкі і лінзы
	for (i=0; i<(colki); i++)
	{
		skleika* Skleika=NULL;
		linza_in_objektiv* Linza=NULL;
		//{///if((i+1)<colki){
		if((i+1)<colki)
		{
			if(Pakazaln[i+1]>Sreda)
			{
			if(Pakazaln[i+2]>Sreda){	///склейка
			//	if{(i+2)<colki){
				if(Pakazaln[i+3]>Sreda)
				{///Трайная склейка
					Skleika=new skleika(Tausczyny[i],Radiusy[i],Radiusy[i+1],Radiusy[i+2],Radiusy[i+3],
					Tausczyny[i+1],Tausczyny[i+2],Tausczyny[i+3],Vyszyni[i]);
					i=i+2;
				}
				else
				{
					Skleika=new skleika(Tausczyny[i],Radiusy[i],Radiusy[i+1],Radiusy[i+2],
					Tausczyny[i+1],Tausczyny[i+2],Vyszyni[i]);
					i=i+1;
				}
			}
			else { Linza=new linza_in_objektiv(Tausczyny[i],Radiusy[i],Radiusy[i+1],
					Vyszyni[i],Tausczyny[i+1],FALSE,FALSE);
			};
			}
		};
	
		if(Skleika!=NULL){
		/*	if((Skleika->linza[2])!=NULL){
				///Трайная склейка
					skleika* Skl=new skleika(Tausczyny[i],Radiusy[i],Radiusy[i+1],Radiusy[i+2],Radiusy[i+3],
					Tausczyny[i+1],Tausczyny[i+2],Tausczyny[i+3],Vyszyni[i]);
					i=i+2;
					m_NaborSkleek.Add(Skl);
				}
			else
				{
					skleika* Skl=new skleika(Tausczyny[i],Radiusy[i],Radiusy[i+1],Radiusy[i+2],
					Tausczyny[i+1],Tausczyny[i+2],Vyszyni[i]);
					i=i+1;
					m_NaborSkleek.Add(Skl);
				}*/
			m_NaborSkleek.Add(Skleika);		
			for(int j=0;j<=2;j++){
				if(Skleika->linza[j]!=NULL){
					linza_in_objektiv* Lin=new linza_in_objektiv(Skleika->linza[j]->pramejutak,
						Skleika->linza[j]->radius1,Skleika->linza[j]->radius2,
						Skleika->linza[j]->vysh,Skleika->linza[j]->tausczyna,
						Skleika->linza[j]->skleivaem1,Skleika->linza[j]->skleivaem2);
						m_NaborLinz.Add(Lin);
				}
			}
	//	delete Skleika;
		}else
		if (Linza!=NULL)m_NaborLinz.Add(Linza);
			
	};
free( Pakazaln );
free( Vyszyni );
free( Tausczyny );
	 free( Radiusy );

 } /// end of if extension=="atc"
/////////////////////////////////////////////////////////		
	else if (extension=="txt"){
	/*	CFile Expromt;
	
/////////////////////////////////////////////////////

	 */
	 
	 }//// end of if extension=="txt"

	else return;

	UpdateAllViews(NULL);
	}
}

void CAutoOpticDoc::OnMenuitemNastr() 
{
	// TODO: Add your command handler code here
	Dlg_path_to_acad DlgPath;
	CStdioFile InFile("path.txt", CFile::modeCreate |CFile::modeNoTruncate|CFile::modeRead);
		InFile.ReadString(DlgPath.m_PathString);
		InFile.Close();

	
	int result=DlgPath.DoModal();
		if (result==IDOK){
		CString PathString=DlgPath.m_PathString;
		
		CStdioFile OutFile("path.txt", CFile::modeCreate |CFile::modeWrite);
		OutFile.WriteString(PathString);
		OutFile.Close();
		//PathString.Replace("\" , "\\");
		path_to_acad=DlgPath.m_PathString;
		};
	}


void CAutoOpticDoc::OnMenuVybarSkl() 
{
	if ((m_NaborSkleek.GetUpperBound())>=0){
			 
	Dlg_vybar_skl dlgVybarSkl;

	dlgVybarSkl.m_Dlg_NaborSkleek=&(m_NaborSkleek);
	
	int result=dlgVybarSkl.DoModal();
		if (result==IDOK){
		skleika* SKLEIKA=m_NaborSkleek.GetAt(dlgVybarSkl.NumToVybar);
		if(dlgVybarSkl.m_mastb==0) dlgVybarSkl.m_mastb=1;
	
//	mastbSkl=dlgVybarSkl.m_mastb;
		if((SKLEIKA->linza[3])!=NULL){
			LinzaSkl=new skleika(0,0,0,0,0,0,0,0,0);}
		else{LinzaSkl=new skleika(0,0,0,0,0,0,0);};

	for(int i=0;i<2;i++){
		if ((SKLEIKA->linza[i])!=NULL){
	//	double r=SKLEIKA->linza[i]->radius1;
		((LinzaSkl->linza[i])->radius1)=
			(dlgVybarSkl.m_mastb)*(SKLEIKA->linza[i]->radius1);
		(LinzaSkl->linza[i]->radius2)=
			dlgVybarSkl.m_mastb*(SKLEIKA->linza[i]->radius2);
		LinzaSkl->linza[i]->vysh=
			dlgVybarSkl.m_mastb*(SKLEIKA->linza[i]->vysh);
		LinzaSkl->linza[i]->tausczyna=
			dlgVybarSkl.m_mastb*(SKLEIKA->linza[i]->tausczyna);
		LinzaSkl->mastb=dlgVybarSkl.m_mastb;
		}
		else (LinzaSkl->linza[i])=NULL;
	}
	OnMenuApracSkl();
		}

	
	// TODO: Add your command handler code here
	}
}

void CAutoOpticDoc::OnMenuApracSkl() 
{
	if ((LinzaSkl)!=NULL){
	// TODO: Add your command handler code here
	Dlg_aprac_skl dlgApracSkl;
//	dlgApracSkl.m_Dlg_LinzaSkl=LinzaSkl;
	int result=dlgApracSkl.DoModal();
		if (result==IDOK){
		
		CStdioFile OutFile("dateWR.scr", CFile::modeCreate |CFile::modeWrite);
		OutFile.Close();
	
			double i=70;///
			double y=200;/// пачатковыя каардынаты
			int Naklon=45;// наклон штрыхоўкі
		
			if((LinzaSkl->linza[0])!=NULL){
				LinzaSkl->maluj_kontur(i,y,LinzaSkl->linza[0]);
				LinzaSkl->linza[0]->sztryhouka(LinzaSkl->linza[0]->pOR,Naklon);
				i=i+LinzaSkl->linza[0]->tausczyna;
				Naklon=Naklon+90;
			
	//	};
			if((LinzaSkl->linza[1])!=NULL){
				LinzaSkl->maluj_kontur(i,y,LinzaSkl->linza[1]);
				LinzaSkl->linza[1]->sztryhouka(LinzaSkl->linza[1]->pOR,Naklon);
				i=i+LinzaSkl->linza[1]->tausczyna;
				Naklon=Naklon+90;
			

	LinzaSkl->linza[1]->linear_dimension(LinzaSkl->linza[0]->pOL,
		LinzaSkl->linza[1]->pOR,((int)(-LinzaSkl->linza[1]->vysh)-25),
		(LinzaSkl->linza[1]->pOR.x-LinzaSkl->linza[1]->pOL.x)/LinzaSkl->mastb,
		"","%%p"+dlgApracSkl.m_dop);
	// памеры па таўшчыне

	LinzaSkl->linza[1]->linear_dimension(LinzaSkl->linza[1]->pointB, LinzaSkl->linza[1]->pointD,
		37,(LinzaSkl->linza[1]->pointB.y-LinzaSkl->linza[1]->pointD.y)/LinzaSkl->mastb,
		"%%c","*");
	// памеры па дыяметру

	LinzaSkl->InsertBlock(LinzaSkl->linza[0]->pOR,"sklp2");
	LinzaSkl->linza[0]->pOR.y=LinzaSkl->linza[0]->pOR.y+2;
	LinzaSkl->InsertBlock(LinzaSkl->linza[0]->pOR,"nobazeb");
	LinzaSkl->linza[0]->pOR.y=LinzaSkl->linza[0]->pOR.y-2;

	
	if((fabs(LinzaSkl->linza[1]->radius2))>(fabs(LinzaSkl->linza[0]->radius1))){
		////базавай з*яўляецца апошняя паверхня
		LinzaSkl->InsertBlock(LinzaSkl->linza[0]->pOL,"nobazea");
		LinzaSkl->linza[0]->pOL.x=LinzaSkl->linza[0]->pOL.x-22;
		LinzaSkl->InsertBlock(LinzaSkl->linza[0]->pOL,"cbdacv");
		LinzaSkl->linza[0]->pOL.x=LinzaSkl->linza[0]->pOL.x-20;
		LinzaSkl->InsertBlock(LinzaSkl->linza[0]->pOL,"cadacv");
		LinzaSkl->linza[1]->pOR.y=LinzaSkl->linza[1]->pOR.y+7;
		LinzaSkl->InsertBlock(LinzaSkl->linza[1]->pOR,"bazap");

	} else{
		LinzaSkl->InsertBlock(LinzaSkl->linza[1]->pOR,"nobazev");
		LinzaSkl->linza[1]->pOR.x=LinzaSkl->linza[1]->pOR.x+22;
		LinzaSkl->InsertBlock(LinzaSkl->linza[1]->pOR,"cvdaca");
		LinzaSkl->linza[1]->pOR.x=LinzaSkl->linza[1]->pOR.x+20;
		LinzaSkl->InsertBlock(LinzaSkl->linza[1]->pOR,"cbdaca");
		LinzaSkl->linza[0]->pOL.y=LinzaSkl->linza[0]->pOL.y+7;
		LinzaSkl->InsertBlock(LinzaSkl->linza[0]->pOL,"bazal");
	};
	LinzaSkl->InsertBlock(LinzaSkl->linza[1]->pointD,"bazadiam");
	LinzaSkl->linza[0]->pointA.x=LinzaSkl->linza[0]->pointA.x+2;
	LinzaSkl->linza[0]->pointA.y=LinzaSkl->linza[0]->pointA.y-2;
	LinzaSkl->InsertBlock(LinzaSkl->linza[0]->pointA,"n1");
	///n1
	LinzaSkl->linza[1]->pointB.x=LinzaSkl->linza[1]->pointB.x-2;
	LinzaSkl->linza[1]->pointB.y=LinzaSkl->linza[1]->pointB.y-2;
	LinzaSkl->InsertBlock(LinzaSkl->linza[1]->pointB,"n2");
	///n2
	
//	LinzaSkl->linza[0]->pOR.x=LinzaSkl->linza[0]->pOR.x-40;
//	LinzaSkl->linza[1]->pOL.x=LinzaSkl->linza[1]->pOL.x+40;
	LinzaSkl->maluj_os(LinzaSkl->linza[0]->pOR,LinzaSkl->linza[1]->pOL);
	/// маляванне аптычнай восі


	/////  тэкставы подпіс да краслюнка
	LinzaSkl->kins.x=30;
	LinzaSkl->kins.y=130;
	int istr;
	if (dlgApracSkl.m_str1!=""){
		LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_str1,"R0",5,0,140);}
	if (dlgApracSkl.m_str2!=""){
		istr=1+int((dlgApracSkl.m_str1.GetLength())/40);
		LinzaSkl->kins.y=LinzaSkl->kins.y-8.4*istr;
		LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_str2,"R0",5,0,140);}
	if (dlgApracSkl.m_str3!=""){
		istr=1+int((dlgApracSkl.m_str2.GetLength())/40);
		LinzaSkl->kins.y=LinzaSkl->kins.y-8*istr;
		LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_str3,"R0",5,0,140);}
	if (dlgApracSkl.m_str4!=""){
		istr=1+int((dlgApracSkl.m_str3.GetLength())/40);
		LinzaSkl->kins.y=LinzaSkl->kins.y-8*istr;
		LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_str4,"R0",5,0,140);}
	/////  подпіс назва машыны
	LinzaSkl->kins.x=3;
	LinzaSkl->kins.y=150;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_mash,"R0",4,90,20);
	/////  подпіс БРАС верхні
	LinzaSkl->kins.x=75;
	LinzaSkl->kins.y=282;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_namb,"R0",5,180,60);
	
	int deltaX=0;
	//CString farmat=dlgApracSkl.farmat;
	if (dlgApracSkl.farmat=="a4")deltaX=0;
	if (dlgApracSkl.farmat=="a3")deltaX=202;
//	{
	/////  подпіс БРАС ніжні
	LinzaSkl->kins.x=83+deltaX;
	LinzaSkl->kins.y=55;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_namb,"R0",5,0,60);
	

	int deltaY=0;
//	int deltaKvarcX=0;
//	int mater=m_combmater.GetCurSel();
//	{
	//	if (mater==0) {
			deltaY=40;
	//	material="_zvycz";} ;
	//	if (mater==1) {deltaY=-15; deltaKvarcX=14; material="_kvarc";};
	//	if (mater==2) {deltaY=0; material="_fluar";};

	///// f' плюс допуск на яго
	if (dlgApracSkl.m_f!=""){
	LinzaSkl->kins.x=170+deltaX;
	LinzaSkl->kins.y=181+deltaY;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_f+"%%p"+dlgApracSkl.m_fplus,"R0",4,0,30);
	}
	//// Sf
	//LinzaInDlg2->kins.x=170;
	if (dlgApracSkl.m_sf!=""){
	LinzaSkl->kins.y=174+deltaY;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_sf,"R0",4,0,30);
	}

	//// S'f'
	if(dlgApracSkl.m_sfshtr!=""){
	LinzaSkl->kins.y=167+deltaY;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_sfshtr+"%%p"+dlgApracSkl.m_sfshtrplus,"R0",4,0,30);
	}

	//// OdA
	if (dlgApracSkl.m_oda!=""){
	LinzaSkl->kins.y=160+deltaY;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_oda,"R0",4,0,30);
	}

	//// OdB
	if (dlgApracSkl.m_odb!=""){
	LinzaSkl->kins.y=153+deltaY;
	LinzaSkl->TextStr(LinzaSkl->kins,0,0,dlgApracSkl.m_odb,"R0",4,0,30);
	}
			}
			}
		command_switches="";
		command_switches="//nologo /t ";
		if (dlgApracSkl.farmat=="a4") command_switches+="a4_skleika";
		if (dlgApracSkl.farmat=="a3") command_switches+="a3_skleika";
	//	command_switches+="a4_skleika";
		command_switches+=" /b dateWR.scr";
		ready=TRUE;
	
			CString msg;
		msg="Файл згенераваны паспяхова\nМожна перадаваць у AutoCad";
		AfxMessageBox(msg,MB_ICONINFORMATION);
	
		}
		if (result==IDCANCEL)
		{
			OnMenuVybarSkl();
		};

	}
}

void CAutoOpticDoc::OnUpdateMENUVybSkl(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable((m_NaborSkleek.GetUpperBound())>=0);
}

void CAutoOpticDoc::OnUpdateMENUapracSkl(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(LinzaSkl!=NULL);
	
}
