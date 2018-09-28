/*******************************************************************
Copyright(c) 2017, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
//  作者：何海涛
//  C++
//==================================================================

// 面试题3：数组中重复的数字
// 题目1：找出数组中重复的数字

#include<iostream>

using namespace std;

bool duplicate(int numbers[], int length, int* duplicate) {
	if (numbers == 0 || length < 0)
		return false;
	for (int i = 0; i < length; i++) {
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplicate = numbers[i];
				return true;
			}

			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

//=========================test=====================================
// 长度为n的数组里包含一个或多个重复的数字
void test1() {
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	int length = sizeof(numbers)/sizeof(int);
	int duplication;
	bool result = duplicate(numbers, length, &duplication);
	cout << result << endl;
}

// 数组里不包含重复的数字
void test2() {
	int numbers[] = { 2, 3, 1, 0, 5};
	int length = sizeof(numbers) / sizeof(int);
	int duplication;
	bool result = duplicate(numbers, length, &duplication);
	cout << result << endl;
}

// 无效的输入用例
void test3() {
	int* numbers = nullptr;
	int length = sizeof(numbers) / sizeof(int);
	int duplication;
	bool result = duplicate(numbers, length, &duplication);
	cout << result << endl;
}
int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}
