# Microsoft Developer Studio Project File - Name="GDF" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GDF - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GDF.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GDF.mak" CFG="GDF - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GDF - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GDF - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GDF - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "GDF - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GDF - Win32 Release"
# Name "GDF - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DigLayerList.cpp
# End Source File
# Begin Source File

SOURCE=.\GDF.cpp
# End Source File
# Begin Source File

SOURCE=.\GDF.rc
# End Source File
# Begin Source File

SOURCE=.\GDFDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\GDFView.cpp

!IF  "$(CFG)" == "GDF - Win32 Release"

!ELSEIF  "$(CFG)" == "GDF - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\IndexMapSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\Layer.cpp
# End Source File
# Begin Source File

SOURCE=.\LayerList.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\scaler.cpp
# End Source File
# Begin Source File

SOURCE=.\Sheet.cpp
# End Source File
# Begin Source File

SOURCE=.\SheetIndexMap.cpp
# End Source File
# Begin Source File

SOURCE=.\SheetLayer.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DigLayerList.h
# End Source File
# Begin Source File

SOURCE=.\GDF.h
# End Source File
# Begin Source File

SOURCE=.\GDFDoc.h
# End Source File
# Begin Source File

SOURCE=.\GDFHeader.h
# End Source File
# Begin Source File

SOURCE=.\GDFView.h
# End Source File
# Begin Source File

SOURCE=.\IndexMapSheet.h
# End Source File
# Begin Source File

SOURCE=.\Layer.h
# End Source File
# Begin Source File

SOURCE=.\LayerList.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\scaler.h
# End Source File
# Begin Source File

SOURCE=.\Sheet.h
# End Source File
# Begin Source File

SOURCE=.\SheetIndexMap.h
# End Source File
# Begin Source File

SOURCE=.\SheetLayer.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GDF.ico
# End Source File
# Begin Source File

SOURCE=.\res\GDF.rc2
# End Source File
# Begin Source File

SOURCE=.\res\GDFDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Group "Shape"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Shape\Labeler.cpp

!IF  "$(CFG)" == "GDF - Win32 Release"

!ELSEIF  "$(CFG)" == "GDF - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Shape\Labeler.h
# End Source File
# Begin Source File

SOURCE=.\Shape\LayerManager.cpp

!IF  "$(CFG)" == "GDF - Win32 Release"

!ELSEIF  "$(CFG)" == "GDF - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Shape\LayerManager.h
# End Source File
# Begin Source File

SOURCE=.\Shape\objtype.h
# End Source File
# Begin Source File

SOURCE=.\Shape\Shapefile.cpp

!IF  "$(CFG)" == "GDF - Win32 Release"

!ELSEIF  "$(CFG)" == "GDF - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Shape\Shapefile.h
# End Source File
# Begin Source File

SOURCE=.\Shape\SHPLayer.cpp

!IF  "$(CFG)" == "GDF - Win32 Release"

!ELSEIF  "$(CFG)" == "GDF - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Shape\SHPLayer.h
# End Source File
# End Group
# Begin Group "R_Tree"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\R_Tree\buffer.h
# End Source File
# Begin Source File

SOURCE=.\R_Tree\oextent.h
# End Source File
# Begin Source File

SOURCE=.\R_Tree\oobject.cpp
# End Source File
# Begin Source File

SOURCE=.\R_Tree\oobject.h
# End Source File
# Begin Source File

SOURCE=.\R_Tree\ortree.cpp
# End Source File
# Begin Source File

SOURCE=.\R_Tree\ortree.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
