; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGDFView
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GDF.h"
LastPage=0

ClassCount=9
Class1=CGDFApp
Class2=CGDFDoc
Class3=CGDFView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_DigSheetLayer
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=DigLayerList
Resource3=IDD_DIALOG1
Resource4=IDD_PANNEL
Class7=CSheetLayer
Resource5=IDD_ABOUTBOX
Class8=CIndexMapSheet
Class9=CSheetIndexMap
Resource6=IDD_DigSheetIndexMap

[CLS:CGDFApp]
Type=0
HeaderFile=GDF.h
ImplementationFile=GDF.cpp
Filter=N

[CLS:CGDFDoc]
Type=0
HeaderFile=GDFDoc.h
ImplementationFile=GDFDoc.cpp
Filter=N
LastObject=CGDFDoc

[CLS:CGDFView]
Type=0
HeaderFile=GDFView.h
ImplementationFile=GDFView.cpp
Filter=D
LastObject=ID_SHPOpen
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=GDF.cpp
ImplementationFile=GDF.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_SHPOpen
Command4=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_FILE_PRINT
Command9=ID_APP_ABOUT
Command10=ID_ZOOMOUT
Command11=ID_ZOONIN
Command12=ID_MOVE
Command13=ID_AREA
Command14=ID_EXTENT
Command15=ID_BtnLayer
CommandCount=15

[DLG:IDD_DIALOG1]
Type=1
Class=DigLayerList
ControlCount=3
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_BtnHide,button,1342242816
Control3=IDC_BtnDel,button,1342242816

[CLS:DigLayerList]
Type=0
HeaderFile=DigLayerList.h
ImplementationFile=DigLayerList.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BtnDel
VirtualFilter=dWC

[DLG:IDD_PANNEL]
Type=1
Class=?
ControlCount=2
Control1=IDC_SheetHolder,static,1342177287
Control2=IDC_IndexMapHolder,static,1342177287

[DLG:IDD_DigSheetLayer]
Type=1
Class=CSheetLayer
ControlCount=3
Control1=IDC_SheetLayer,SysListView32,1350631425
Control2=IDC_BtnSheetDel,button,1342242816
Control3=IDC_BUTTON2,button,1342242816

[CLS:CSheetLayer]
Type=0
HeaderFile=SheetLayer.h
ImplementationFile=SheetLayer.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CSheetLayer

[DLG:IDD_DigSheetIndexMap]
Type=1
Class=CSheetIndexMap
ControlCount=0

[CLS:CIndexMapSheet]
Type=0
HeaderFile=IndexMapSheet.h
ImplementationFile=IndexMapSheet.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CIndexMapSheet

[CLS:CSheetIndexMap]
Type=0
HeaderFile=SheetIndexMap.h
ImplementationFile=SheetIndexMap.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CSheetIndexMap
VirtualFilter=idWC

