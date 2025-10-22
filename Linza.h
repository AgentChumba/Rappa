// linza.h : interface of the linza class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__C59637EC_748E_11D2_AA49_006052052EA5__INCLUDED_)
#define AFX_CHILDFRM_H__C59637EC_748E_11D2_AA49_006052052EA5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class kontur : public CObject
{
		DECLARE_SERIAL(kontur)
public:
	double radius;// радыюс паверхні лінзы
	double vysh; // агульная вышыня лінзы (тут паверхні)
//	double mashtab;// маштаб адлюстравання лінзы
	struct kardynaty
	{
		double x;
		double y;
	};

	kardynaty origin;
	kardynaty point1;
	kardynaty point2;
	CString OutString;

protected:
		void initilize(double R, double h);
	kontur();
	~kontur();
	double delta_x;
	double y1;
	double y2;

	// Operations
public:
//	virtual void Serialize(CArchive& ar);

virtual	void maluj_arc();
virtual	void maluj_line(kardynaty kr1, kardynaty kr2);
};



class linza:public kontur
{
	DECLARE_SERIAL(linza)
protected:
///	
	~linza();
public:
//	CChildFrame();
	linza();
	linza(double r1, double r2,
			 double vsh, double t);
	

// Attributes
public:
	double radius1; // першы радыюс лінзы
	double radius2; // другі радыюс лінзы

	double tausczyna;// таушчыня лінзы
	kardynaty pointA, pointB,   // левы верхні, правы верхні,
	           pointC, pointD;  //  левы ніжні, правы ніжні   
	kardynaty pOL, pOR;  //левая асявая кропка, правая асявая кропка

	BOOL  skleivaem1;// ці будзе склейвацца гэта паверхня
	BOOL  skleivaem2;// ці будзе склейвацца гэта паверхня
	// Operations
public:
	linza& operator=( const linza &l)
	{
		vysh=l.vysh;
		radius1=l.radius1;
		radius2=l.radius2;
		tausczyna=l.tausczyna;
			skleivaem1=l.skleivaem1;
		skleivaem2=l.skleivaem2;
	//	pramejutak=l.pramejutak;
		 return *this;
	}

	linza( const linza &l)
	{
		vysh=l.vysh;
		radius1=l.radius1;
		radius2=l.radius2;
		tausczyna=l.tausczyna;
			skleivaem1=l.skleivaem1;
		skleivaem2=l.skleivaem2;
	//	pramejutak=l.pramejutak;
	}
//	virtual void Serialize(CArchive& ar);
public:
	void linear_dimension(kardynaty kr1, kardynaty kr2,
		int smesh, double pamer, const char* apnadpis,const char* dopis);
	void maluj_kontur(double x1, double y1,
		linza* plinzaOne);
	void sztryhouka(kardynaty kr2,int naklon);
	void maluj_os(kardynaty kr1, kardynaty kr2);
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	public:
//	
	//}}AFX_VIRTUAL

// Implementation
public:
//	virtual ~CChildFrame();
#ifdef _DEBUG
//	virtual void AssertValid() const;
//	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
//	CSplitterWnd m_Splitter;

	//{{AFX_MSG(CChildFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
//	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////

class linza_in_objektiv: public linza
{
		DECLARE_SERIAL(linza_in_objektiv)
protected:
	
public:
	linza_in_objektiv();

public:
	linza_in_objektiv(double pr, double r1, double r2,
			 double vsh, double t);
	linza_in_objektiv(double pr, double r1, double r2,
			 double vsh, double t, BOOL skl1, BOOL skl2);
	~linza_in_objektiv();

// Attributes
public:
double pramejutak;

// Operations
public:
	linza_in_objektiv& operator=( const linza_in_objektiv &l)
	{
		vysh=l.vysh;
		radius1=l.radius1;
		radius2=l.radius2;
		tausczyna=l.tausczyna;
		pramejutak=l.pramejutak;
		skleivaem1=l.skleivaem1;
		skleivaem2=l.skleivaem2;
		 return *this;
	}

	linza_in_objektiv( const linza_in_objektiv &l)
	{
		vysh=l.vysh;
		radius1=l.radius1;
		radius2=l.radius2;
		tausczyna=l.tausczyna;
		pramejutak=l.pramejutak;
		skleivaem1=l.skleivaem1;
		skleivaem2=l.skleivaem2;
	}

virtual void Serialize(CArchive& ar);


virtual	void maluj_arc();
virtual	void maluj_line(kardynaty kr1, kardynaty kr2);
};


class skleika:public linza_in_objektiv
{
	 DECLARE_SERIAL(skleika)
public:
	virtual void Serialize(CArchive& ar);
	skleika();
	skleika(double pr,double r1,double r2, double r3, double t1, double t2, double h);
	skleika(double pr,double r1,double r2, double r3, double r4, double t1, double t2, double t3, double h);
	linza_in_objektiv* linza[2];
	double mastb;//маштаб адлюстраваня
	kardynaty kins;
// Operations	
	void InsertBlock(kardynaty kr1, const char* LOR);
	void TextStr(kardynaty kr1, int smesh_x, int smesh_y,
		CString stext, CString style, double height,int rot, int width);

	skleika& operator=( const skleika &l)
	{
		for(int i=0;i<2;i++){
			if (linza[i]!=NULL){
				linza[i]->vysh=l.linza[i]->vysh;
				linza[i]->radius1=l.linza[i]->radius1;
				linza[i]->radius2=l.linza[i]->radius2;
				linza[i]->tausczyna=l.linza[i]->tausczyna;
				linza[i]->skleivaem1=l.linza[i]->skleivaem1;
				linza[i]->skleivaem2=l.linza[i]->skleivaem2;
			}
		}
		return *this;
	}

	skleika( const skleika &l)
	{
		for(int i=0;i<2;i++){
			if (linza[i]!=NULL){
				linza[i]->vysh=l.linza[i]->vysh;
				linza[i]->radius1=l.linza[i]->radius1;
				linza[i]->radius2=l.linza[i]->radius2;
				linza[i]->tausczyna=l.linza[i]->tausczyna;
				linza[i]->skleivaem1=l.linza[i]->skleivaem1;
				linza[i]->skleivaem2=l.linza[i]->skleivaem2;
			}
		}
	}
};

class linza_single:public skleika
{
	DECLARE_DYNAMIC( linza_single )
	//DECLARE_SERIAL(linza)
protected:
///	
public:
//	CChildFrame();
	linza_single();
	linza_single(double r1, double r2,
			 double vsh, double t, double ms);
	~linza_single();
	linza_single& operator=( const linza_single &l)
	{
		vysh=l.vysh;
		radius1=l.radius1;
		radius2=l.radius2;
		tausczyna=l.tausczyna;
		created=l.created;
		mastb=l.mastb;
		skleivaem1=l.skleivaem1;
		skleivaem2=l.skleivaem2;
		return *this;
	}

	linza_single( const linza_single &l)
	{
		vysh=l.vysh;
		radius1=l.radius1;
		radius2=l.radius2;
		tausczyna=l.tausczyna;
		created=l.created;
		mastb=l.mastb;
		skleivaem1=l.skleivaem1;
		skleivaem2=l.skleivaem2;
	}
// Attributes
public:

	int  created;// ці створана гэта лінза

	kardynaty kl,kp;
// Operations
public:
	void radius_dimension(kardynaty kr1,
		double vysh, double pamer);
	void faski(kardynaty kr1, int smesh_x, int smesh_y,
		CString fsk, CString angle);
	
	};



//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__C59637EC_748E_11D2_AA49_006052052EA5__INCLUDED_)





