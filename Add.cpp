/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.15
*
* 面试题65: 不用加减乘除做加法
*
********************************************************************/

class Solution {
public:
	int Add(int num1, int num2) {
		int sum, carry;
		do {
			sum = num1 ^ num2;
			carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);

		return num1;
	}
};