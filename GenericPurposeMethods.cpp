// GenericPurposeMethods.cpp: implementation of the GenericPurposeMethods class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OperationReverse.h"
#include "GenericPurposeMethods.h"

#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GenericPurposeMethods::GenericPurposeMethods()
{

}

GenericPurposeMethods::~GenericPurposeMethods()
{

}

unsigned int GenericPurposeMethods::GetIntFromStr(char *value, char *base1)
{
unsigned int converted = 0;
int max_len = 0;
if (value[0] == '-') max_len++;  // for negative number increment
if (strcmp(base1,CString(_T("decimal")).GetBuffer(0))==0)
{  // if decimal as base
max_len = max_len+3*4;
}
else if (strcmp(base1,CString(_T("hexadecimal")).GetBuffer(0))==0)
{  // if hexadecimal as base
max_len = max_len+2*4;
}
else if (strcmp(base1,CString(_T("binary")).GetBuffer(0))==0)
{  // if binary as base
max_len = max_len+32;  // max 32 chars
}

char *truncated_value = GenericPurposeMethods::TruncateString(value, max_len);
converted = GenericPurposeMethods::GetIntFromTStr(value, base1);
return converted;
}

unsigned int GenericPurposeMethods::GetIntFromTStr(char *buffer, char *base1)
{
   unsigned int result1 = 0;
   int startIndex = 0;
   bool negativeNumber = false;

   if (buffer[0] == '-')
   {
   negativeNumber = true;
   startIndex = 1;
   }

   bool isdecimal = (strcmp(base1,CString(_T("decimal")).GetBuffer(0))==0);
   bool isbinary  = (strcmp(base1,CString(_T("binary")).GetBuffer(0))==0);

   for (int i = startIndex; i < (int)strlen(buffer); i++)
   {

	if (isdecimal)
	{
      if (buffer[i] >= '0' && buffer[i] <= '9')
      {
         unsigned int digit = buffer[i] - '0';
         result1 = result1 * 10 + digit;
      }
      else
      return 0;
	  
	}
	else if (isbinary)
	{

      if (buffer[i] >= '0' && buffer[i] <= '1')
      {
         unsigned int digit = buffer[i] - '0';
         result1 = result1 * 2 + digit;
      }
      else
      return 0;
	}
	else  // hexadecimal parse:
	{
	if (!GenericPurposeMethods::IsHexNumber(buffer[i])) return 0;

	  if(buffer[i])
      {
	  unsigned int current_char = buffer[i]-'0';
	  if (current_char>=0x011&&current_char<=0x016)  // is it 'A'- 'F'
	  current_char = current_char - 07;

	  if (current_char>=0x031&&current_char<=0x036)  // is it 'a'- 'f'
	  current_char = current_char - 0x27;

      result1 += current_char*Pow(16,strlen(buffer)-1-i);
      }
	}

   }

   if (negativeNumber == true)
      result1 *= -1;

   return result1;
}

bool GenericPurposeMethods::IsHexNumber(char tobetested)
{
if (tobetested >= '0' && tobetested <= '9')
return true;

if (tobetested >= 'A' && tobetested <= 'F')
return true;

if (tobetested >= 'a' && tobetested <= 'f')
return true;

return false;
}

unsigned int GenericPurposeMethods::Pow(int value,int exponent)
{
	unsigned int result1 = 1;

	for (int i = 0; i < exponent; ++i)
	result1 *= value;

	return (result1);
}

char* GenericPurposeMethods::TruncateString(char *value, int newlen)
{
int ostrlen = strlen(value);
if (ostrlen<=newlen) return value;  // no truncate needed!

char* array = new char[newlen+1];
for (int i=0;i<newlen;i++)
array[i] = value[i];

array[newlen] = 0; // end marker char

return array;
}

CString local_r;
CString GenericPurposeMethods::NumbtoBinaryStr(unsigned int n)
{
	local_r = "";
	NumbtoBinaryStrRec(n);
    return local_r;
}

void GenericPurposeMethods::NumbtoBinaryStrRec(unsigned int n)
{
    local_r=(n%2==0 ?"0":"1")+local_r;
    if (n / 2 != 0) {
        NumbtoBinaryStrRec(n / 2);
    }

}

CString GenericPurposeMethods::ReverseOp(char *operation1, CString result_bin, CString oneop_bin)
{

if (strcmp(operation1,CString(_T("xor")).GetBuffer(0))==0)
return ReverseXor(result_bin, oneop_bin);
else
if (strcmp(operation1,CString(_T("or")).GetBuffer(0))==0)
return ReverseOr(result_bin, oneop_bin);
if (strcmp(operation1,CString(_T("and")).GetBuffer(0))==0)
return ReverseAnd(result_bin, oneop_bin);

return "Error";
}

