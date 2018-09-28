/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.27
*
* 面试题16: 数值的整数次方
* 题目：实现函数double Power(double base, int exponent)，求base的exponent
* 次方。不得使用库函数，同时不需要考虑大数问题。
*******************************************************************/

class Solution {
public:
	double PowerWithUnsignedExponent(double base, int absExponent);
	double Power(double base, int exponent) {
		g_InvalidInput = false;
		if (equal(base, 0.0) && exponent < 0) {
			g_InvalidInput = true;
			return 0.0;
		}

		unsigned int absExponent = (unsigned int)(exponent);
		if (exponent < 0)
			absExponent = (unsigned int)(-exponent);

		double result = PowerWithUnsignedExponent(base, absExponent);
		if (exponent < 0)
			result = 1.0 / result;
	}

	double PowerWithUnsignedExponent(double base, unsigned int exponent) {
		if (exponent == 0)
			return 1;
		if (exponent == 1)
			return base;

		double result = PowerWithUnsignedExponent(base, exponent >> 1);
		result *= result;

		if (exponent & 0x1 == 1)
			result *= base;

		return result;
	}
private:
	int g_InvalidInput = false;
};