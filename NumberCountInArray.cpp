/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.09
*
* ������56: ���������ֳ��ֵĴ���
* ��Ŀһ��������ֻ����һ�ε���������
*
* ��Ŀһ����: 
* ������ֵĶ����Ʊ�ʾΪ��
* 2 = 0010       3 = 0011       4 = 0100
* 5 = 0101       6 = 0110
*
* ����1 ȫ�����2^4^3^6^3^2^5^5 = 4^6 = 0010
* ����2 ȷ��λ�ã�����0010���������ĵڶ�λΪ1����˿��Ը��ݵ�����2λ�Ƿ�Ϊ1���з���
* ����3 ���з��飺�ֳ�[2,3,6,3,2]��[4,5,5]����
* ����4 �������2^3^6^3^2 = 6��4^5^5 = 4����˽��Ϊ4��6��
* 
* ��Ŀ���� ������Ψһֻ����һ�ε�����
*
* ������ ����λ���㣬��һ�����ֳ������Σ���ô���Ķ����Ʊ�ʾ�е�ÿһλҲ�������Ρ���
* �����е����г������ε����ֵĶ����Ʊ�ʾ��ÿһλ�ֱ����������ÿһλ�ĺͶ��ܱ�3������
* �ٰ�������Ǹ����ֵ�ÿһλ�ֱ����ȥ���������ƶ�Ӧλ�ĺͻ��ܱ�3���������������ֶ�
* ӦλΪ0������Ϊ1�����գ��õ��������ֵĶ����Ʊ�ʾ��

********************************************************************/

class Sulotion {
public:
	// ��Ŀһ��������ֻ����һ�ε���������
	unsigned int FindFirstBitIs1(int num) {
		int indexBit = 0;
		while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
			num = num >> 1;
			++indexBit;
		}

		return indexBit;
	}

	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return (num & 1);
	}

	void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
		if (data == nullptr || length < 2)
			return;

		int  resultExclusiveOR = 0;
		for (int i = 0; i < length; ++i)
			resultExclusiveOR ^= data[i];

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		*num1 = *num2 = 0;
		for (int j = 0; j < length; ++j) {
			if (IsBit1(data[j], indexOf1))
				*num1 ^= data[j];
			else
				*num2 ^= data[j];
		}
	}

	// ��Ŀ���� ������Ψһֻ����һ�ε�����
	int FindNumberAppearingOnce(int numbers[], int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int bitSum[32] = { 0 };
		for (int i = 0; i < length; ++i) {
			int bitMask = 1;
			for (int j = 31; j >= 0; --j) {
				int bit = numbers[i] & bitMask;
				if (bit != 0) {
					bitSum[j] += 1;
					bitMask = bitMask << 1;
				}
			}

			int result = 0;
			for (int i = 0; i < 32; ++i) {
				result = result << 1;
				result += bitSum[i] % 3;
			}

			return result;
		}
	}

};