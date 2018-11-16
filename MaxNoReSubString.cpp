/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.26
*
* 面试题48: 最长不含重复字符的子字符串
* 题目: 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该字符串
* 的长度。
*
*******************************************************************/

#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
	int longestSubstringWithoutDuplication(const std::string& str) {
		int curLength = 0;
		int maxLength = 0;
		int* position = new int[26];
		for (int i = 0; i < 26; ++i)
			position[i] = -1;
		for (int i = 0; i < str.length(); ++i) {
			int prevIndex = position[str[i] - 'a'];
			if (prevIndex < 0 || i - prevIndex > curLength)
				++curLength;
			else{
				if (curLength > maxLength)
					maxLength = curLength;

				curLength = i - prevIndex;
			}
			position[str[i] - 'a'] = i;

		}
		if (curLength > maxLength)
			maxLength = curLength;

		delete[] position;
		return maxLength;
	}
};