/*******************************************************************
Copyright(c) 2018, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
//  作者：何海涛
//  C++
//==================================================================

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

#include<iostream>

using namespace std;

bool Find(int *matrix, int rows, int columns, int numbers) {
	bool found = false;
	if (matrix != nullptr && rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0) {
			if (matrix[row*columns + column] == numbers) {
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > numbers)
				--column;
			else
				++row;
		}
	}
	return found;
}

//===============================测试====================================
void Test(char* testName, int* matrix, int rows, int columns, int numbers, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	bool result = Find(matrix, rows, columns, numbers);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}


// 二维数组中包含查找的数字
void test1() {
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int *test = (int*) matrix;
	cout << test[10] << endl;
	char test1[] = "Test1";
	Test(test1, (int*)matrix, 4, 4, 7, true);
}

// 二维数组中没有查找的数字
void test2() {
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int *test = (int*)matrix;
	char test2[] = "Test2";
	Test(test2, (int*)matrix, 4, 4, 14, false);
}

// 特殊输入测试
void test3() {
	char test3[] = "Test3";
	Test(test3, nullptr, 0, 0, 16, false);
}

int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}