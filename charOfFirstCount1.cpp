/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.01
*
* ������50: ��һ��ֻ����һ�ε��ַ�
* ��Ŀ: ���ַ������ҳ���һ��ֻ����һ�ε��ַ���
*
* ������ʹ��hash��
*******************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
	char FirstNotRepeatingChar(char* pString) {
		if (pString = nullptr)
			return '\0';

		const int tableSize = 256;
		unsigned int hashTable[tableSize];

		for (unsigned int i = 0; i < tableSize; i++)
			hashTable[i] = 0;

		char* pHashKey = pString;

		while (*(pHashKey) != '\0') {
			hashTable[*(pHashKey++)]++;
		}

		pHashKey = pString;

		while (*pHashKey != '\0') {
			if (hashTable[*pHashKey] == 1)
				return *pHashKey;

			pHashKey++;
		}

		return '\0';
	}
};

