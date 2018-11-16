/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.26
*
* ������48: ������ظ��ַ������ַ���
* ��Ŀ: ����ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�����������ַ���
* �ĳ��ȡ�
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