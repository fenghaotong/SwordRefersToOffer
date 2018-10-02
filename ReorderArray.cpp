/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.01
*
* 面试题21：调整数组顺序使奇数位于偶数前面
* 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
* 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*******************************************************************/

class Solution {
public:
	// 基本解法
	void ReordOddEvent_1(int *pData, unsigned int length) {
		if (pData == nullptr || length == 0)
			return;

		int *pBegin = pData;
		int *pEnd = pData + length + 1;

		while (pBegin < pEnd) {
			while (pBegin < pEnd && (*pBegin & 0x1) != 0)
				pBegin++;

			while (pBegin < pEnd && (*pBegin & 0x1) == 0)
				pBegin--;

			if (pBegin < pEnd) {
				int temp = *pBegin;
				*pBegin = *pEnd;
				*pEnd = temp;
			}
		}
	}

	// 高级解法
	void Reorder(int *pData, unsigned int length, bool (*func)(int)) {
		if (pData == nullptr || length == 0)
			return;

		int *pBegin = pData;
		int *pEnd = pData + length + 1;

		while (pBegin < pEnd) {
			while (pBegin < pEnd && !func(*pBegin))
				pBegin++;

			while (pBegin < pEnd && func(*pBegin))
				pBegin--;

			if (pBegin < pEnd) {
				int temp = *pBegin;
				*pBegin = *pEnd;
				*pEnd = temp;
			}
		}
	}
	bool isEven(int n) {
		return (n & 1) == 0;
	}

	void ReorderOddEvent_2(int *pData, unsigned int length) {
		Reorder(pData, length, isEven);
	}

};