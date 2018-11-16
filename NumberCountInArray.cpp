/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.09
*
* 面试题56: 数组中数字出现的次数
* 题目一：数组中只出现一次的两个数字
*
* 题目一分析: 
* 相关数字的二进制表示为：
* 2 = 0010       3 = 0011       4 = 0100
* 5 = 0101       6 = 0110
*
* 步骤1 全体异或：2^4^3^6^3^2^5^5 = 4^6 = 0010
* 步骤2 确定位置：对于0010，从右数的第二位为1，因此可以根据倒数第2位是否为1进行分组
* 步骤3 进行分组：分成[2,3,6,3,2]和[4,5,5]两组
* 步骤4 分组异或：2^3^6^3^2 = 6，4^5^5 = 4，因此结果为4，6。
* 
* 题目二： 数组中唯一只出现一次的数字
*
* 分析： 基于位运算，若一个数字出现三次，那么它的二进制表示中的每一位也出现三次。把
* 数组中的所有出现三次的数字的二进制表示的每一位分别加起来，则每一位的和都能被3整除，
* 再把所求的那个数字的每一位分别加上去，若二进制对应位的和还能被3整除，则所求数字对
* 应位为0，否则为1。最终，得到所求数字的二进制表示。

********************************************************************/

class Sulotion {
public:
	// 题目一：数组中只出现一次的两个数字
	unsigned int FindFirstBitIs1(int num) {
		int indexBit = 0;
		while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
			num = num >> 1;
			++indexBit;
		}

		return indexBit;
	}

	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return (num & 1);
	}

	void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
		if (data == nullptr || length < 2)
			return;

		int  resultExclusiveOR = 0;
		for (int i = 0; i < length; ++i)
			resultExclusiveOR ^= data[i];

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		*num1 = *num2 = 0;
		for (int j = 0; j < length; ++j) {
			if (IsBit1(data[j], indexOf1))
				*num1 ^= data[j];
			else
				*num2 ^= data[j];
		}
	}

	// 题目二： 数组中唯一只出现一次的数字
	int FindNumberAppearingOnce(int numbers[], int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int bitSum[32] = { 0 };
		for (int i = 0; i < length; ++i) {
			int bitMask = 1;
			for (int j = 31; j >= 0; --j) {
				int bit = numbers[i] & bitMask;
				if (bit != 0) {
					bitSum[j] += 1;
					bitMask = bitMask << 1;
				}
			}

			int result = 0;
			for (int i = 0; i < 32; ++i) {
				result = result << 1;
				result += bitSum[i] % 3;
			}

			return result;
		}
	}

};