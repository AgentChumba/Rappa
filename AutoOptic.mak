# Microsoft Developer Studio Generated NMAKE File, Based on AutoOptic.dsp
!IF "$(CFG)" == ""
CFG=AutoOptic - Win32 Debug
!MESSAGE No configuration specified. Defaulting to AutoOptic - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AutoOptic - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AutoOptic.mak" CFG="AutoOptic - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AutoOptic - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\AutoOptic.exe"

!ELSE 

ALL : "$(OUTDIR)\AutoOptic.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AutoOptic.obj"
	-@erase "$(INTDIR)\AutoOptic.pch"
	-@erase "$(INTDIR)\AutoOptic.res"
	-@erase "$(INTDIR)\AutoOpticDoc.obj"
	-@erase "$(INTDIR)\AutoOpticView.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\CntrItem.obj"
	-@erase "$(INTDIR)\D_linz1.obj"
	-@erase "$(INTDIR)\Dlg_abektv.obj"
	-@erase "$(INTDIR)\Dlg_aprc.obj"
	-@erase "$(INTDIR)\Dlg_del_linz.obj"
	-@erase "$(INTDIR)\Dlg_edit_ln.obj"
	-@erase "$(INTDIR)\Dlg_ins_linz.obj"
	-@erase "$(INTDIR)\Dlg_newln.obj"
	-@erase "$(INTDIR)\linza.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\AutoOptic.exe"
	-@erase "$(OUTDIR)\AutoOptic.ilk"
	-@erase "$(OUTDIR)\AutoOptic.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\AutoOptic.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC=rc.exe
RSC_PROJ=/l 0x419 /fo"$(INTDIR)\AutoOptic.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AutoOptic.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\AutoOptic.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\AutoOptic.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AutoOptic.obj" \
	"$(INTDIR)\AutoOptic.res" \
	"$(INTDIR)\AutoOpticDoc.obj" \
	"$(INTDIR)\AutoOpticView.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\CntrItem.obj" \
	"$(INTDIR)\D_linz1.obj" \
	"$(INTDIR)\Dlg_abektv.obj" \
	"$(INTDIR)\Dlg_aprc.obj" \
	"$(INTDIR)\Dlg_del_linz.obj" \
	"$(INTDIR)\Dlg_edit_ln.obj" \
	"$(INTDIR)\Dlg_ins_linz.obj" \
	"$(INTDIR)\Dlg_newln.obj" \
	"$(INTDIR)\linza.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\AutoOptic.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<


!IF "$(CFG)" == "AutoOptic - Win32 Debug"
SOURCE=.\AutoOptic.cpp
DEP_CPP_AUTOO=\
	".\AutoOptic.h"\
	".\AutoOpticDoc.h"\
	".\AutoOpticView.h"\
	".\ChildFrm.h"\
	".\Linza.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\AutoOptic.obj" : $(SOURCE) $(DEP_CPP_AUTOO) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\AutoOptic.rc
DEP_RSC_AUTOOP=\
	".\res\AutoOptic.ico"\
	".\res\AutoOptic.rc2"\
	".\res\AutoOpticDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\AutoOptic.res" : $(SOURCE) $(DEP_RSC_AUTOOP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\AutoOpticDoc.cpp
DEP_CPP_AUTOOPT=\
	".\AutoOptic.h"\
	".\AutoOpticDoc.h"\
	".\CntrItem.h"\
	".\Linza.h"\
	

"$(INTDIR)\AutoOpticDoc.obj" : $(SOURCE) $(DEP_CPP_AUTOOPT) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\AutoOpticView.cpp
DEP_CPP_AUTOOPTI=\
	".\AutoOptic.h"\
	".\AutoOpticDoc.h"\
	".\AutoOpticView.h"\
	".\CntrItem.h"\
	".\d_linz1.h "\
	".\dlg_abektv.h "\
	".\dlg_aprc.h "\
	".\dlg_del_linz.h "\
	".\dlg_ins_linz.h "\
	".\dlg_newln.h "\
	".\Linza.h"\
	

"$(INTDIR)\AutoOpticView.obj" : $(SOURCE) $(DEP_CPP_AUTOOPTI) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\AutoOptic.h"\
	".\ChildFrm.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\CntrItem.cpp
DEP_CPP_CNTRI=\
	".\AutoOptic.h"\
	".\AutoOpticDoc.h"\
	".\AutoOpticView.h"\
	".\CntrItem.h"\
	".\Linza.h"\
	

"$(INTDIR)\CntrItem.obj" : $(SOURCE) $(DEP_CPP_CNTRI) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\D_linz1.cpp
DEP_CPP_D_LIN=\
	".\AutoOptic.h"\
	".\AutoOpticDoc.h"\
	".\AutoOpticView.h"\
	".\D_linz1.h"\
	".\Linza.h"\
	

"$(INTDIR)\D_linz1.obj" : $(SOURCE) $(DEP_CPP_D_LIN) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\Dlg_abektv.cpp
DEP_CPP_DLG_A=\
	".\AutoOptic.h"\
	".\Dlg_abektv.h"\
	".\Dlg_edit_ln.h"\
	".\Dlg_newln.h"\
	".\Linza.h"\
	

"$(INTDIR)\Dlg_abektv.obj" : $(SOURCE) $(DEP_CPP_DLG_A) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\Dlg_aprc.cpp
DEP_CPP_DLG_AP=\
	".\AutoOptic.h"\
	".\Dlg_aprc.h"\
	".\Linza.h"\
	

"$(INTDIR)\Dlg_aprc.obj" : $(SOURCE) $(DEP_CPP_DLG_AP) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\Dlg_del_linz.cpp
DEP_CPP_DLG_D=\
	".\AutoOptic.h"\
	".\Dlg_del_linz.h"\
	".\Linza.h"\
	

"$(INTDIR)\Dlg_del_linz.obj" : $(SOURCE) $(DEP_CPP_DLG_D) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\Dlg_edit_ln.cpp
DEP_CPP_DLG_E=\
	".\AutoOptic.h"\
	".\Dlg_edit_ln.h"\
	".\Linza.h"\
	

"$(INTDIR)\Dlg_edit_ln.obj" : $(SOURCE) $(DEP_CPP_DLG_E) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\Dlg_ins_linz.cpp
DEP_CPP_DLG_I=\
	".\AutoOptic.h"\
	".\Dlg_ins_linz.h"\
	

"$(INTDIR)\Dlg_ins_linz.obj" : $(SOURCE) $(DEP_CPP_DLG_I) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\Dlg_newln.cpp
DEP_CPP_DLG_N=\
	".\AutoOptic.h"\
	".\Dlg_newln.h"\
	".\Linza.h"\
	

"$(INTDIR)\Dlg_newln.obj" : $(SOURCE) $(DEP_CPP_DLG_N) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\linza.cpp
DEP_CPP_LINZA=\
	".\Linza.h"\
	

"$(INTDIR)\linza.obj" : $(SOURCE) $(DEP_CPP_LINZA) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\AutoOptic.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\AutoOptic.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\AutoOptic.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AutoOptic.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<



!ENDIF 

