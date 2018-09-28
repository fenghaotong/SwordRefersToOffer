/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.27
*
* 面试题14: 剪绳子
* 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
* 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
* 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
* 时得到最大的乘积18。
*******************************************************************/
#include<math.h>

class Solution {
public:
	// 动态规划
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

	// 贪婪算法
	int maxProductAfterCutting_solution2(int length) {
		if (length < 2)
			return 0;
		if (length == 2)
			return 1;
		if (length == 3)
			return 2;

		// 尽可能的多剪去长度为3的绳子段
		int timesOf3 = length / 3;
		
		// 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段
		// 此时应该剪成长度为2的两段
		if (length - timesOf3 * 3 == 1)
			timesOf3 -= 1;

		int timesOf2 = (length - timesOf3 * 3) / 2;

		return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
	}
};