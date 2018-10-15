/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.15
*
* 面试题39: 数组中次数超过一半的数字
* 题目：数组中一个数字出现的次数超过数组长度的一半，找出这个数字。
*
* 分析：一个数字出现的次数超过数组的一半，说明他出现的次数要比其他所有
* 数字出现的次数的和还要多，所以遍历数组的时候保存两个值，一个数组的数
* 字，另一个是次数。
*******************************************************************/

class Solution {
public:
	bool g_bInputInvalid = false;

	bool CheckInvalidArray(int* number, int length) {
		g_bInputInvalid = false;
		if (number == nullptr || length <= 0)
			g_bInputInvalid = true;

		return g_bInputInvalid;
	}

	bool CheckMoreThanHalf(int* numbers, int length, int number) {
		int times = 0;
		for (int i = 0; i < length; ++i) {
			if (numbers[i] == number)
				times++;
		}

		bool isMoreThanHalf = true;
		if (times * 2 <= length) {
			g_bInputInvalid = true;
			isMoreThanHalf = false;
		}

		return isMoreThanHalf;
	}

	int MoreThanHalfNum(int* numbers, int length) {
		if (CheckInvalidArray(numbers, length))
			return 0;

		int result = numbers[0];
		int times = 1;
		for(int i = 1; i < length; ++i) {
			if (times == 0) {
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result) {
				times++;
			}
			else
				times--;
		}

		if (!CheckMoreThanHalf(numbers, length, result))
			result = 0;

		return result;
	}
};