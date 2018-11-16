/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.12
*
* ������58: ��ת�ַ���
* ��Ŀһ����ת����˳��
* ��Ŀ��������ת�ַ���
* �磺 ��abcdefg������������2��������������ת���Ϊ����cdefgab��
********************************************************************/
#include<string>

using namespace std;

class Solution {
public:
	// ��ת��������
	void Reverse(char* pBegin, char* pEnd) {
		if (pEnd == nullptr || pBegin == nullptr) {
			return;
		}

		while (pBegin < pEnd) {
			char temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}

		pBegin++, pEnd--;
	}

	// ����ת�ַ���
	char* LeftRotateString(char* pStr, int n) {
		if (pStr != nullptr) {
			int nLength = static_cast<int>(strlen(pStr));
			if (nLength > 0 && n > 0 && n < nLength) {
				char* pFirstStart = pStr;
				char* pFirstEnd = pStr + n - 1;
				char* pSecondStart = pStr + n;
				char* pSecondEnd = pStr + nLength - 1;

				// ��תǰn���ַ���
				Reverse(pFirstStart, pFirstEnd);
				// ��ת������ַ���
				Reverse(pSecondStart, pSecondEnd);
				// ��ת���е��ַ���
				Reverse(pFirstStart, pSecondEnd);
			}
		}
	}

};