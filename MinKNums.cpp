/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.16
*
* 面试题40: 最小得k个数
* 题目：输入n个整数，找出其中最小得k个数
*
* 分析，基于快排得算法，时间复杂度为0(n)，但需要修改输入得数组
* 基于堆或者红黑树得解法，时间复杂度为0(nlogk),适用于海量数据
*******************************************************************/
#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
	// 基于快排得算法
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

	// 基于堆和红黑树
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