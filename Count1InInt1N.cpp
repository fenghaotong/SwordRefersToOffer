/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.23
*
* 面试题43: 1-n整数中1出现的次数
* 题目：输入一个整数n，求1-n这n个整数的十进制表示中1出现的次数。
*
* 分析，最简单的算法就是让每个数字都除以10，看看余数是否为1，但是如果有
* n个数，每个数有logn位那么时间复杂度为O(nlogn);
*******************************************************************/
#include<stdio.h>
#include<string>

using namespace std;

class Solution {
public:
	int PowerBase10(unsigned int n);
	int NumberOf1(const char* strN);
	int NumberOf1Between1AndN(int n) {
		if (n <= 0)
			return 0;

		char strN[50];
		sprintf(strN, "%d", n);

		return NumberOf1(strN);
	}

	int NumberOf1(const char* strN) {
		if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
			return 0;

		int first = *strN - '0';
		unsigned int length = static_cast<unsigned int>(strlen(strN));

		if (length == 1 && first == 0)
			return 0;

		if (length == 1 && first > 0)
			return 1;

		int numFirstDigit = 0;
		if (first > 1)
			numFirstDigit = PowerBase10(length - 1);
		else if (first == 1)
			numFirstDigit = atoi(strN + 1) + 1;

		int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
		int numRecursive = NumberOf1(strN + 1);

		return numFirstDigit + numOtherDigits + numRecursive;
	}

	int PowerBase10(unsigned int n) {
		int result = 1;
		for (unsigned int i = 0; i < n; ++i)
			result *= 10;

		return result;
	}
};