/*******************************************************************
Copyright(c) 2018, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》C++代码
//
// 面试题5：字符串替换空格
// 题目：实现一个函数，把字符串中的每个空格替换成“%20”（空格的ASCII为32,十六进制的0x20）
//==================================================================

#include<iostream>

using namespace std;

// 功能函数
void ReplaceBlank(char string[], int length) {
	if (string == nullptr || length < 0)
		return;

	// 遍历一次得到字符串长度和空格个数
	int orignalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0') {
		++orignalLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}

	// 把空格替换成“%20”后字符串长度为newLength
	int newLength = orignalLength + numberOfBlank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = orignalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (string[indexOfOriginal] == ' ') {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else {
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

//================================测试代码==================================
void Test(char *testName, char string[], int length, char except[]) {
	if (testName != nullptr)
		cout << testName << ":";

	ReplaceBlank(string, length);

	if (except == nullptr && string == nullptr)
		cout << "passed." << endl;
	else if (except == nullptr && string != nullptr)
		cout << "failed." << endl;
	else if(strcmp(string, except) == 0)
		cout << "passed." << endl;
	else
		cout << "failed." << endl;
}

// 输入的字符串中包含空格
void test1() {
	const int length = 100;
	char str[length] = "hello world";
	char test[] = "test1";
	char except[] = "hello%20world";
	Test(test, str, length, except);

}

// 输入的字符串中没有空格
void test2() {
	const int length = 100;
	char str[length] = "helloworld";
	char test[] = "test2";
	char except[] = "helloworld";
	Test(test, str, length, except);
}

// 字符串是个nullptr指针
void test3() {
	const int length = 0;
	char test[] = "test3";
	Test(test, nullptr, length, nullptr);
}

// 主函数
int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}
