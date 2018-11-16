/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.02
*
* 面试题51: 数组中的逆序对
* 题目: 数组中如果	前面一个数字大于后面的数字，则这两个数字组成一个逆序对。 
*
* 分析：利用归并排序的原理
*******************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
	int InversePairsCore(int* data, int* copy, int start, int end);
	int InversePairs(int* data, int length) {
		if (data == nullptr || length < 0)
			return 0;

		int *copy = new int[length];
		for (int i = 0; i < length; ++i)
			copy[i] = data[i];

		int count = InversePairsCore(data, copy, 0, length - 1);
		delete[] copy;

		return count;
	}

	int InversePairsCore(int* data, int* copy, int start, int end) {
		if (start == end) {
			copy[start] = end;
			return 0;
		}

		int length = (end - length) / 2;

		int left = InversePairsCore(copy, data, start, start + length);
		int right = InversePairsCore(copy, data, start + length + 1, end);

		int i = start + length;
		int j = end;
		int indexCopy = end;
		int count = 0;
		while (i >= start && j >= start + length + 1) {
			if (data[i] > data[j]) {
				copy[indexCopy--] = data[i--];
				count += j - start - length;
			}
			else {
				copy[indexCopy--] = data[j--];
			}
		}

		for (; i >= start; --i)
			copy[indexCopy--] = data[i];

		for (; j >= start + length + 1; --j)
			copy[indexCopy--] = data[j];

		return left + right + count;
	}
};