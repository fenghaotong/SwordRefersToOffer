/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.27
*
* ������14: ������
* ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
* ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
* ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
* ʱ�õ����ĳ˻�18��
*******************************************************************/
#include<math.h>

class Solution {
public:
	// ��̬�滮
	int maxProductAfterCutting_solution(int length) {
		if (length < 2)
			return 0;
		if (length == 2)
			return 1;
		if (length == 3)
			return 2;

		int *products = new int[length + 1];
		products[0] = 0;
		products[1] = 1;
		products[2] = 2;
		products[3] = 3;

		int max = 0;
		for (int i = 4; i <= length; i++) {
			max = 0;
			for (int j = 1; j <= i / 2; j++) {
				int product = products[i] * products[i - j];
				if (max < product)
					max = product;

				products[i] = max;
			}
		}

		max = products[length];
		delete[] products;
		return max;
	}

	// ̰���㷨
	int maxProductAfterCutting_solution2(int length) {
		if (length < 2)
			return 0;
		if (length == 2)
			return 1;
		if (length == 3)
			return 2;

		// �����ܵĶ��ȥ����Ϊ3�����Ӷ�
		int timesOf3 = length / 3;
		
		// ���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����Ӷ�
		// ��ʱӦ�ü��ɳ���Ϊ2������
		if (length - timesOf3 * 3 == 1)
			timesOf3 -= 1;

		int timesOf2 = (length - timesOf3 * 3) / 2;

		return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
	}
};