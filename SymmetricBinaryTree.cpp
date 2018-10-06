/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.05
*
* 面试题27: 对称的二叉树
* 题目：实现一个函数，用来判断一颗二叉树是不是对称的
*
* 分析: 前序遍历是先遍历左子树，实现一个先实现右子树的算法，如果
* 他们的前序遍历相同则对称
*******************************************************************/
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	bool isSymmetrical(BinaryTreeNode* pRoot) {
		return isSymmetrical(pRoot, pRoot);
	}

	bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
		if (pRoot1 == nullptr && pRoot2 == nullptr)
			return true;

		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;

		if (pRoot1->m_nValue != pRoot2->m_nValue)
			return false;

		return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && 
			isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
	}
};