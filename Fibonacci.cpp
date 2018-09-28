/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.21
*
* 面试题10：斐波那契数列
* 题目一：求斐波那契数列的第n项
*******************************************************************/

#include<iostream>
#include<ctime>

using namespace std;

// 递归
long long Fibonacci_Recursive(unsigned int n) {
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci_Recursive(n - 1) + Fibonacci(n - 2);
}

// 非递归
long long Fibonacci(unsigned int n) {
	int result[2] = { 0,1 };
	if (n < 2)
		return result[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i < n; i++) {
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}
int main() {
	// 递归所用时间
	time_t start_t, end_t;
	time(&start_t);
	Fibonacci_Recursive(40);
	time(&end_t);
	cout << start_t << endl;
	cout << end_t << endl;
	cout << difftime(end_t, start_t) << endl;
	// 非递归所用时间
	time(&start_t);
	Fibonacci(40);
	time(&end_t);
	cout << start_t << endl;
	cout << end_t << endl;
	cout << difftime(end_t, start_t) << endl;
	system("pause");
	return 0;
}