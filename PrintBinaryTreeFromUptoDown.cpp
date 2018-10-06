/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.06
*
* 面试题32: 从上到下打印二叉树
* 题目一：不分行打印(PrintFromTopToBottom)
* 题目二：分行从上到下打印二叉树(print)
*
* 分析： 层序遍历
*******************************************************************/
#include<queue>
#include<iostream>

struct BinaryTreeNode {
	int m_mValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	// 不分行打印
	void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot) {
		if (!pTreeRoot)
			return;

		std::queue<BinaryTreeNode *> dequeTreeNode;

		dequeTreeNode.push(pTreeRoot);
		while (dequeTreeNode.size()) {
			BinaryTreeNode* pNode = dequeTreeNode.front();
			dequeTreeNode.pop();
			std::cout << pNode->m_mValue;

			if (pNode->m_pLeft)
				dequeTreeNode.push(pNode->m_pLeft);

			if (pNode->m_pRight)
				dequeTreeNode.push(pNode->m_pRight);

		}
	}
	// 分行打印
	void print(BinaryTreeNode* pRoot) {
		if (pRoot = nullptr)
			return;

		std::queue<BinaryTreeNode *> nodes;
		nodes.push(pRoot);
		int nextLevel = 0;
		int toBePrinted = 1;
		while (!nodes.empty()) {
			BinaryTreeNode* pNode = nodes.front();
			std::cout << pNode->m_mValue;

			if (pNode->m_pLeft != nullptr) {
				nodes.push(pNode->m_pLeft);
				++nextLevel;
			}
			if (pNode->m_pRight != nullptr) {
				nodes.push(pNode->m_pRight);
				++nextLevel;
			}

			nodes.pop();
			--toBePrinted;
			if (toBePrinted == 0) {
				std::cout << std::endl;
				toBePrinted = nextLevel;
				nextLevel = 0;
			}
		}
	}
};