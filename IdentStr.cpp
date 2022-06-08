#include "IdentStr.h"
#include <iostream>

using namespace std;

IdentStr& IdentStr:: operator = (const IdentStr& S)
{
	if (&S != this)
	{
		delete[]pCh;
		len = strlen(S.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, S.pCh);
	}
	cout << "IdentStr& IdentStr:: operator = (const IdentStr& S)" << endl;
	return *this;
}

char& IdentStr::operator[](int index)
{
	if (index >= 0 && index < len)
	{
		cout << "char& IdentStr::operator[](int index)" << endl;
		return pCh[index];
	}
	return pCh[0];
}

IdentStr IdentStr::operator ~ ()
{
	int i, j;
	char tmp;
	for (i = 0, j = len - 1; i < len / 2; i++, j--)
	{
		tmp = pCh[i];
		pCh[i] = pCh[j];
		pCh[j] = tmp;
	}

	cout << "IdentStr IdentStr::operator ~ ()" << endl;
	return *this;
}

IdentStr::IdentStr(int val) :String(val)
{
	cout << "IdentStr::IdentStr(int val):String(val)" << endl;
}
IdentStr::IdentStr(char ch) : String(ch)
{
	if ((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z'))
	{
		cout << "IdentStr::IdentStr(char ch)" << endl;
	}
	else
	{
		if (pCh)delete[]pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		cout << "Bad sumbol!" << endl;
	}
}

IdentStr::IdentStr(const char* pStr) : String(pStr)
{
	const char* keyword[] =
	{
		"alignas",
		"alignof",
		"auto",
		"bool",
		"break",
		"case",
		"catch",
		"char",
		"char16_t",
		"char32_t",
		"class",
		"const",
		"const_cast",
		"constexpr",
		"continue",
		"decltype",
		"default",
		"delete",
		"do",
		"double",
		"dynamic_cast",
		"else",
		"enum",
		"explicit",
		"extern",
		"false",
		"float",
		"for",
		"friend",
		"goto",
		"if",
		"inline",
		"int",
		"long",
		"mutable",
		"namespace",
		"new",
		"noexcept",
		"nullptr",
		"operator",
		"private",
		"protected",
		"public",
		"return",
		"short",
		"signed",
		"sizeof",
		"static",
		"static_assert",
		"static_cast",
		"struct",
		"switch",
		"template",
		"this",
		"thread_local",
		"throw",
		"true",
		"try",
		"typedef",
		"typeid",
		"typename",
		"union",
		"unsigned",
		"virtual",
		"void",
		"volatile",
		"wchar_t",
		"while"
	};
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(pCh, keyword[i]) == 0)
		{
			cout << "Bad string, pCh = " << pCh << endl;
			delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))
	{
		cout << "Bad symbol" << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	for (int i = 1; i < len; i++)
	{
		if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))
		{
			cout << "Bad string, pCh[" << i << "] = " << pCh << endl;
			cout << "Bad symbol" << endl;
			if (pCh) delete[] pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
}

IdentStr::IdentStr(const IdentStr& from) :String(from)
{
	cout << "IdentStr::IdentStr(const IdentStr& from)" << endl;
}

IdentStr::~IdentStr()
{
	cout << "IdentStr::~IdentStr()" << endl;
}

IdentStr operator + (const IdentStr& x1, const IdentStr& x2)
{
	IdentStr tmp(x1.GetLen() + x2.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = x1.pCh[j++]);
	--i;
	j = 0;
	while (tmp.pCh[i++] = x2.pCh[j++]);
	cout << "IdentStr operator + (const IdentStr& pobg1, const IdentStr& pobg2)" << endl;
	return tmp;
}

IdentStr operator + (const IdentStr& x1, const char* x2)
{
	IdentStr tmp1(x2);
	IdentStr tmp(x1.GetLen() + tmp1.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = x1.pCh[j++]);
	--i;
	j = 0;
	while (tmp.pCh[i++] = tmp1.pCh[j++]);

	cout << "IdentStr operator + (const IdentStr& pobg1, const char* pobg2)" << endl;
	return tmp;
}

IdentStr operator + (const char* x1, const IdentStr& x2)
{
	IdentStr tmp1(x1);
	IdentStr tmp(x2.GetLen() + tmp1.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = tmp1.pCh[j++]);
	--i;
	j = 0;
	while (tmp.pCh[i++] = x2.pCh[j++]);
	cout << "IdentStr operator + (const char* pobg1, const IdentStr& pobg2)" << endl;
	return tmp;
}