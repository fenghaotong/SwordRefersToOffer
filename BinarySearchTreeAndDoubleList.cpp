/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.10
*
* 面试题36: 二叉树和双向链表
* 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
* 不能创建任何新的结点，只能调整树中结点指针的指向。
* 
*******************************************************************/

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	void CovertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);
	BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
		BinaryTreeNode *pLastNodeInList = nullptr;
		CovertNode(pRootOfTree, &pLastNodeInList);

		BinaryTreeNode* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
			pHeadOfList = pHeadOfList->m_pLeft;

		return pHeadOfList;
	}

	void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
		if (pNode == nullptr)
			return;

		BinaryTreeNode *pCurrent = pNode;

		if (pCurrent->m_pLeft != nullptr)
			CovertNode(pCurrent->m_pLeft, pLastNodeInList);

		pCurrent->m_pLeft = *pLastNodeInList;
		if (*pLastNodeInList != nullptr)
			(*pLastNodeInList)->m_pRight = pCurrent;

		*pLastNodeInList = pCurrent;

		if (pCurrent->m_pRight != nullptr)
			CovertNode(pCurrent->m_pRight, pLastNodeInList);
	}
};