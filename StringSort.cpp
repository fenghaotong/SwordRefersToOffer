/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.15
*
* ������38: �ַ���������
* ��Ŀ������һ���ַ�������ӡ���ַ������ַ����������У����磬 �����ַ���
* abc�����ӡ�����ַ�a��b��c�������г����������ַ�����
*
* ���������ַ����ֳ��������֣�һ�������ַ����ĵ�һ���ַ�����һ������
* ��һ���ַ��������У�Ȼ���õ�һ���ַ�����������ַ����������
*******************************************************************/
#include<iostream>
class Solution {
public:
	void Permutation(char* pStr) {
		if (pStr = nullptr)
			return;

		Permutation(pStr, pStr);
	}

	void Permutation(char* pStr, char* pBegin) {
		if (*pBegin == '\0') {
			std::cout << pStr << std::endl;
		}
		else {
			for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
				char temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;

				Permutation(pStr, pBegin + 1);

				temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;
			}
		}
	}
};