/*******************************************************************
Copyright(c) 2018, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
//  作者：何海涛
//  C++
//==================================================================

// 面试题3：数组中重复的数字
// 题目2：不修改数组找出重复的数字

#include<iostream>

using namespace std;

int countRange(const int* numbers, int length, int start, int end) {
	if (numbers == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}
	return count;
}
int getDuplicate(const int *numbers, int length) {
	if (numbers == nullptr || length < 0)
		return -1;

	int start = 1;
	int end = length - 1;
	while (end >= start) {
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start) {
			if (count > 1)
				return start;
			else
				break;
		}

		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;	
	}
	return -1;
}
//=========================test=====================================
// 长度为n的数组里包含一个或多个重复的数字
void test1() {
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	int length = sizeof(numbers) / sizeof(int);
	int result =getDuplicate(numbers, length);
	cout << result << endl;
}

// 数组里不包含重复的数字
void test2() {
	int numbers[] = { 2, 3, 1, 0, 5 };
	int length = sizeof(numbers) / sizeof(int);
	int result = getDuplicate(numbers, length);
	cout << result << endl;
}

// 无效的输入用例
void test3() {
	int* numbers = nullptr;
	int length = sizeof(numbers) / sizeof(int);
	int result = getDuplicate(numbers, length);
	cout << result << endl;
}

int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}
