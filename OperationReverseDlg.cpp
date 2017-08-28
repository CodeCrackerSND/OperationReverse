// OperationReverseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OperationReverse.h"
#include "OperationReverseDlg.h"
#include "NewEdit.h"
#include "GenericPurposeMethods.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COperationReverseDlg dialog

COperationReverseDlg::COperationReverseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COperationReverseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COperationReverseDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COperationReverseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COperationReverseDlg)
	DDX_Control(pDX, otherbinary, m_otherbinary);
	DDX_Control(pDX, generatenumb, m_generatenumb);
	DDX_Control(pDX, oneoperand, m_oneoperand);
	DDX_Control(pDX, result, m_result);
	DDX_Control(pDX, operation, m_operation);
	DDX_Control(pDX, base, m_base);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COperationReverseDlg, CDialog)
	//{{AFX_MSG_MAP(COperationReverseDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(reverse, Onreverse)
	ON_BN_CLICKED(Generatenumb_but, Onbut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COperationReverseDlg message handlers

BOOL COperationReverseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	m_base.AddString("binary");
	int dec_index = m_base.AddString("decimal");
	m_base.AddString("hexadecimal");
	m_base.SetCurSel(dec_index);

	int first_index = m_operation.AddString("xor");
	m_operation.AddString("or");
	m_operation.AddString("and");
	m_operation.SetCurSel(first_index);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COperationReverseDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COperationReverseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COperationReverseDlg::Onreverse() 
{
	// TODO: Add your control notification handler code here
	int row = m_base.GetCurSel();
    if (row < 0)
	return;

	CString base_str;
    m_base.GetLBText(row, base_str);
	if (base_str.GetLength()==0)
	return;

	row = m_operation.GetCurSel();
    if (row < 0)
	return;

    CString operation_str;
    m_operation.GetLBText(row, operation_str);
	if (operation_str.GetLength()==0)
	return;

	char result_str[500];
	m_result.GetWindowText(result_str, 500);

	if (result_str[0]==0)
	return;

	unsigned int result_num = GenericPurposeMethods::GetIntFromStr(result_str, base_str.GetBuffer(0));

	char oneop_str[500];
	m_oneoperand.GetWindowText(oneop_str, 500);

	if (oneop_str[0]==0)
	return;

	unsigned int oneop_num = GenericPurposeMethods::GetIntFromStr(oneop_str, base_str.GetBuffer(0));

	CString result_bin = GenericPurposeMethods::NumbtoBinaryStr(result_num);

	CString oneop_bin = GenericPurposeMethods::NumbtoBinaryStr(oneop_num);

	CString bin_otherop = GenericPurposeMethods::ReverseOp(operation_str.GetBuffer(0), result_bin, oneop_bin);

	m_otherbinary.SetWindowText(bin_otherop);

}

void COperationReverseDlg::Onbut() 
{
	// TODO: Add your control notification handler code here
	
	int row = m_base.GetCurSel();
    if (row < 0)
	return;

	CString base_str;
    m_base.GetLBText(row, base_str);
	if (base_str.GetLength()==0)
	return;

	CString binary_mask;
	m_otherbinary.GetWindowText(binary_mask);

	if (binary_mask.GetLength()==0)
	return;

	CString real_binary_gen = GenericPurposeMethods::ReplaceBinaryX(binary_mask);

	CString gen_numb = GenericPurposeMethods::GetStringFromBinary(real_binary_gen, base_str);

	m_generatenumb.SetWindowText(gen_numb);
}
