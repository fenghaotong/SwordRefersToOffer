/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.11
*
* 面试题59: 队列的最大值
* 题目一：滑动窗口的最大值
* 题目二： 队列的最大值
*
********************************************************************/

#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
		vector<int> maxInWindows;
		if (num.size() >= size && size >= 1) {
			deque<int> index;

			for (unsigned int i = 0; i < size; ++i) {
				while (!index.empty() && num[i] >= num[index.back()])
					index.pop_back();

				index.push_back(i);
			}

			for (unsigned int i = size; i < num.size(); ++i) {
				maxInWindows.push_back(num[index.front()]);

				while (!index.empty() && num[i] >= num[index.back()])
					index.pop_back();

				if (!index.empty() && index.front() <= (int)(i - size))
					index.pop_front();

				index.push_back(i);
			}
			maxInWindows.push_back(num[index.front()]);
		}

		return maxInWindows;
	}
};

template<typename T>
class QueueWithMax {
public:
	QueueWithMax() :currentIndex(0) {}

	void push_bach(T number) {
		while (!maximums.empty() && number >= maximums.back().number)
			maximums.pop_back();

		InternalData internalData = { number, currentIndex };
		data.push_back(internalData);
		maximums.push_back(internalData);

		++currentIndex;
	}

	void pop_front() {
		if (maximums.empty())
			throw new exception("queue is empty");
		if (maximums.front.index == data.front().index)
			maximums.pop_front();

		data.pop_front();
	}

	T max() const {
		if(maximums.empty())
			throw new exception("queue is empty");

		return maximums.front().number;
	}

private:
	struct InternalData {
		T number;
		int index;
	};

	deque<InternalData> data;
	deque<InternalData> maximums;
	int currentIndex;
};