/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.15
*
* 面试题38: 字符串的排列
* 题目：输入一个字符串，打印该字符串中字符的所有排列，例如， 输入字符串
* abc，则打印出有字符a、b、c所能排列出来的所有字符串。
*
* 分析：把字符串分成两个部分，一部分是字符串的第一个字符，另一部分是
* 第一个字符串的排列，然后拿第一个字符和它后面的字符逐个交换。
*******************************************************************/
#include<iostream>
class Solution {
public:
	void Permutation(char* pStr) {
		if (pStr = nullptr)
			return;

		Permutation(pStr, pStr);
	}

	void Permutation(char* pStr, char* pBegin) {
		if (*pBegin == '\0') {
			std::cout << pStr << std::endl;
		}
		else {
			for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
				char temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;

				Permutation(pStr, pBegin + 1);

				temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;
			}
		}
	}
};