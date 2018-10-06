/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.04
*
* 面试题27: 二叉树的镜像
* 题目：输入两颗二叉树，输出它的镜像。
*
*******************************************************************/
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	void MirrorOfBinaryTree(BinaryTreeNode* pNode) {
		if (pNode == nullptr)
			return;

		if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
			return;

		BinaryTreeNode* pTemp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = pTemp;

		if (pNode->m_pLeft)
			MirrorOfBinaryTree(pNode->m_pLeft);
		if (pNode->m_pRight)
			MirrorOfBinaryTree(pNode->m_pRight);
	}
};