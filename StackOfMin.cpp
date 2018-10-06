/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.06
*
* 面试题31: 栈的压入、弹出序列
* 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
* 否为该栈的弹出顺序。
*
*******************************************************************/
#include<stack>

class Solution {
public:
	bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
		bool bPossible = false;
		if (pPush != nullptr && pPop != nullptr && nLength > 0) {
			const int* pNextPush = pPush;
			const int* pNextPop = pPop;

			std::stack<int> stackData;
			while (pNextPop - pPop < nLength) {
				while (stackData.empty() || stackData.top() != *pNextPop) {
					if (pNextPush - pPush == nLength)
						break;

					stackData.push(*pNextPush);
					pNextPop++;
				}

				if (stackData.top() != *pNextPop)
					break;

				stackData.pop();
				pNextPop++;
			}

			if (stackData.empty() && pNextPop - pPop == nLength)
				bPossible = true;
		}

		return bPossible;
	}
};
