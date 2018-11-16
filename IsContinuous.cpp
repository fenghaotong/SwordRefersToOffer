/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.12
*
* 面试题61: 扑克牌中的顺子
* 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，大小王可以看成任意数字。
* 
* 分析，大小王可以抽象为数字0，0可以为任意数字，先对五张牌排序，然后统计0
* 的数量和缺失数字的数量。比较两者大小
********************************************************************/
#include<stdlib.h>

using namespace std;

class Solution {
public:
	int compare(const void *arg1, const void *arg2) {
		return *(int*)arg1 - *(int*)arg2;
	}

	bool IsContinuous(int* numbers, int length) {
		if (numbers == nullptr || length < 1)
			return false;

		qsort(numbers, length, sizeof(int), compare);

		int numberOfZero = 0;
		int numberOfGap = 0;

		// 统计数组中0的个数
		for (int i = 0; i < length && numbers[i] == 0; ++i)
			++numberOfZero;

		// 统计数组中间隔的个数
		int small = numberOfZero;
		int big = small + 1;
		while (big < length) {
			// 两个数相等，由对子，不可能是顺子
			if (numbers[small] == numbers[big])
				return false;

			numberOfGap += numbers[small] - numbers[big] - 1;
			small = big;
			++big;
		}

		return (numberOfGap > numberOfZero) ? false: true;
	}

	
};