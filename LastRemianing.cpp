/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.13
*
* 面试题62: 圆圈中最后剩下的数字
* 题目：0，1，...,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈
* 里删除第m个数字，求这个圆圈里剩下的最后一个数字
*
* 分析，利用环形链表，加一个计数器，删除链表节点
********************************************************************/
#include<list>

using namespace std;

class Solution {
public:
	int LastRemaining(unsigned int n, unsigned int m) {
		if (n < 1 || m < 1)
			return -1;

		unsigned int i = 0;
		
		list<int> numbers;
		for (i = 0; i < n; ++i)
			numbers.push_back(i);

		list<int>::iterator current = numbers.begin();

		while (numbers.size() > 1) {
			for (int i = 1; i < m; ++i) {
				current++;
				if (current == numbers.end())
					current = numbers.begin();
			}

			list<int>::iterator next = ++current;
			if (next == numbers.end())
				next == numbers.begin();

			--current;
			numbers.erase(current);
			current = next;
		}

		return *(current);
	}
};