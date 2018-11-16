/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.25
*
* 面试题47: 礼物的最大值
* 题目: 在一个m*n的棋盘的每一个都放一个礼物，每个礼物都有一定的价值
* 。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或者向下移动一个
* 直到到达棋盘的右下角，给定一个棋盘及其上面的礼物，计算能拿到的礼物的
* 最大值。
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