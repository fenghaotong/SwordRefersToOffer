/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.01
*
* 面试题23：链表中的环的入口节点
* 一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
* 环的入口结点是结点3。
*
* 分析： 先使用两个指针，一快一满，快指针一次走两步，慢指针一次走一步
* 如果快的指针追上慢指针则有环，然后从这个节点处慢指针，继续向前走，
* 再回到这个节点时，记录走的步数，则为环中节点个数。
* 然后再用两个指针一个指针先走n步(n为环中节点个数)，另一个指针开始走，
* 两个指针相遇时即为环的入口
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	// 判断是否有环
	ListNode* MeetingNode(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;

		ListNode* pSlow = pHead->m_pNext;
		if (pSlow == nullptr)
			return nullptr;

		ListNode* pFast = pSlow->m_pNext;
		if (pFast != nullptr && pSlow != nullptr) {
			if (pFast == pSlow)
				return pFast;

			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
			if (pFast != nullptr)
				pFast = pFast->m_pNext;
		}

		return nullptr;
	}

	ListNode* EntryNodeOfLoop(ListNode* pHead) {
		ListNode*  meetingNode = MeetingNode(pHead);
		if (meetingNode == nullptr)
			return nullptr;

		// 环中节点个数
		int nodesLoop = 1;
		ListNode* pNode1 = meetingNode;
		while (pNode1->m_pNext != meetingNode) {
			pNode1 = pNode1->m_pNext;
			++nodesLoop;
		}

		pNode1 = pHead;
		for (int i = 0; i < nodesLoop; i++)
			pNode1 = pNode1->m_pNext;

		ListNode* pNode2 = pHead;
		while (pNode1 != pNode2) {
			pNode1 = pNode1->m_pNext;
			pNode2 = pNode2->m_pNext;
		}

		return pNode1;
	}
};