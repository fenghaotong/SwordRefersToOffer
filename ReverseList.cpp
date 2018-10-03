/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.03
*
* ������24: ��ת����
* ��Ŀ������һ������������һ�������ͷ�ڵ㣬��ת�����������ת����
* ���ͷ�ڵ㡣
*******************************************************************/
struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* pReversedHead = nullptr;
		ListNode* pNode = pHead;
		ListNode* pPrev = nullptr;
		while (pNode != nullptr) {
			ListNode* pNext = pNode->m_pNext;

			if (pNext == nullptr)
				pReversedHead = pNode;

			pNode->m_pNext = pPrev;

			pPrev = pNode;
			pNode = pNext;
		}

		return pReversedHead;
	}
};