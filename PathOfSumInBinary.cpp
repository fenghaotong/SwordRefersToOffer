/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.08
*
* 面试题34: 二叉树中和为某一值的路径
* 题目：输入一颗二叉树和一个整数，打印出二叉树中节点值得和为输入整数得所有路径。
*
*******************************************************************/
#include<iostream>
#include<vector>

struct BinaryTreeNode {
	int m_mValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum);
	void FindPath(BinaryTreeNode* pRoot, int expectedSum) {
		if (pRoot == nullptr)
			return;

		std::vector<int> path;
		int currentSum = 0;
		FindPath(pRoot, expectedSum, path, currentSum);
	}

	void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum) {
		currentSum += pRoot->m_mValue;
		path.push_back(pRoot->m_mValue);

		bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
		if (currentSum == expectedSum && isLeaf) {
			std::cout << "A path is found" ;
			std::vector<int>::iterator iter = path.begin();
			for (; iter != path.end(); ++iter)
				std::cout << *iter << "\t";

			std::cout << std::endl;
		}

		if (pRoot->m_pLeft != nullptr)
			FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
		if (pRoot->m_pRight != nullptr)
			FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

		path.pop_back();
	}
};