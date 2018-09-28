/*******************************************************************
Copyright(c) 2017, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
//  作者：何海涛
//  C++
//==================================================================

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include<iostream>
#include<string>

using namespace std;


// ===================创建类=====================
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

//==================测试代码===================
template<class T>
void CMyString<T>::print() {
	cout << m_pData << endl;
}

// 把一个CMyString的实例赋值给另一个实例
void test1() {
	cout << "把一个CMyString的实例赋值给另一个实例:" << endl;

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


//把一个CMyString的实例赋值给自己
void test2() {
	cout << "把一个CMyString的实例赋值给自己:" << endl;

	char text[] = "hello test2";
	char *astr = text;

	CMyString<char> str1(astr);
	str1 = str1;

	cout << "The expected result is: " << text << endl;

	cout << "The actual result is:";
	str1.print();
	cout << endl;
}

// 连续赋值
void test3() {
	cout << "连续赋值:" << endl;

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