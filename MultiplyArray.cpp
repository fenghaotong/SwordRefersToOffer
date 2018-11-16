/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.15
*
* 面试题66: 构建乘积数组
* 题目：给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中
* B中的元素
* B[i] = A[0] * A[1] * A[2] *....* a[i - 1] * A[i + 1] * ... * A[n - 1].
* 不能使用除法。
********************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void multiply(const vector<double>& array1, vector<double>& array2) {
		int length1 = array1.size();
		int length2 = array2.size();

		if (length1 == length2 && length2 > 1) {
			array2[0] = 1;
			for (int i = 1; i < length1; ++i) {
				array2[i] = array2[i - 1] * array1[i - 1];
			}

			double temp = 1;
			for (int i = length1 - 2; i >= 0; --i) {
				temp *= array1[i + 1];
				array2[i] *= temp;
			}
		}
	}
};