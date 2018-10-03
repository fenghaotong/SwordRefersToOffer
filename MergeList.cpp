/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.03
*
* ������25: �ϲ��������������
* ��Ŀ������������������������ϲ�����������ʹ�������еĽڵ���Ȼ
* �ǵ�������ġ�
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	ListNode* MergeList(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr)
			return pHead2;
		else if (pHead2 == nullptr)
			return pHead1;

		ListNode* pMergeHead = nullptr;
		if (pHead1->m_nValue < pHead2->m_nValue) {
			pMergeHead = pHead1;
			pMergeHead->m_pNext = MergeList(pHead1->m_pNext, pHead2);
		}
		else {
			pMergeHead = pHead2;
			pMergeHead->m_pNext = MergeList(pHead1, pHead2->m_pNext);
		}

		return pMergeHead;
	}
};