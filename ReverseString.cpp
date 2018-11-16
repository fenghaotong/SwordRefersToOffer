/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.12
*
* 面试题58: 反转字符串
* 题目一：反转单词顺序
* 题目二：左旋转字符串
* 如： “abcdefg”，输入数字2，函数返回左旋转结果为：“cdefgab”
********************************************************************/
#include<string>

using namespace std;

class Solution {
public:
	// 反转整个句子
	void Reverse(char* pBegin, char* pEnd) {
		if (pEnd == nullptr || pBegin == nullptr) {
			return;
		}

		while (pBegin < pEnd) {
			char temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}

		pBegin++, pEnd--;
	}

	// 左旋转字符串
	char* LeftRotateString(char* pStr, int n) {
		if (pStr != nullptr) {
			int nLength = static_cast<int>(strlen(pStr));
			if (nLength > 0 && n > 0 && n < nLength) {
				char* pFirstStart = pStr;
				char* pFirstEnd = pStr + n - 1;
				char* pSecondStart = pStr + n;
				char* pSecondEnd = pStr + nLength - 1;

				// 反转前n个字符串
				Reverse(pFirstStart, pFirstEnd);
				// 反转后面的字符串
				Reverse(pSecondStart, pSecondEnd);
				// 反转所有的字符串
				Reverse(pFirstStart, pSecondEnd);
			}
		}
	}

};