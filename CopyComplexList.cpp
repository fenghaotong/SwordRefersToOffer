/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.10
*
* 面试题35: 复杂链表的复制
* 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead),复制
* 复杂链表。在复杂链表中，每个节点除了有一个m_pNext指针指向下一个节点，
* 还有一个m_pSibling指针指向链表中的任意节点或者nullptr。
*
* 分析： 第一步，复制原始链表，把复制后的链表节点放在相应的原始链表节点
* 后面；第二步，设置复制出来的节点的m_pSibling，假设原始链表的上N节点的
* m_pSIbling指向节点s，那么其对应复制出来的N'也对应；第三部把这个长链表
* 拆分成两个链表；
*******************************************************************/

struct ComplexListNode {
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

class Solution {
public:
	// 第一步
	void CloneNodes(ComplexListNode* pHead) {
		ComplexListNode* pNode = pHead;
		while (pNode != nullptr) {
			ComplexListNode* pCloned = new ComplexListNode();
			pCloned->m_nValue = pNode->m_nValue;
			pCloned->m_pNext = pNode->m_pNext;
			pCloned->m_pSibling = nullptr;

			pNode->m_pNext = pCloned;
			pNode = pCloned->m_pNext;
		}
	}

	// 第二步
	void ConnectSiblingNodes(ComplexListNode* pHead) {
		ComplexListNode* pNode = pHead;
		while (pNode != nullptr) {
			ComplexListNode* pCloned = pNode->m_pNext;
			if (pNode->m_pSibling != nullptr) {
				pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
			}

			pNode = pCloned->m_pNext;
		}	
	}

	// 第三步
	ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
		ComplexListNode* pNode = pHead;
		ComplexListNode* pClonedHead = nullptr;
		ComplexListNode* pClonedNode = nullptr;

		if (pNode != nullptr) {
			pClonedHead = pClonedNode = pNode->m_pNext;
			pNode->m_pNext = pClonedNode->m_pNext;
			pNode = pNode->m_pNext;
		}

		while (pNode != nullptr) {
			pClonedNode->m_pNext = pNode->m_pNext;
			pClonedNode = pClonedNode->m_pNext;
			pNode->m_pNext = pClonedNode->m_pNext;
			pNode = pNode->m_pNext;
		}

		return pClonedHead;
	}

	ComplexListNode* Clone(ComplexListNode* pHead) {
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		ReconnectNodes(pHead);
	}
};