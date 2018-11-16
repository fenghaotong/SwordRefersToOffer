/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.08
*
* 面试题55: 二叉树的深度
* 题目一：二叉树的深度
* 题目二： 平衡二叉树
*
* 分析: 二叉树的深度使用递归，很容易实现;要判断平衡二叉树，使用递归的
* 方法遍历二叉树的每个节点然后判断是否是平衡二叉树很简单，但是会重复遍历
* 很多节点，
********************************************************************/
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	// 题目一：二叉树的深度
	int TreeDepth(BinaryTreeNode* pRoot) {
		if (pRoot == nullptr)
			return 0;

		int nLeft = TreeDepth(pRoot->m_pLeft);
		int nRight = TreeDepth(pRoot->m_pRight);

		return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
	}
	// 题目二： 平衡二叉树

	bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth) {
		if (pRoot == nullptr) {
			*pDepth = 0;
			return true;
		}

		int left, right;

		if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
			int diff = left - right;
			if (diff <= 1 && diff >= -1) {
				*pDepth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}

	bool IsBalanced(BinaryTreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
};