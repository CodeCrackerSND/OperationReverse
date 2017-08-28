// GenericPurposeMethods.h: interface for the GenericPurposeMethods class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENERICPURPOSEMETHODS_H__900D1212_DF48_4A0B_ADFA_E20410006D7C__INCLUDED_)
#define AFX_GENERICPURPOSEMETHODS_H__900D1212_DF48_4A0B_ADFA_E20410006D7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class GenericPurposeMethods  
{
public:
	GenericPurposeMethods();
	virtual ~GenericPurposeMethods();

	static char* TruncateString(char *value, int newlen);
	static bool IsHexNumber(char tobetested);
	static CString NumbtoBinaryStr(unsigned int n);
	static void NumbtoBinaryStrRec(unsigned int n);
	static unsigned int Pow(int value,int exponent);
	static unsigned int GetIntFromStr(char *value, char *base1);
	static unsigned int GetIntFromTStr(char *buffer, char *base1);

	static CString ReverseOp(char *operation1, CString result_bin, CString oneop_bin);
	static CString ReverseXor(CString result_bin, CString oneop_bin);
	static CString ReverseOr(CString result_bin, CString oneop_bin);
	static CString ReverseAnd(CString result_bin, CString oneop_bin);
	static CString ReplaceBinaryX(CString binary);
	static CString GetStringFromBinary(CString binary, CString base_str);

};

#endif // !defined(AFX_GENERICPURPOSEMETHODS_H__900D1212_DF48_4A0B_ADFA_E20410006D7C__INCLUDED_)
