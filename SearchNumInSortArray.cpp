/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.07
*
* 面试题53: 数字在排序数组中出现的次数
* 题目一: 数字在排序数组中出现的次数。

* 分析：使用二分查找，找到第一个k和第二个k
*
* 题目二: 0~n-1中缺失的数字
*
* 题目三: 数组中数组和下标相等的元素
*******************************************************************/

class Solution {
public:
	// 题目一
	// 得到第一个k
	int GetFirstK(int* data, int length, int k, int start, int end) {
		if (start > end)
			return -1;

		int middleIndex = (start + end) / 2;
		int middleData = data[middleIndex];

		if (middleData == k) {
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
				return middleIndex;
			else
				end = middleIndex - 1;
		}
		else if (middleData > k)
			end = middleIndex - 1;
		else
			start = middleIndex + 1;

		return GetFirstK(data, length, k, start, end);
	}

	//得到最后一个k
	int GetLastK(int* data, int length, int k, int start, int end) {
		if (start > end)
			return -1;

		int middleIndex = (start + end) / 2;
		int middleData = data[middleIndex];

		if (middleData == k) {
			if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
				return middleIndex;
			else
				start = middleIndex + 1;
		}
		else if (middleData < k)
			start = middleIndex + 1;
		else
			end = middleIndex - 1;

		return GetFirstK(data, length, k, start, end);
	}

	int GetNumberOfK(int* data, int length, int k) {
		int number = 0;
		if (data != nullptr && length > 0) {
			int first = GetFirstK(data, length, k, 0, length - 1);
			int last = GetLastK(data, length, k, 0, length - 1);

			if (first > -1 && last > -1)
				number = last - first + 1;
		}

		return number;
	}

	// 题目二
	int GetMissingNumber(const int* numbers, int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int left = 0;
		int right = length - 1;
		while (left <= right) {
			int middle = (right + left) >> 1;
			if (numbers[middle] != middle) {
				if (middle == 0 || numbers[middle - 1] == middle - 1)
					return middle;
				right = middle - 1;
			}
			else
				left = middle + 1;
		}
		if (left == length)
			return length;

		return -1;
	}

	// 题目三
	int GetNumberSameAsIndex(const int* numbers, int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int left = 0;
		int right = length - 1;
		while (left <= right) {
			int middle = left + (right - left) >> 1;
			if (numbers[middle] == middle)
				return middle;

			if (numbers[middle] > middle)
				right = middle - 1;
			else
				left = middle + 1;
		}

		return -1;
	}
};