/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.04
*
* 面试题26: 树的子结构
* 题目：输入两颗二叉树A和B，判断B是不是A的子结构。
* 
* 分析：先找到树A中与树B的根节点一样的，然后判断他们的左右孩子是否一样
*******************************************************************/

struct BinaryTreeNode{
	double m_dbValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	bool Equal(double num1, double num2);
	bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
	bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
		bool result = false;
		if (pRoot1 != nullptr && pRoot2 != nullptr) {
			if (Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
				result = DoesTree1HaveTree2(pRoot1, pRoot2);
			if (!result)
				result = HasSubtree(pRoot1->m_pLeft, pRoot2);
			if (!result)
				result = HasSubtree(pRoot1->m_pRight, pRoot2);
		}
		return result;
	}

	bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
		if (pRoot2 == nullptr)
			return true;

		if (pRoot1 == nullptr)
			return false;

		if (!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
			return false;

		return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
	}

	bool Equal(double num1, double num2) {
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
			return true;
		else
			return false;
	}
};