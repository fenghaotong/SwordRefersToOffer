/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.12
*
* ������60: n�����ӵĵ���
* ��Ŀ����n���������ڵ��ϣ��������ӳ���һ��ĵ���֮����s������n����ӡ��
* s�����п��ܵ�ֵ���ֵĸ��ʡ�
*
* ������ ���ǿ��Կ����������������洢���ӵ�����ÿһ���������ֵĴ�������
* һ��ѭ���У�ÿһ�������еĵ�n�����ֱ�ʾ���Ӻ�Ϊn���ֵĴ���������һ��ѭ
* ���У����Ǽ���һ���µ����ӣ���ʱ��Ϊn���ֵĴ�������һ���У����Ǽ���һ��
* �µ����ӣ���ʱ��Ϊn�����ӳ��ֵĴ���Ӧ�õ�����һ��ѭ�������ӵ�����Ϊn-1,
* n-2,n-3,n-4,n-5�Ĵ���֮�ͣ��������ǰ���һ������ĵ�n��������Ϊǰһ����
* ���Ӧ�ĵ�n-1��n-2��n-3��n-4��n-5 
*
********************************************************************/
#include<iostream>
#include<math.h>

using namespace std;

int g_maxValue = 6;

class Solution {
public:
	void PrintProbability(int number) {
		if (number < 1)
			return;
		int CountOfSum = g_maxValue * number + 1;
		int* pProbabilitys[2];
		pProbabilitys[0] = new int[CountOfSum];
		pProbabilitys[1] = new int[CountOfSum];

		for (int i = 0; i < CountOfSum; ++i) {
			pProbabilitys[0][i] = 0;
			pProbabilitys[1][i] = 0;
		}

		int flag = 0;
		for (int i = 1; i <= g_maxValue; ++i)
			pProbabilitys[flag][i] = 1;

		for (int k = 2; k <= number; ++k) {
			for (int i = 0; i < k; ++i)
				pProbabilitys[1 - flag][i] = 0;

			for (int i = k; i < g_maxValue * k; ++i) {
				pProbabilitys[1 - flag][i] = 0;
				for (int j = 1; j <= i && j <= g_maxValue; ++j)
					pProbabilitys[1 - flag][i] += pProbabilitys[flag][i - j];
			}

			flag = 1 - flag;
		}

		double total = pow((double)g_maxValue, number);
		for (int i = number; i <= g_maxValue * number; ++i) {
			double ratio = (double)pProbabilitys[flag][i] / total;
			cout << i << ":" << ratio;
		}

		delete[] pProbabilitys[0];
		delete[] pProbabilitys[1];
	}
};
