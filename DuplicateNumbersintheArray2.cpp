/*******************************************************************
Copyright(c) 2018, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
//  ���ߣ��κ���
//  C++
//==================================================================

// ������3���������ظ�������
// ��Ŀ2�����޸������ҳ��ظ�������

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
// ����Ϊn�����������һ�������ظ�������
void test1() {
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	int length = sizeof(numbers) / sizeof(int);
	int result =getDuplicate(numbers, length);
	cout << result << endl;
}

// �����ﲻ�����ظ�������
void test2() {
	int numbers[] = { 2, 3, 1, 0, 5 };
	int length = sizeof(numbers) / sizeof(int);
	int result = getDuplicate(numbers, length);
	cout << result << endl;
}

// ��Ч����������
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
