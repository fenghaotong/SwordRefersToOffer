/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.01
*
* ������49: ����
* ��Ŀ: ����ֻ�Ѱ�������2��3��5������Ϊ�������󰴴�С�����˳��ĵ�1500
* ��������ϰ�������ǰ�1������һ��������
*
*******************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
	int Min(int number1, int number2, int number3);
	int GetUglyNumber_Solution2(int index) {
		if (index <= 0)
			return 0;

		int *pUglyNumbers = new int[index];
		pUglyNumbers[0] = 1;
		int nextUglyIndex = 1;

		int *pMutiply2 = pUglyNumbers;
		int *pMutiply3 = pUglyNumbers;
		int *pMutiply5 = pUglyNumbers;

		while (nextUglyIndex < index) {
			int min = Min(*pMutiply2 * 2, *pMutiply3 * 3, *pMutiply5 * 5);
			pUglyNumbers[nextUglyIndex] = min;

			while (*pMutiply2 * 2 <= pUglyNumbers[nextUglyIndex])
				++pMutiply2;
			while (*pMutiply3 * 3 <= pUglyNumbers[nextUglyIndex])
				++pMutiply3;
			while (*pMutiply5 * 5 <= pUglyNumbers[nextUglyIndex])
				++pMutiply5;

			++nextUglyIndex;
		}

		int ugly = pUglyNumbers[nextUglyIndex - 1];
		delete[] pUglyNumbers;
		return ugly;
	}

	int Min(int number1, int number2, int number3) {
		int min = (number1 < number2) ? number1 : number2;
		min = (min < number3) ? min : number3;

		return min;
	}
};