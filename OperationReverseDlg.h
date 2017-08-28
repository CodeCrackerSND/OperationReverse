// OperationReverseDlg.h : header file
//

#include "stdafx.h"
#include "OperationReverse.h"
#include "NewEdit.h"
#include "BinEdit.h"

#if !defined(AFX_OPERATIONREVERSEDLG_H__1D3248B8_849E_4CEE_A810_84466192A878__INCLUDED_)
#define AFX_OPERATIONREVERSEDLG_H__1D3248B8_849E_4CEE_A810_84466192A878__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COperationReverseDlg dialog

class COperationReverseDlg : public CDialog
{
// Construction
public:
	COperationReverseDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(COperationReverseDlg)
	enum { IDD = IDD_OPERATIONREVERSE_DIALOG };
	BinEdit	m_otherbinary;
	NewEdit	m_generatenumb;
	NewEdit	m_oneoperand;
	NewEdit	m_result;
	CComboBox	m_operation;
	CComboBox	m_base;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperationReverseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COperationReverseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onreverse();
	afx_msg void Onbut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATIONREVERSEDLG_H__1D3248B8_849E_4CEE_A810_84466192A878__INCLUDED_)
