/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.25
*
* 面试题45: 把数字转换成字符串
* 题目: 给定一个数字，按照以下规则翻译成字符串，0翻译成“a”，1翻译成“b”
* 一次类推，一个数字可能有多少个翻译，例如12258有5种翻译，分别是“bccfi”、
* “bwfi”、“bczi”、“mcfi”、“mzi”。
*
* 分析，如果利用递归的画会重复计算，所以我们可以从有向左翻译并计算不同翻译的
* 数目。
*******************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int GetTranslationCount(const string& number);
	int GetTranslationCount(int number) {
		if (number < 0)
			return 0;

		string numberInString = to_string(number);
		return GetTranslationCount(numberInString);
	}

	int GetTranslationCount(const string& number) {
		int length = number.length();
		int* counts = new int[length];
		int count = 0;

		for (int i = length - 1; i >= 0; --i) {
			count = 0;
			if (i < length - 1)
				count = counts[i + 1];
			else
				count = 1;

			if (i < length - 1) {
				int digit1 = number[i] - '0';
				int digit2 = number[i+1] - '0';
				int converted = digit1 * 10 + digit2;

				if (converted >= 10 && converted <= 25) {
					if (i < length - 2)
						count += counts[i + 2];
					else
						count += 1;
				}
			}
			counts[i] = count;
		}

		count = counts[0];
		delete[] counts;

		return count;
	}
};