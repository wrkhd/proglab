#include "String.h"
#include <iostream>

using namespace std;

String::String(int val) :len(val), pCh(new char[len + 1])
{
	if (val == 0) pCh[0] = '\0';
	cout << "String::String(int val)" << endl;
}

String::String(char ch) :len(1), pCh(new char[len + 1])
{
	pCh[0] = ch;
	pCh[1] = '\0';
	cout << "String::String(char ch)" << endl;
}

String::String(const char* S)
{
	cout << "String::String(const char* S)" << endl;

	const char* ptr = S;
	while (*ptr++)
		len = ptr - S;

	pCh = new char[len + 1];

	const char* ptr1 = S;
	char* ptr2 = pCh;
	while (*ptr2++ = *ptr1++)
		*ptr2 = '\0';
	cout << pCh << endl;

	cout << "...." << endl;
}

String::String(const String& from) :len(strlen(from.pCh)), pCh(new char[from.len + 1])
{
	strcpy_s(pCh, len + 1, from.pCh);
	cout << "String::String(const String& from)" << endl;
}

String::~String()
{
	if (pCh)
		delete[]pCh;
	cout << "String::~String()" << endl;
}

void String::Show(void)
{
	cout << "pCh = " << pCh << endl;
	cout << "len = " << len << endl;
}