/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.24
*
* ������45: �������ų���С����
* ��Ŀ: ����һ�����������飬 �������������ƴ�������ų�һ��������ӡ��
* ƴ�ӳ���������������С��һ����
*
* ������������������m��n�����������ϲ�Ϊmn����nm�����mn < nm����ô��ӡ��
* mn������m��nǰ�棬��ʱ����mС��n���෴���mn > nm,����nС��m�����mn==nm
* ����m����n����Ϊm��nƴ�ӵ�������int�Ϳ������������Ҫ������ת�����ַ�����
*******************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class Solution {
public:
	int compare(const void* strNumber1, const void* strNumber2);

	void PrintMinNumber(int* numbers, int length) {
		if (numbers == nullptr || length <= 0) {
			return;
		}

		char** strNumbers = (char**)(new int[length]);
		for (int i = 0; i < length; ++i) {
			strNumbers[i] = new char[g_MaxNumberLength + 1];
			sprintf(strNumbers[i], "%d", numbers[i]);
		}

		qsort(strNumbers, length, sizeof(char*), compare);

		for (int i = 0; i < length; ++i)
			cout << strNumbers[i];
		cout << endl;

		for (int i = 0; i < length; ++i)
			delete[] strNumbers[i];
		delete[] strNumbers;
	}

	int compare(const void* strNumber1, const void* strNumber2) {
		strcpy(g_StrCombine1, *(const char**)strNumber1);
		strcat(g_StrCombine1, *(const char**)strNumber2);

		strcpy(g_StrCombine2, *(const char**)strNumber2);
		strcat(g_StrCombine2, *(const char**)strNumber1);

		return strcmp(g_StrCombine1, g_StrCombine2);
	}
private:
	const int g_MaxNumberLength = 10;

	char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
	char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];
};