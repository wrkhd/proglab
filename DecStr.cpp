#include "DecStr.h"
#include <iostream>

using namespace std;

DecStr::DecStr(int val) :String(val) {
	cout << "DecStr::DecStr(int val) :String(val)" << endl;
}

DecStr::DecStr(char ch) : String(ch) {
	cout << "DecStr::DecStr(char ch) : String(ch)" << endl;
}

DecStr::DecStr(const char* Str) : String(Str) {
	if (!((pCh[0] >= '0' && pCh[0] <= '9') || (pCh[0] == '-') || (pCh[0] == '+'))) {
		cout << "Bad sumbol, pCh[0] = " << pCh[0] << endl;
		if (pCh)delete[]pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}

	for (int i = 1; i < len; i++) {
		if (!(pCh[i] >= '0') && (pCh[i] <= '9')) {
			cout << "Bad String, pCh[" << i << "]=" << pCh[i] << endl;
			if (pCh) delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}

	cout << "DecStr::DecStr(const char* Str) : String(Str)" << endl;
}

DecStr::DecStr(const DecStr& from) : String(from) {
	cout << "DecStr::DecStr(const DecStr & from) : String(from)" << endl;
}

DecStr::~DecStr() {
	cout << "DecStr::~DecStr()" << endl;
}

DecStr& DecStr::operator= (const DecStr& t) {
	if (&t != this) {
		delete[]pCh;
		len = strlen(t.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, t.pCh);
	}
	cout << "DecStr& DecStr::operator= (const DecStr& DS)" << endl;
	return *this;
}

DecStr operator + (const DecStr& x1, const int x2) {
	int n1, n2;
	int count = 0;
	char* result;
	DecStr tmpStr(x1);
	n1 = atoi(tmpStr.GetStr());
	n2 = x2;
	int sum = n1 + n2;

	if ((n2 > 0 && sum < n1) || (n2 < 0 && sum > n1))
	{
		if (tmpStr.pCh) delete[] tmpStr.pCh;
		cout << "Integer arithmetic overflow!" << endl;
		tmpStr.pCh = new char[1];
		tmpStr.pCh[0] = '\0';
		tmpStr.len = strlen(tmpStr.pCh);
		return tmpStr;
	}

	while (n2) {
		count++;
		n2 /= 10;
	}

	if (n2 < 0) {
		count++;
		n2 *= -1;
	}

	if (tmpStr.len < count) {
		result = new char[count + 2];
		_itoa_s(sum, result, count + 2, 10);
	}
	else {
		result = new char[tmpStr.len + 2];
		_itoa_s(sum, result, tmpStr.len + 2, 10);
	}

	if (tmpStr.pCh) delete[] tmpStr.pCh;
	tmpStr.pCh = result;
	tmpStr.len = strlen(tmpStr.pCh);
	return tmpStr;
};

DecStr operator + (const DecStr& x1, const DecStr& x2) {
	int num1, num2;
	DecStr tmp(x1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(x2.GetStr());
	int A = num1 + num2;
	char* pTmpCh;

	if (tmp.len >= x2.len) {
		pTmpCh = new char(tmp.len + 2);
		_itoa_s(A, pTmpCh, tmp.len + 2, 10);
	} 
	
	else {
		pTmpCh = new char[x2.len + 2];
		_itoa_s(A, pTmpCh, x2.len + 2, 10);
	}

	if(tmp.pCh) delete[] tmp.pCh;
	tmp.pCh = pTmpCh;
	tmp.len = strlen(tmp.pCh);
	cout << "DecStr::operator(const DecStr& pobg1, const DecStr& pobg2)" << endl;
	return tmp;
};

DecStr operator + (const int x2, const DecStr& x1) {
	int n1, n2;
	int count = 0;
	char* result;
	DecStr tmpStr(x1);
	n1 = atoi(tmpStr.GetStr());
	n2 = x2;
	int sum = n1 + n2;

	if ((n2 > 0 && sum < n1) || (n2 < 0 && sum > n1))
	{
		if (tmpStr.pCh) delete[] tmpStr.pCh;
		cout << "Integer arithmetic overflow" << endl;
		tmpStr.pCh = new char[1];
		tmpStr.pCh[0] = '\0';
		tmpStr.len = strlen(tmpStr.pCh);
		return tmpStr;
	}

	while (n2) {
		count++;
		n2 /= 10;
	}

	if (n2 < 0) {
		count++;
		n2 *= -1;
	}

	if (tmpStr.len < count) {
		result = new char[count + 2];
		_itoa_s(sum, result, count + 2, 10);
	}
	else {
		result = new char[tmpStr.len + 2];
		_itoa_s(sum, result, tmpStr.len + 2, 10);
	}

	if (tmpStr.pCh) delete[] tmpStr.pCh;
	tmpStr.pCh = result;
	tmpStr.len = strlen(tmpStr.pCh);
	return tmpStr;
};

DecStr operator - (const DecStr& x1, const DecStr& x2) {
	int num1, num2;
	DecStr tmp(x1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(x2.GetStr());
	char* pTmpCh;
	int A = num1 - num2;

	if (x1.len >= x2.len) {
		pTmpCh = new char[tmp.len + 2];
		_itoa_s(A, pTmpCh, tmp.len + 2, 10);
	}

	else {
		pTmpCh = new char[x2.len + 2];
		_itoa_s(A, pTmpCh, x2.len + 2, 10);
	}

	if (tmp.pCh) delete[]tmp.pCh;
	tmp.pCh = pTmpCh;
	tmp.len = strlen(tmp.pCh);
	cout << "DecStr operator - for const DecStr& x1 and const DecStr& x2" << endl;
	return tmp;
};