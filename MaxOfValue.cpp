/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.25
*
* ������47: ��������ֵ
* ��Ŀ: ��һ��m*n�����̵�ÿһ������һ�����ÿ�����ﶼ��һ���ļ�ֵ
* ������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ��������������ƶ�һ��
* ֱ���������̵����½ǣ�����һ�����̼������������������õ��������
* ���ֵ��
*
*******************************************************************/
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int getMaxValue_solution(const int* values, int rows, int cols) {
		if (values == nullptr || rows <= 0 || cols <= 0)
			return 0;

		int* maxValues = new int[cols];
		for(int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j) {
				int left = 0;
				int up = 0;

				if (i > 0)
					up = maxValues[j];
				if (j > 0)
					left = maxValues[j - 1];

				maxValues[j] = std::max(left, up) + values[i * cols + j];
			}
		}
		int maxValue = maxValues[cols - 1];

		delete[] maxValues;

		return maxValue;

	}
};