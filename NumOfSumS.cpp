/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.09
*
* ������57: ��Ϊs������
* ��Ŀһ����Ϊs����������
*
* ����: ��Ϊ�ǵ�����������飬ʹ��ǰ������ָ�룬��ӣ���κʹ���s�������
* ָ����ǰ�ƶ��������С��s��ǰ���ָ������ƶ���
*
* ��Ŀ���� ��Ϊs��������������
*
* ������ ʹ��small��big��ʾ���е���Сֵ�����ֵ����ʼ��Ϊsmall=1��big=2��
* ���small��big֮������к�С��s����big��1�����small��big֮������к�
* ����s����small��1��
********************************************************************/
#include<iostream>

using namespace std;


class Sulotion {
public:
	// ��Ŀһ����Ϊs����������
	bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2) {
		bool found = false;
		if (length < 1 || num1 == nullptr || num2 == nullptr)
			return found;

		int ahead = length - 1;
		int behind = 0;

		while (ahead > behind) {
			long long curSum = data[ahead] + data[behind];

			if (curSum == sum) {
				*num1 = data[behind];
				*num2 = data[ahead];
				found = true;
				break;
			}
			else if (curSum > sum)
				ahead--;
			else
				behind++;
		}

		return found;
	}

	// ��Ŀ���� ��Ϊs��������������

	void PrintCountinuousSequence(int small, int big) {
		for (int i = small; i <= big; ++i) {
			cout << i << endl;
		}
	}
	void FindContinuousSequence(int sum) {
		if (sum < 3)
			return;

		int small = 1;
		int big = 2;
		int middle = (1 + sum) / 2;
		int curSum = small + big;

		while (small < middle) {
			if (curSum == sum)
				PrintCountinuousSequence(small, big);

			while (curSum > sum && small < middle) {
				curSum -= small;
				small++;

				if (curSum == sum)
					PrintCountinuousSequence(small, big);
			}

			big++;
			curSum += big;
		}
	}

};