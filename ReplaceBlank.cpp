/*******************************************************************
Copyright(c) 2018, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷C++����
//
// ������5���ַ����滻�ո�
// ��Ŀ��ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20�����ո��ASCIIΪ32,ʮ�����Ƶ�0x20��
//==================================================================

#include<iostream>

using namespace std;

// ���ܺ���
void ReplaceBlank(char string[], int length) {
	if (string == nullptr || length < 0)
		return;

	// ����һ�εõ��ַ������ȺͿո����
	int orignalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0') {
		++orignalLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}

	// �ѿո��滻�ɡ�%20�����ַ�������ΪnewLength
	int newLength = orignalLength + numberOfBlank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = orignalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (string[indexOfOriginal] == ' ') {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else {
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

//================================���Դ���==================================
void Test(char *testName, char string[], int length, char except[]) {
	if (testName != nullptr)
		cout << testName << ":";

	ReplaceBlank(string, length);

	if (except == nullptr && string == nullptr)
		cout << "passed." << endl;
	else if (except == nullptr && string != nullptr)
		cout << "failed." << endl;
	else if(strcmp(string, except) == 0)
		cout << "passed." << endl;
	else
		cout << "failed." << endl;
}

// ������ַ����а����ո�
void test1() {
	const int length = 100;
	char str[length] = "hello world";
	char test[] = "test1";
	char except[] = "hello%20world";
	Test(test, str, length, except);

}

// ������ַ�����û�пո�
void test2() {
	const int length = 100;
	char str[length] = "helloworld";
	char test[] = "test2";
	char except[] = "helloworld";
	Test(test, str, length, except);
}

// �ַ����Ǹ�nullptrָ��
void test3() {
	const int length = 0;
	char test[] = "test3";
	Test(test, nullptr, length, nullptr);
}

// ������
int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}
