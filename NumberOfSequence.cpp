/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.23
*
* 面试题44: 数字序列中某一位的数字
*
* 分析，例如第1001位数字是多少，0-9这10个只有一位数字，共10个，
* 1001 - 10 = 991，10-99有两位数字，共90个，位数为180，991 - 180
* = 811，然后100-999有三位数字，个数为900个位数2700，811 < 2700,所以
* 第811位是某个三位数中的一位，由于811 = 270*3 + 1，所有第811位是从100
* 位开始的第270个数字即370的中间一位，也就是7.
*******************************************************************/
#include<math.h>

using namespace std;

class Solution {
public:
	int countOfIntegers(int digits);
	int beginNumber(int digits);
	int digitAtIndex(int index, int digits);
	int digitAtIndex(int index) {
		if (index < 0)
			return -1;

		int digits = 1;
		while (true) {
			int numbers = countOfIntegers(digits);
			if (index < numbers * digits)
				return digitAtIndex(index, digits);

			index -= digits * numbers;
			digits++;
		}
		return -1;
	}

	int counfOfIntegers(int digits) {
		if (digits == 1)
			return 10;

		int count = (int)pow(10, digits - 1);
		return 9 * count;
	}

	int digitAtIndex(int index, int digits) {
		int number = beginNumber(digits) + index / digits;
		int indexFromRight = digits - index % digits;

		for (int i = 1; i < indexFromRight; ++i)
			number /= 10;

		return number % 10;
	}

	int beginNumber(int digits) {
		if (digits == 1)
			return 0;

		return (int)pow(10, digits - 1);
	}
};