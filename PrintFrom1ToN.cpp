/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.28
*
* 面试题17: 打印从1到最大的n位数
* 题目：输入数字n，an顺序打印从1到最大的n位十进制数，比如输入3，
* 则打印出1、2、3一直到最大的三位数999。
* 
* 分析：有一个陷阱，当n很大的时候，用int或者long long都会溢出，怎么办？
* 使用字符串存储数字
*******************************************************************/

#include<iostream>

using namespace std;

bool Increment(char* number);
void PrintNumber(char* number);
void Print1ToMaxOfNdigitsRecursively(char* number, int length, int index);

// 方法一
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

// 方法二
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