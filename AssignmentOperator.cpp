/*******************************************************************
Copyright(c) 2017, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
//  ���ߣ��κ���
//  C++
//==================================================================

// ������1����ֵ���������
// ��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������

#include<iostream>
#include<string>

using namespace std;


// ===================������=====================
template<class T>
class CMyString {
public:
	CMyString(T* pData = nullptr);
	CMyString(const CMyString<T>& str);
	~CMyString(void);

	CMyString<T>& operator = (const CMyString<T>& str);
	void print();

private:
	T* m_pData;
};

template<class T>
CMyString<T>::CMyString(T* pData) {
	if (pData == nullptr) {
		m_pData = new T[1];
		m_pData[0] = '\0';
	}
	else {
		int length = strlen(pData);
		m_pData = new T[length + 1];
		strcpy_s(m_pData, length + 1, pData);
	}
}

template<class T>
CMyString<T>::CMyString(const CMyString<T>& str) {
	int length = strlen(str.m_pData);
	m_pData = new T[length + 1];
	strcpy_s(m_pData, length+1, str.m_pData);
}

template<class T>
CMyString<T>::~CMyString() {
	delete[] m_pData;
}

template<class T>
CMyString<T>& CMyString<T>::operator=(const CMyString<T>& str) {
	if (this == &str)
		return *this;

	delete[] m_pData;
	m_pData = nullptr;

	int length = strlen(str.m_pData);
	m_pData = new T[length + 1];
	strcpy_s(m_pData, length + 1, str.m_pData);

	return *this;
}

//==================���Դ���===================
template<class T>
void CMyString<T>::print() {
	cout << m_pData << endl;
}

// ��һ��CMyString��ʵ����ֵ����һ��ʵ��
void test1() {
	cout << "��һ��CMyString��ʵ����ֵ����һ��ʵ��:" << endl;

	char text[] = "hello test1";
	char *astr = text;
	CMyString<char> str1(astr);
	CMyString<char> str2;
	str2 = str1;

	cout << "The expected result is: " << text << endl;

	cout << "The actual result is:";
	str2.print();
	cout << endl;
}


//��һ��CMyString��ʵ����ֵ���Լ�
void test2() {
	cout << "��һ��CMyString��ʵ����ֵ���Լ�:" << endl;

	char text[] = "hello test2";
	char *astr = text;

	CMyString<char> str1(astr);
	str1 = str1;

	cout << "The expected result is: " << text << endl;

	cout << "The actual result is:";
	str1.print();
	cout << endl;
}

// ������ֵ
void test3() {
	cout << "������ֵ:" << endl;

	char text[] = "hello world!";
	char *astr = text;

	CMyString<char> str1(astr);
	CMyString<char> str2, str3;
	str3 = str2 = str1;

	cout << "The expected result is: " << text << endl;

	cout << "The actual result is:";
	str2.print();

	cout << "The expected result is: " << text << endl;

	cout << "The actual result is:";
	str3.print();
	cout << endl;
}
int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}