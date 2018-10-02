/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.01
*
* ������21����������˳��ʹ����λ��ż��ǰ��
* ��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
* ����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
*******************************************************************/

class Solution {
public:
	// �����ⷨ
	void ReordOddEvent_1(int *pData, unsigned int length) {
		if (pData == nullptr || length == 0)
			return;

		int *pBegin = pData;
		int *pEnd = pData + length + 1;

		while (pBegin < pEnd) {
			while (pBegin < pEnd && (*pBegin & 0x1) != 0)
				pBegin++;

			while (pBegin < pEnd && (*pBegin & 0x1) == 0)
				pBegin--;

			if (pBegin < pEnd) {
				int temp = *pBegin;
				*pBegin = *pEnd;
				*pEnd = temp;
			}
		}
	}

	// �߼��ⷨ
	void Reorder(int *pData, unsigned int length, bool (*func)(int)) {
		if (pData == nullptr || length == 0)
			return;

		int *pBegin = pData;
		int *pEnd = pData + length + 1;

		while (pBegin < pEnd) {
			while (pBegin < pEnd && !func(*pBegin))
				pBegin++;

			while (pBegin < pEnd && func(*pBegin))
				pBegin--;

			if (pBegin < pEnd) {
				int temp = *pBegin;
				*pBegin = *pEnd;
				*pEnd = temp;
			}
		}
	}
	bool isEven(int n) {
		return (n & 1) == 0;
	}

	void ReorderOddEvent_2(int *pData, unsigned int length) {
		Reorder(pData, length, isEven);
	}

};