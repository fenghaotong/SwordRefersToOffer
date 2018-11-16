/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.01
*
* 面试题50: 第一个只出现一次的字符
* 题目: 字字符串中找出第一个只出现一次的字符。
*
* 分析：使用hash表
*******************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
	char FirstNotRepeatingChar(char* pString) {
		if (pString = nullptr)
			return '\0';

		const int tableSize = 256;
		unsigned int hashTable[tableSize];

		for (unsigned int i = 0; i < tableSize; i++)
			hashTable[i] = 0;

		char* pHashKey = pString;

		while (*(pHashKey) != '\0') {
			hashTable[*(pHashKey++)]++;
		}

		pHashKey = pString;

		while (*pHashKey != '\0') {
			if (hashTable[*pHashKey] == 1)
				return *pHashKey;

			pHashKey++;
		}

		return '\0';
	}
};

