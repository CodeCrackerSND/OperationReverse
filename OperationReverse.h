// OperationReverse.h : main header file for the OPERATIONREVERSE application
//

#if !defined(AFX_OPERATIONREVERSE_H__B280434D_EDB8_40C6_85DD_5127FAB15A22__INCLUDED_)
#define AFX_OPERATIONREVERSE_H__B280434D_EDB8_40C6_85DD_5127FAB15A22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COperationReverseApp:
// See OperationReverse.cpp for the implementation of this class
//

class COperationReverseApp : public CWinApp
{
public:
	COperationReverseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperationReverseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COperationReverseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATIONREVERSE_H__B280434D_EDB8_40C6_85DD_5127FAB15A22__INCLUDED_)
