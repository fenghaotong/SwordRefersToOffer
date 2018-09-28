/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.21
*
* 面试题11: 旋转数组的最小数字
* 题目： 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
* 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素
*******************************************************************/

#include<iostream>
#include<exception>

using namespace std;

int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length) {
	if (numbers == nullptr || length <= 0)
		throw new std::exception("Invaild paramter");


	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		if (numbers[index1] == numbers[index1] && numbers[index1] == numbers[indexMid])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2) {
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++) {
		if (result > numbers[i])
			result = numbers[i];
	}
	return result;
}

//=========================================测试代码======================================
void Test(char* testName, int* numbers, int length, int excepted) {
	if (testName != nullptr)
		cout << testName << ":" << endl;
	try {
		int result = Min(numbers, length);

		if (excepted == result)
			cout << "Passed!" << endl;
		else
			cout << "Failed!" << endl;
	}
	catch (...) {
		if(numbers == nullptr)
			cout << "Passed!" << endl;
		else
			cout << "Failed!" << endl;
	}
	
}

// 功能测试
void test1() {
	char test[] = "test1";
	int numbers[] = { 3,4,5,1,2 };
	int length = sizeof(numbers) / sizeof(int);
	int excepted = 1;
	Test(test, numbers, length, excepted);
}

// 边界值测试
void test2() {
	char test[] = "test2";
	int numbers[] = { 1,0,1,1,1 };
	int length = sizeof(numbers) / sizeof(int);
	int excepted = 0;
	Test(test, numbers, length, excepted);
}

// 特殊输入测试
void test3() {
	char test[] = "test3";
	Test(test, nullptr, 0, 0);
}

int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}