/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.03
*
* 面试题24: 反转链表
* 题目：定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链
* 表的头节点。
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