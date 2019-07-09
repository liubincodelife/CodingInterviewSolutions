#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator=(const CMyString& str);
	void print();
protected:
private:
	char* m_pData;
};

CMyString::CMyString(char* pData)
{
	cout <<"CMyString::CMyString(char* pData) called..."<< endl;
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	cout << "CMyString::CMyString(const CMyString& str) called..." << endl;
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	cout << "CMyString::~CMyString() called..." << endl;
	delete[] m_pData;
}

#if 0
//the basic method
CMyString& CMyString::operator=(const CMyString& str)
{
	cout << "CMyString& CMyString::operator=(const CMyString& str) Basic Method called..." << endl;
	if (this == &str)
	{
		cout <<"it is the same string, return itself..."<< endl;
		return *this;
	}

	delete[] m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}
#else
//the exception safe method
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		cout << "CMyString& CMyString::operator=(const CMyString& str) Exception Safe Method called..." << endl;
		CMyString strTemp(str);
		char *pTempData = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTempData;
	}
	else
	{
		cout << "it is the same string, return itself..." << endl;
	}
	return *this;
}
#endif

void CMyString::print()
{
	cout <<"the string is: "<<m_pData<< endl;
}

void test1(char* strText)
{
	CMyString str1(strText);
	str1.print();
	CMyString str2, str3;
	str3 = str2 = str1;
	str3.print();
	str2.print();
	str1 = str1;
}

int main(int argc, char ** argv)
{
	char inputText[20];
	cout <<"Please input a valid string: ";
	cin >> inputText;
	cout <<"the inputText is: "<< inputText << endl;
	test1(inputText);
	while (true)
	{

	}
	return 0;
}