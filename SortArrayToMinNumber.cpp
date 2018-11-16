/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.24
*
* 面试题45: 把数组排成最小的数
* 题目: 输入一个正整数数组， 把数组里的数字拼接起来排成一个数，打印能
* 拼接出的所有数字中最小的一个。
*
* 分析，给定两个数字m和n，将两个数合并为mn或者nm，如果mn < nm，那么打印出
* mn，就是m在n前面，此时定义m小于n；相反如果mn > nm,定义n小于m；如果mn==nm
* 定义m等于n，因为m和n拼接的数字用int型可能溢出，所以要把数字转换成字符串。
*******************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class Solution {
public:
	int compare(const void* strNumber1, const void* strNumber2);

	void PrintMinNumber(int* numbers, int length) {
		if (numbers == nullptr || length <= 0) {
			return;
		}

		char** strNumbers = (char**)(new int[length]);
		for (int i = 0; i < length; ++i) {
			strNumbers[i] = new char[g_MaxNumberLength + 1];
			sprintf(strNumbers[i], "%d", numbers[i]);
		}

		qsort(strNumbers, length, sizeof(char*), compare);

		for (int i = 0; i < length; ++i)
			cout << strNumbers[i];
		cout << endl;

		for (int i = 0; i < length; ++i)
			delete[] strNumbers[i];
		delete[] strNumbers;
	}

	int compare(const void* strNumber1, const void* strNumber2) {
		strcpy(g_StrCombine1, *(const char**)strNumber1);
		strcat(g_StrCombine1, *(const char**)strNumber2);

		strcpy(g_StrCombine2, *(const char**)strNumber2);
		strcat(g_StrCombine2, *(const char**)strNumber1);

		return strcmp(g_StrCombine1, g_StrCombine2);
	}
private:
	const int g_MaxNumberLength = 10;

	char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
	char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];
};