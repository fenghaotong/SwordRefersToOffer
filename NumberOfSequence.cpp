/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.23
*
* ������44: ����������ĳһλ������
*
* �����������1001λ�����Ƕ��٣�0-9��10��ֻ��һλ���֣���10����
* 1001 - 10 = 991��10-99����λ���֣���90����λ��Ϊ180��991 - 180
* = 811��Ȼ��100-999����λ���֣�����Ϊ900��λ��2700��811 < 2700,����
* ��811λ��ĳ����λ���е�һλ������811 = 270*3 + 1�����е�811λ�Ǵ�100
* λ��ʼ�ĵ�270�����ּ�370���м�һλ��Ҳ����7.
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