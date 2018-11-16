/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.09
*
* 面试题57: 和为s的数字
* 题目一：和为s的两个数字
*
* 分析: 因为是递增排序的数组，使用前后两个指针，相加，如何和大于s，后面的
* 指针向前移动，如果和小于s，前面的指针向后移动。
*
* 题目二： 和为s的连续正数序列
*
* 分析： 使用small和big表示序列的最小值和最大值，初始化为small=1，big=2，
* 如果small和big之间的序列和小于s，则big加1，如果small和big之间的序列和
* 大于s，则small加1。
********************************************************************/
#include<iostream>

using namespace std;


class Sulotion {
public:
	// 题目一：和为s的两个数字
	bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2) {
		bool found = false;
		if (length < 1 || num1 == nullptr || num2 == nullptr)
			return found;

		int ahead = length - 1;
		int behind = 0;

		while (ahead > behind) {
			long long curSum = data[ahead] + data[behind];

			if (curSum == sum) {
				*num1 = data[behind];
				*num2 = data[ahead];
				found = true;
				break;
			}
			else if (curSum > sum)
				ahead--;
			else
				behind++;
		}

		return found;
	}

	// 题目二： 和为s的连续正数序列

	void PrintCountinuousSequence(int small, int big) {
		for (int i = small; i <= big; ++i) {
			cout << i << endl;
		}
	}
	void FindContinuousSequence(int sum) {
		if (sum < 3)
			return;

		int small = 1;
		int big = 2;
		int middle = (1 + sum) / 2;
		int curSum = small + big;

		while (small < middle) {
			if (curSum == sum)
				PrintCountinuousSequence(small, big);

			while (curSum > sum && small < middle) {
				curSum -= small;
				small++;

				if (curSum == sum)
					PrintCountinuousSequence(small, big);
			}

			big++;
			curSum += big;
		}
	}

};