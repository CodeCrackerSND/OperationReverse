; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COperationReverseDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OperationReverse.h"

ClassCount=4
Class1=COperationReverseApp
Class2=COperationReverseDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=NewEdit
Class4=BinEdit
Resource2=IDD_OPERATIONREVERSE_DIALOG

[CLS:COperationReverseApp]
Type=0
HeaderFile=OperationReverse.h
ImplementationFile=OperationReverse.cpp
Filter=N
LastObject=COperationReverseApp

[CLS:COperationReverseDlg]
Type=0
HeaderFile=OperationReverseDlg.h
ImplementationFile=OperationReverseDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=base



[DLG:IDD_OPERATIONREVERSE_DIALOG]
Type=1
Class=COperationReverseDlg
ControlCount=14
Control1=base,combobox,1344339970
Control2=IDC_STATIC,static,1342308352
Control3=operation,combobox,1344339970
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=result,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=oneoperand,edit,1350631552
Control9=otheroperand,static,1342308352
Control10=reverse,button,1342242816
Control11=otherbinary,edit,1350631552
Control12=Generatenumb_but,button,1342242816
Control13=IDC_STATIC,static,1342308352
Control14=generatenumb,edit,1350631552

[CLS:NewEdit]
Type=0
HeaderFile=NewEdit.h
ImplementationFile=NewEdit.cpp
BaseClass=CEdit
Filter=W
LastObject=NewEdit

[CLS:BinEdit]
Type=0
HeaderFile=BinEdit.h
ImplementationFile=BinEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=BinEdit

