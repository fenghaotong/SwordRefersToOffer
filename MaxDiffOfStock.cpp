/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.13
*
* ������63: ��Ʊ���������
* ��Ŀ����Ʊ�۸�ʱ��˳��浽һ�������У���[9,11,8,5,7,12,16,14]��Ϊ�����ù�
* Ʊһ�ο��ܻ�õ���������Ƕ��١�
*
********************************************************************/
class Solution {
public:
	int MaxDiff(const int* numbers, unsigned length) {
		if (numbers == nullptr && length < 2)
			return 0;

		int min = numbers[0];
		int maxDiff = numbers[1] - min;

		for (int i = 2; i < length; ++i) {
			if (numbers[i - 1] < min)
				min = numbers[i - 1];

			int currentDiff = numbers[i] - min;
			if (currentDiff > maxDiff)
				maxDiff = currentDiff;
		}

		return maxDiff;
	}
};