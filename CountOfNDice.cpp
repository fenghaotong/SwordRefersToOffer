/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.12
*
* 面试题60: n个骰子的点数
* 题目：把n个骰子仍在地上，所有骰子朝上一面的点数之和是s。输入n，打印出
* s的所有可能的值出现的概率。
*
* 分析： 我们可以考虑用两个数组来存储骰子点数的每一个综述出现的次数。在
* 一次循环中，每一个数组中的第n个数字表示骰子和为n出现的次数。在下一轮循
* 环中，我们加上一个新的骰子，此时和为n出现的次数。下一轮中，我们加上一个
* 新的骰子，此时和为n的骰子出现的次数应该等于上一次循环中骰子点数和为n-1,
* n-2,n-3,n-4,n-5的次数之和，所以我们把另一个数组的第n个数字设为前一个数
* 组对应的第n-1，n-2，n-3，n-4，n-5 
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
