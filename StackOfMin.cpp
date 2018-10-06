/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.06
*
* ������31: ջ��ѹ�롢��������
* ��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ���������
* ��Ϊ��ջ�ĵ���˳��
*
*******************************************************************/
#include<stack>

class Solution {
public:
	bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
		bool bPossible = false;
		if (pPush != nullptr && pPop != nullptr && nLength > 0) {
			const int* pNextPush = pPush;
			const int* pNextPop = pPop;

			std::stack<int> stackData;
			while (pNextPop - pPop < nLength) {
				while (stackData.empty() || stackData.top() != *pNextPop) {
					if (pNextPush - pPush == nLength)
						break;

					stackData.push(*pNextPush);
					pNextPop++;
				}

				if (stackData.top() != *pNextPop)
					break;

				stackData.pop();
				pNextPop++;
			}

			if (stackData.empty() && pNextPop - pPop == nLength)
				bPossible = true;
		}

		return bPossible;
	}
};
