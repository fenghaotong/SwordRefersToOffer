/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.03
*
* 面试题25: 合并两个排序的链表
* 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然
* 是递增排序的。
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