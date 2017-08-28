#if !defined(AFX_BINEDIT_H__6BD5EB8D_30F4_44B1_9162_5E1992FE8337__INCLUDED_)
#define AFX_BINEDIT_H__6BD5EB8D_30F4_44B1_9162_5E1992FE8337__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BinEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BinEdit window

class BinEdit : public CEdit
{
// Construction
public:
	BinEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BinEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~BinEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(BinEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINEDIT_H__6BD5EB8D_30F4_44B1_9162_5E1992FE8337__INCLUDED_)
