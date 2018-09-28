/*******************************************************************
Copyright(c) 2018, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
//  ���ߣ��κ���
//  C++
//==================================================================

// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
// �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�����

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

//===============================����====================================
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


// ��ά�����а������ҵ�����
void test1() {
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int *test = (int*) matrix;
	cout << test[10] << endl;
	char test1[] = "Test1";
	Test(test1, (int*)matrix, 4, 4, 7, true);
}

// ��ά������û�в��ҵ�����
void test2() {
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int *test = (int*)matrix;
	char test2[] = "Test2";
	Test(test2, (int*)matrix, 4, 4, 14, false);
}

// �����������
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