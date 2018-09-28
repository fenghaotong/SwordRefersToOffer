/*******************************************************************
Copyright(c) 2017, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
//  ���ߣ��κ���
//  C++
//==================================================================

// ������3���������ظ�������
// ��Ŀ1���ҳ��������ظ�������

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
// ����Ϊn�����������һ�������ظ�������
void test1() {
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	int length = sizeof(numbers)/sizeof(int);
	int duplication;
	bool result = duplicate(numbers, length, &duplication);
	cout << result << endl;
}

// �����ﲻ�����ظ�������
void test2() {
	int numbers[] = { 2, 3, 1, 0, 5};
	int length = sizeof(numbers) / sizeof(int);
	int duplication;
	bool result = duplicate(numbers, length, &duplication);
	cout << result << endl;
}

// ��Ч����������
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
