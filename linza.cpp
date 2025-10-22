#include "stdafx.h"
#include "linza.h"
#include <math.h>

/////////////////////////////////////////
// метады класа kontur          /////////
IMPLEMENT_SERIAL(kontur, CObject,1)

kontur::kontur()
{
};

kontur::~kontur()
{
};

/*void kontur::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar<<vysh;	
	else
		ar>>vysh;	
	
};*/

void kontur::initilize(double R, double h)
{
	if(R<0) 
	{
		// мал€ваць пачынае зн≥зу
		delta_x=R+sqrt((R*R)-(h*h));
		y1=-h;
		y2=h;
	}
	else
	if(R>0)
	{
		// мал€ваць пачынае зверху
		delta_x=R-sqrt((R*R)-(h*h));
		y1=h;
		y2=-h;
	}
	else
	{
		// тут мал€ваць усЄроҐна €к (R==0)
		delta_x=0;
		y1=-h;
		y2=h;
		radius=32000;
	}
	point1.x=origin.x+delta_x;
	point1.y=origin.y+y1;

	point2.x=origin.x+delta_x;
	point2.y=origin.y+y2;

};
////////////////////////////////////////////////
///  малюе л≥н≥ю па заданым кропкам   //////////

void kontur::maluj_line(kardynaty kr1, kardynaty kr2)
{
	CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("pline\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr1.x, kr1.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("width\n0.5\n\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr2.x, kr2.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("\n");
};

////////////////////////////////////////////////
///  малюе дугу па выл≥чаным пап€рэдне кропкам  ///

void kontur::maluj_arc()
	{
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("pline\n");
	OutString.Format("%3.3f,%3.3f\n",
		point1.x, point1.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("width\n0.5\n\narc\nradius\n");
	OutString.Format("%3.3f\n",
		fabs(radius));
	OutFile.WriteString(OutString);
	OutString.Format("%3.3f,%3.3f\n",
		point2.x, point2.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("\n");
	};

/////////////////////////////////////////
// метады класа linza            /////////
IMPLEMENT_SERIAL(linza, kontur,1)
linza::linza()
{};

linza::linza(double r1, double r2, 
			 double vsh, double t)
{
	
	radius1=r1;
	radius2=r2;
//	skleivaem1=sk1;
//	skleivaem2=sk2;
	vysh=vsh;
	tausczyna=t;
} ;	


linza::~linza()
{
//	MessageBox(NULL,"menu 245","zz",MB_OK|MB_ICONINFORMATION) ;
};

/*void linza::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar<<radius1<<radius2<<tausczyna;	
	else
		ar>>radius1>>radius2>>tausczyna;	

};*/
///////////////////////////////////////////////////////////
///////  будзе прамалЄҐваць л≥нейны€ памеры  //////////////

void linza::linear_dimension(kardynaty kr1, kardynaty kr2,
				 int smesh, double pamer, const char* apnadpis,const char* dopis)
 {
	CString Nadpis;/// колькасць знакаҐ пасл€ коск≥
	kardynaty outPoint;
	if(kr1.x==kr2.x)
	{
		outPoint.y=kr1.y;
		outPoint.x=kr1.x+smesh;
		//dakladnasc=1;
		Nadpis.Format("%s%3.1f%s\n",apnadpis, pamer,dopis);
	}
	else if(kr1.y==kr2.y)
	{
		outPoint.x=kr1.x;
		outPoint.y=kr1.y+smesh;
	//	dakladnasc=2;
		Nadpis.Format("%s%3.2f%s\n",apnadpis, pamer,dopis);
	}
	else 
	{
		outPoint.x=kr1.x;
		outPoint.y=kr1.y+smesh;
	//	dakladnasc=2;
		Nadpis.Format("%s%3.2f%s\n",apnadpis, pamer,dopis);
	};
//	const int d=dakladnasc;
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("_dimlinear\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr1.x, kr1.y);
	OutFile.WriteString(OutString);
	OutString.Format("%3.3f,%3.3f\n",
		kr2.x, kr2.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("text\n");
//	OutString.Format("%s%(3.d)f%s\n",apnadpis, pamer,dopis);
	OutFile.WriteString(Nadpis);
	OutString.Format("%3.3f,%3.3f\n",
		outPoint.x, outPoint.y);
	OutFile.WriteString(OutString);
};



void linza::maluj_kontur(double x1, double y1,
			linza* plinzaOne)

{
	//	linza linzaOne(r1, r2, sk1, sk2, vsh, t);
       	
	plinzaOne->origin.x=x1;
	plinzaOne->origin.y=y1;
	plinzaOne->pOL=plinzaOne->origin;
	plinzaOne->radius=plinzaOne->radius1;
	plinzaOne->initilize(plinzaOne->radius1, plinzaOne->vysh);
	plinzaOne->maluj_arc();
	plinzaOne->pointA.x=plinzaOne->point1.x;
	plinzaOne->pointA.y=max(plinzaOne->point1.y,plinzaOne->point2.y);
	plinzaOne->pointC.x=plinzaOne->point1.x;
	plinzaOne->pointC.y=min(plinzaOne->point1.y,plinzaOne->point2.y);
	
	plinzaOne->origin.x=x1+plinzaOne->tausczyna;
	plinzaOne->origin.y=y1;
	plinzaOne->pOR=plinzaOne->origin;
	plinzaOne->radius=plinzaOne->radius2;
	plinzaOne->initilize(plinzaOne->radius2, plinzaOne->vysh);
	plinzaOne->maluj_arc();
	plinzaOne->pointB.x=plinzaOne->point1.x;
	plinzaOne->pointB.y=max(plinzaOne->point1.y,plinzaOne->point2.y);
	plinzaOne->pointD.x=plinzaOne->point1.x;
	plinzaOne->pointD.y=min(plinzaOne->point1.y,plinzaOne->point2.y);
	
	plinzaOne->maluj_line(plinzaOne->pointA, plinzaOne->pointB);
	plinzaOne->maluj_line(plinzaOne->pointC, plinzaOne->pointD);
	
};

void linza::sztryhouka(kardynaty kr2,int naklon)
{
	CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("-bhatch\n");
	OutString.Format("%3.3f,%3.3f\n",
		(kr2.x-2.5), kr2.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("properties\n");
	OutFile.WriteString("steklo\n1.5\n");
	OutString.Format("%d\n",naklon);
	OutFile.WriteString(OutString);
	OutFile.WriteString("\n");
		
};

void linza::maluj_os(kardynaty kr1, kardynaty kr2)
{
		CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("-linetype\nset\nAcad_iso04w100\n\n");
			OutFile.WriteString("line\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr1.x-50, kr1.y);
	OutFile.WriteString(OutString);
//	OutFile.WriteString("width\n0.5\n\n");
	OutString.Format("%3.3f,%3.3f\n\n",
		kr2.x+50, kr2.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("-linetype\nset\nbylayer\n\n");
//	OutFile.WriteString("\n");

};
/////////////////////////////////////////
// метады класа linza_in_objektiv   /////////

linza_in_objektiv::linza_in_objektiv()
{};	

linza_in_objektiv::~linza_in_objektiv()
{};	

IMPLEMENT_SERIAL(linza_in_objektiv, linza,1)
linza_in_objektiv::linza_in_objektiv(double pr, double r1, double r2,
			 double vsh, double t)
{
	pramejutak=pr;
	radius1=r1;
	radius2=r2;
	vysh=vsh;
	tausczyna=t;
	skleivaem1=FALSE;
	skleivaem2=FALSE;
} ;

linza_in_objektiv::linza_in_objektiv(double pr, double r1, double r2,
			 double vsh, double t, BOOL skl1, BOOL skl2)
{
	pramejutak=pr;
	radius1=r1;
	radius2=r2;
	vysh=vsh;
	tausczyna=t;
	skleivaem1=skl1;
	skleivaem2=skl2;
} ;

void linza_in_objektiv::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar<<pramejutak<<radius1<<radius2<<vysh<<tausczyna;	
	else
		ar>>pramejutak>>radius1>>radius2>>vysh>>tausczyna;	

};

void linza_in_objektiv::maluj_arc()
	{
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("pline\n");
	OutString.Format("%3.3f,%3.3f\n",
		point1.x, point1.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("width\n0.5\n\narc\nradius\n");
	OutString.Format("%3.3f\n",
		fabs(radius));
	OutFile.WriteString(OutString);
	OutString.Format("%3.3f,%3.3f\n",
		point2.x, point2.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("\n");
	};

void linza_in_objektiv::maluj_line(kardynaty kr1, kardynaty kr2)
{
	CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("pline\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr1.x, kr1.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("width\n0.5\n\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr2.x, kr2.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("\n");
};

/////////////////////////////////////////
// метады класа linza_single   /////////
//class linza_single:public linza
IMPLEMENT_DYNAMIC(linza_single ,skleika )
linza_single::linza_single()
{};

linza_single::~linza_single()
{};

linza_single::linza_single(double r1, double r2,
			 double vsh, double t, double ms)
{
	radius1=r1;
	radius2=r2;
///	skleivaem1=linza::skleivaem1;
///	skleivaem2=linza::skleivaem2;
	vysh=vsh;
	tausczyna=t;
	mastb=ms;
};

void linza_single::radius_dimension(kardynaty kr1,
		double vysh, double pamer)
{
	kardynaty outPoint;
	if (pamer>0)
	{
	outPoint.x=kr1.x+vysh*0.7;
	outPoint.y=kr1.y+vysh*0.7;
	} else
		if(pamer<0)
	{
	outPoint.x=kr1.x-vysh*0.7;
	outPoint.y=kr1.y+vysh*0.7;
	}
		else return;
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("_dimradius\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr1.x, kr1.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("text\n");
	OutString.Format("R %3.3f\n", fabs(pamer));
	OutFile.WriteString(OutString);
	OutString.Format("%3.3f,%3.3f\n",
		outPoint.x, outPoint.y);
	OutFile.WriteString(OutString);
	
};


void linza_single::faski(kardynaty kr1, int smesh_x, int smesh_y,
		CString fsk, CString angle)
{
		kardynaty outPoint;
		outPoint.x=kr1.x+smesh_x;
		outPoint.y=kr1.y+smesh_y;
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("_leader\n");
	OutString.Format("%3.3f,%3.3f\n",
		kr1.x, kr1.y);
	OutFile.WriteString(OutString);
	OutString.Format("%3.3f,%3.3f\n",
		outPoint.x, outPoint.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("annotation\n");
//		OutString.Format("  +%1.1f\n",dopusk);
//	OutFile.WriteString(OutString);
		OutString.Format("%s   x%s∞\n\n",fsk,angle);
	OutFile.WriteString(OutString);

		
};

//IMPLEMENT_DYNAMIC( skleika, linza_in_objektiv )
IMPLEMENT_SERIAL(skleika, linza_in_objektiv,1)
skleika::skleika()
		{
		linza[0]=NULL;
		linza[1]=NULL;
		linza[2]=NULL;
		};

skleika::skleika(double pr,double r1,double r2, double r3, double t1, double t2, double h)
{
	linza[0]=new linza_in_objektiv(pr,r1,r2,h,t1,FALSE,TRUE);
	linza[1]=new linza_in_objektiv(0,r2,r3,h,t2,TRUE,FALSE);
	linza[2]=NULL;
};

skleika::skleika(double pr,double r1,double r2, double r3, double r4, double t1, double t2, double t3, double h)
{
	linza[0]=new linza_in_objektiv(pr,r1,r2,h,t1,FALSE,TRUE);
	linza[1]=new linza_in_objektiv(0,r2,r3,h,t2,TRUE,TRUE);
	linza[2]=new linza_in_objektiv(0,r3,r4,h,t3,TRUE,FALSE);
};

void skleika::InsertBlock(kardynaty kr1, const char* LOR)
{
	CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
		OutFile.WriteString("insert\n");
		OutString.Format("%s\n",LOR);
		OutFile.WriteString(OutString);
	OutString.Format("%3.3f,%3.3f\n",
		kr1.x, kr1.y);
	OutFile.WriteString(OutString);
	OutFile.WriteString("\n\n\n");
	
};

void skleika::TextStr(kardynaty kr1, int smesh_x, int smesh_y,
		CString stext, CString style, double height,int rot, int width)
{
		kardynaty outPoint;
		outPoint.x=kr1.x+smesh_x;
		outPoint.y=kr1.y+smesh_y;
			CStdioFile OutFile("dateWR.scr", CFile::modeWrite);
			OutFile.SeekToEnd();
	OutFile.WriteString("-mtext\n");
	OutString.Format("%3.3f,%3.3f\n",
		outPoint.x, outPoint.y);
	OutFile.WriteString(OutString);
	OutString.Format("style\n%s\nheight\n%2.1f\nrotation\n%d\nwidth\n%d\n",
		style,height,rot,width);
//	OutString.Format("%d\n",width);
	OutFile.WriteString(OutString);
		OutString.Format("%s\n\n",stext);
	OutFile.WriteString(OutString);
		
};

void skleika::Serialize(CArchive &ar)
{
/*	if (ar.IsStoring()){
		for(int i=0;i<2;i++){
		if ((linza[i])!=NULL){
			linza[i]->Serialize(ar);}
		}
	}
		//ar<<pramejutak<<radius1<<radius2<<vysh<<tausczyna;	
	else{
		for(int i=0;i<2;i++){
		if ((linza[i])!=NULL){
			linza[i]->Serialize(ar);}
		}
	//	ar>>pramejutak>>radius1>>radius2>>vysh>>tausczyna;	
	}*/

}
