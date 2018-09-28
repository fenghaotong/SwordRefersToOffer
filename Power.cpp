/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.27
*
* ������16: ��ֵ�������η�
* ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
* �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
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