/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.08
*
* 面试题54: 二叉搜索树的第k大节点
* 题目: 给定一棵二叉搜索树，找出其中第k大的节点
*
* 分析: 二叉树中序遍历
********************************************************************/
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


class Solution {
public:
	BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int& k);
	BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k) {
		if (pRoot == nullptr || k == 0)
			return nullptr;

		return KthNodeCore(pRoot, k);
	}

	BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int& k) {
		BinaryTreeNode* target = nullptr;

		if (pRoot->m_pLeft != nullptr)
			target = KthNodeCore(pRoot->m_pLeft, k);

		if (target == nullptr) {
			if (k == 1)
				target = pRoot;

			k--;
		}

		if (target == nullptr && pRoot->m_pRight != nullptr)
			target = KthNodeCore(pRoot->m_pRight, k);

		return target;
	}
};