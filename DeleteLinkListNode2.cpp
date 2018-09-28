/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.28
*
* ������18: ɾ������ڵ�
* ��Ŀ����ɾ���������ظ��Ľڵ㣬��һ����������������ɾ���ظ��Ľڵ㡣
*
* ��������ͷ�����������������ǰ�ڵ������һ���ڵ��ֵ��ͬ����ô��
* �Ǿ����ظ��Ľڵ㣬�����Ա�ɾ����
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	void DeleteDuplication(ListNode** pHead) {
		if (pHead == nullptr || *pHead == nullptr)
			return;

		ListNode* preNode = nullptr;
		ListNode* pNode = *pHead;
		while (pNode != nullptr) {
			ListNode* pNext = pNode->m_pNext;
			bool needDelete = false;

			if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
				needDelete = true;

			if (!needDelete) {
				preNode = pNode;
				pNode = pNode->m_pNext;
			}
			else {
				int value = pNode->m_nValue;
				ListNode* pToBedel = pNode;
				while(pToBedel != nullptr && pToBedel->m_nValue == value) {
					pNext = pToBedel->m_pNext;
					delete pToBedel;
					pToBedel = nullptr;
					pToBedel = pNext;
				}

				if (preNode == nullptr)
					*pHead = pNext;
				else
					preNode->m_pNext = pNext;

				pNode = pNext;
			}
		}
	}
};