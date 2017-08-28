// BinEdit.cpp : implementation file
//

#include "stdafx.h"
#include "OperationReverse.h"
#include "BinEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BinEdit

BinEdit::BinEdit()
{
}

BinEdit::~BinEdit()
{
}


BEGIN_MESSAGE_MAP(BinEdit, CEdit)
	//{{AFX_MSG_MAP(BinEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BinEdit message handlers

void BinEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

if (islower(nChar)) nChar -=32;  // MAKE CHAR UPPER IF IS LOWER

if (nChar>=48&&nChar<=49)  // accept 0 and 1
DefWindowProc(WM_CHAR, nChar,0);

if (nChar==88||nChar==120)  // accept X and x 
DefWindowProc(WM_CHAR, nChar,0);

if (nChar == VK_BACK||nChar == VK_DELETE)  // if backslash or delete key
DefWindowProc(WM_CHAR, nChar,0);

if (nChar==0x02D)  // - char
DefWindowProc(WM_CHAR, nChar,0);

	// Originaly calls this:
	// CEdit::OnChar(nChar, nRepCnt, nFlags);
}

void BinEdit::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	this->SetLimitText(32);  // set max text lenght to 32
	CEdit::PreSubclassWindow();
}
