/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.28
*
* 面试题18: 删除链表节点
* 题目二：删除链表中重复的节点，在一个排序的链表中如何删除重复的节点。
*
* 分析：从头遍历整个链表，如果当前节点的与下一个节点的值相同，那么他
* 们就是重复的节点，都可以被删除。
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