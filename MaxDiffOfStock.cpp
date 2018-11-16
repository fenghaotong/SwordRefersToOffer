/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.13
*
* 面试题63: 股票的最大利润
* 题目：股票价格按时间顺序存到一个数组中，如[9,11,8,5,7,12,16,14]，为买卖该股
* 票一次可能获得的最大利润是多少。
*
********************************************************************/
class Solution {
public:
	int MaxDiff(const int* numbers, unsigned length) {
		if (numbers == nullptr && length < 2)
			return 0;

		int min = numbers[0];
		int maxDiff = numbers[1] - min;

		for (int i = 2; i < length; ++i) {
			if (numbers[i - 1] < min)
				min = numbers[i - 1];

			int currentDiff = numbers[i] - min;
			if (currentDiff > maxDiff)
				maxDiff = currentDiff;
		}

		return maxDiff;
	}
};