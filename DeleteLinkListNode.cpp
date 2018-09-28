/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.28
*
* 面试题18: 删除链表节点
* 题目一：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删
* 除该结点。
*
* 分析：给出了要删除的节点指针，所以可以很方便得到要删除节点的下一个节点，
* 可以把下一个节点的内容赋值为要删除的节点，然后删除下一个节点；
* 如果要删除的节点没有下一个节点，则需要从头遍历得到这个节点的
* 前序节点，然后完成删除操作；
* 如果链表中只有一个节点，那么删除节点后需要把链表的头节点设置为空。
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
		if (!pListHead || !pToBeDeleted)
			return;

		if (pToBeDeleted->m_pNext != nullptr) {
			ListNode* pNext = pToBeDeleted->m_pNext;
			pToBeDeleted->m_nValue = pNext->m_nValue;
			pToBeDeleted->m_pNext = pNext->m_pNext;

			delete pNext;
			pNext = nullptr;
		}
		else if(*pListHead == pToBeDeleted){
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
			*pListHead = nullptr;
		}
		else {
			ListNode* pNode = *pListHead;
			while (pNode->m_pNext != pToBeDeleted)
				pNode = pNode->m_pNext;

			pNode->m_pNext = nullptr;
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
		}
	}
};