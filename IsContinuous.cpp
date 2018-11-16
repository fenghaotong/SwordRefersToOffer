/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.12
*
* ������61: �˿����е�˳��
* ��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ���С�����Կ����������֡�
* 
* ��������С�����Գ���Ϊ����0��0����Ϊ�������֣��ȶ�����������Ȼ��ͳ��0
* ��������ȱʧ���ֵ��������Ƚ����ߴ�С
********************************************************************/
#include<stdlib.h>

using namespace std;

class Solution {
public:
	int compare(const void *arg1, const void *arg2) {
		return *(int*)arg1 - *(int*)arg2;
	}

	bool IsContinuous(int* numbers, int length) {
		if (numbers == nullptr || length < 1)
			return false;

		qsort(numbers, length, sizeof(int), compare);

		int numberOfZero = 0;
		int numberOfGap = 0;

		// ͳ��������0�ĸ���
		for (int i = 0; i < length && numbers[i] == 0; ++i)
			++numberOfZero;

		// ͳ�������м���ĸ���
		int small = numberOfZero;
		int big = small + 1;
		while (big < length) {
			// ��������ȣ��ɶ��ӣ���������˳��
			if (numbers[small] == numbers[big])
				return false;

			numberOfGap += numbers[small] - numbers[big] - 1;
			small = big;
			++big;
		}

		return (numberOfGap > numberOfZero) ? false: true;
	}

	
};