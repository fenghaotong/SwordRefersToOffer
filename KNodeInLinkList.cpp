/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.02
*
* 面试题22：链表中的倒数第k个节点
* 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
* 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
* 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
* 值为4的结点。
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k == 0)
			return nullptr;

		ListNode *pAhead = pListHead;
		ListNode *pBehind = nullptr;

		for (unsigned int i = 0; i < k - 1; ++i) {
			if (pAhead->m_pNext != nullptr)
				pAhead = pAhead->m_pNext;
			else
				return nullptr;
		}
		pBehind = pListHead;
		while (pAhead->m_pNext != nullptr) {
			pAhead = pAhead->m_pNext;
			pBehind = pBehind->m_pNext;
		}

		return pBehind;
	}
};