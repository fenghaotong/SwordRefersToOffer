/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.28
*
* ������17: ��ӡ��1������nλ��
* ��Ŀ����������n��an˳���ӡ��1������nλʮ����������������3��
* ���ӡ��1��2��3һֱ��������λ��999��
* 
* ��������һ�����壬��n�ܴ��ʱ����int����long long�����������ô�죿
* ʹ���ַ����洢����
*******************************************************************/

#include<iostream>

using namespace std;

bool Increment(char* number);
void PrintNumber(char* number);
void Print1ToMaxOfNdigitsRecursively(char* number, int length, int index);

// ����һ
void PrintToMaxOfDigits(int n) {
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
		PrintNumber(number);

	delete[] number;
}

bool Increment(char* number) {
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;
		if (nSum >= 10) {
			if (i == 0)
				isOverflow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		 }
		else {
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

void PrintNumber(char* number) {
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for(int i = 0; i < nLength; i++) {
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
			printf("%c", number[i]);		
	}
	cout << "\t";
}

// ������
void Print1ToMaxOfNdigits_2(int n) {
	if (n <= 0) {
		return;
	}

	char *number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; i++) {
		number[0] = i + '0';
		Print1ToMaxOfNdigitsRecursively(number, n, 0);
	}

	delete[] number;
}

void Print1ToMaxOfNdigitsRecursively(char* number, int length, int index) {
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++) {
		number[index + 1] = i + '0';
		Print1ToMaxOfNdigitsRecursively(number, length, index + 1);
	}
}

int main() {
	int n = 3;
	PrintToMaxOfDigits(n);
	Print1ToMaxOfNdigits_2(n);
	system("pause");
	return 0;
}