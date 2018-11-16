/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.16
*
* ������40: ��С��k����
* ��Ŀ������n���������ҳ�������С��k����
*
* ���������ڿ��ŵ��㷨��ʱ�临�Ӷ�Ϊ0(n)������Ҫ�޸����������
* ���ڶѻ��ߺ�����ýⷨ��ʱ�临�Ӷ�Ϊ0(nlogk),�����ں�������
*******************************************************************/
#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
	// ���ڿ��ŵ��㷨
	void GetLeastNumbers(int* input, int n, int* output, int k) {
		if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
			return;

		int start = 0;
		int end = n - 1;
		int index = Partition(input, n, start, end);
		while (index != k - 1) {
			if (index > k - 1) {
				end = index - 1;
				index = Partition(input, n, start, end);
			}
			else {
				end = index + 1;
				index = Partition(input, n, start, end);
			}
		}
		for (int i = 0; i < k; ++i) {
			output[i] = input[i];
		}
	}

	// ���ڶѺͺ����
	typedef multiset<int, greater<int>> intSet;
	typedef multiset<int, greater<int>>::iterator setIterator;

	void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k) {
		leastNumbers.clear();

		if (k < 1 || data.size() < k)
			return;

		vector<int>::const_iterator iter = data.begin();
		for (; iter != data.end(); ++iter) {
			if ((leastNumbers.size()) < k)
				leastNumbers.insert(*iter);
			else {
				setIterator iterGreatest = leastNumbers.begin();
				if (*iter < *(leastNumbers.begin())) {
					leastNumbers.erase(iterGreatest);
					leastNumbers.insert(*iter);
				}
			}
		}

	}
};