CString GenericPurposeMethods::ReverseXor(CString result_bin, CString oneop_bin)
{

if (oneop_bin.GetLength()>result_bin.GetLength())
{
for (int i=0;i<(oneop_bin.GetLength()-result_bin.GetLength());i++)
result_bin = '0'+result_bin;
}
else
{
for (int i=0;i<(result_bin.GetLength()-oneop_bin.GetLength());i++)
oneop_bin = '0'+oneop_bin;
}


CString other_op = "";

for (int i=result_bin.GetLength()-1;i>=0;i--)
{

TCHAR result_c = '0';
if (i<result_bin.GetLength())
result_c = result_bin.GetAt(i);

TCHAR oneop_c = '0';
if (i<oneop_bin.GetLength())
oneop_c = oneop_bin.GetAt(i);

TCHAR other_c = '0';

// 0 xor 0 = 0
// 1 xor 0 = 1
// 0 xor 1 = 1
// 1 xor 1 = 0

if (result_c=='0'&&oneop_c=='0')
other_c = '0';
else if (result_c=='0'&&oneop_c=='1')
other_c = '1';

else if (result_c=='1'&&oneop_c=='1')
other_c = '0';
else if (result_c=='1'&&oneop_c=='0')
other_c = '1';

other_op = other_c+other_op;

}

return other_op;

}

CString GenericPurposeMethods::ReverseOr(CString result_bin, CString oneop_bin)
{

if (oneop_bin.GetLength()>result_bin.GetLength())
{
for (int i=0;i<(oneop_bin.GetLength()-result_bin.GetLength());i++)
result_bin = '0'+result_bin;
}
else
{
for (int i=0;i<(result_bin.GetLength()-oneop_bin.GetLength());i++)
oneop_bin = '0'+oneop_bin;
}


CString other_op = "";

for (int i=result_bin.GetLength()-1;i>=0;i--)
{

TCHAR result_c = '0';
if (i<result_bin.GetLength())
result_c = result_bin.GetAt(i);

TCHAR oneop_c = '0';
if (i<oneop_bin.GetLength())
oneop_c = oneop_bin.GetAt(i);

TCHAR other_c = '0';

// 0 or 0 = 0
// 1 or 0 = 1
// 0 or 1 = 1
// 1 or 1 = 1

if (result_c=='0'&&oneop_c=='0')
other_c = '0';
else if (result_c=='0'&&oneop_c=='1')
return "ERROR";  // this is impossible

else if (result_c=='1'&&oneop_c=='1')
other_c = 'x';  // any of 0 or 1
else if (result_c=='1'&&oneop_c=='0')
other_c = '1';

other_op = other_c+other_op;

}

return other_op;

}

CString GenericPurposeMethods::ReverseAnd(CString result_bin, CString oneop_bin)
{

if (oneop_bin.GetLength()>result_bin.GetLength())
{
for (int i=0;i<(oneop_bin.GetLength()-result_bin.GetLength());i++)
result_bin = '0'+result_bin;
}
else
{
for (int i=0;i<(result_bin.GetLength()-oneop_bin.GetLength());i++)
oneop_bin = '0'+oneop_bin;
}


CString other_op = "";

for (int i=result_bin.GetLength()-1;i>=0;i--)
{

TCHAR result_c = '0';
if (i<result_bin.GetLength())
result_c = result_bin.GetAt(i);

TCHAR oneop_c = '0';
if (i<oneop_bin.GetLength())
oneop_c = oneop_bin.GetAt(i);

TCHAR other_c = '0';

// 0 and 0 = 0
// 1 and 0 = 0
// 0 and 1 = 0
// 1 and 1 = 1

if (result_c=='0'&&oneop_c=='0')
other_c = 'x'; // any of 0 or 1
else if (result_c=='1'&&oneop_c=='0')
return "ERROR";
else if (result_c=='1'&&oneop_c=='1')
other_c = '1';
else if (result_c=='0'&&oneop_c=='1')
other_c = '0'; 

other_op = other_c+other_op;

}

return other_op;

}

CString GenericPurposeMethods::ReplaceBinaryX(CString binary)
{


	for (int i=0;i<binary.GetLength();i++)
	{

	if (tolower(binary.GetAt(i))=='x')
	{
	int rand_num = (rand()&01)+'0';  // only 0 or 1
	binary.SetAt(i,rand_num);
	}

	}

	return binary;

}

CString GenericPurposeMethods::GetStringFromBinary(CString binary, CString base_str)
{
if (strcmp(base_str,CString(_T("binary")).GetBuffer(0))==0)
{  // if binary as base
return binary;
}
else if (strcmp(base_str,CString(_T("decimal")).GetBuffer(0))==0)
{  // if decimal as base
	unsigned int numb1 = GenericPurposeMethods::GetIntFromTStr(binary.GetBuffer(0), _T("binary"));

	char* converted1 = new char[4*3+1];
	converted1[0] = 00;
	wsprintf(converted1,"%d", numb1);  // convert int number to decimal string

	return CString(converted1);
}
else if (strcmp(base_str,CString(_T("hexadecimal")).GetBuffer(0))==0)
{  // if hexadecimal as base
	unsigned int numb2 = GenericPurposeMethods::GetIntFromTStr(binary.GetBuffer(0), _T("binary"));

	char* converted2 = new char[4*2+1];
	converted2[0] = 00;
	wsprintf(converted2,"%X",numb2);  // convert int number to hexadecimal string

	return CString(converted2);
}

return "ERROR";

}