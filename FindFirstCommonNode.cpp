/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.02
*
* ������52: ��������ĵ�һ�������ڵ�
* ��Ŀ: �������������ҳ����ǵĵ�һ���ڵ�
*
* �������Ƚ���������Ĵ�С��������ָ��ָ�����������������ָ������
* С������֮�����ߡ�
*******************************************************************/
#include<iostream>

using namespace std;

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

class Solutions{
public: 
	unsigned int GetListLength(ListNode* pHead) {
		unsigned int nLength = 0;
		ListNode* pNode = pHead;
		while (pNode != nullptr) {
			++nLength;
			pNode = pNode->m_pNext;
		}

		return nLength;
	}

	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		unsigned int nLength1 = GetListLength(pHead1);
		unsigned int nLength2 = GetListLength(pHead2);
		int nLengthDif = nLength1 - nLength2;

		ListNode* pListHeadLong = pHead1;
		ListNode* pListHeadShort = pHead2;
		if (nLength2 > nLength1) {
			pListHeadShort = pHead1;
			pListHeadLong = pHead2;
			nLengthDif = nLength2 - nLength1;
		}

		for (int i = 0; i < nLengthDif; ++i)
			pListHeadLong = pListHeadLong->m_pNext;

		while (pListHeadLong != nullptr && pListHeadShort != nullptr && pListHeadLong != pListHeadShort) {
			pListHeadLong = pListHeadLong->m_pNext;
			pListHeadShort = pListHeadShort->m_pNext;
		}

		ListNode* pFirstCommonNode = pListHeadLong;

		return pFirstCommonNode;
	}
};