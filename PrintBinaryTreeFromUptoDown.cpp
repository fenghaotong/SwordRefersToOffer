/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.06
*
* ������32: ���ϵ��´�ӡ������
* ��Ŀһ�������д�ӡ(PrintFromTopToBottom)
* ��Ŀ�������д��ϵ��´�ӡ������(print)
* ��Ŀ��: ֮���δ�ӡ������(����ջ���ֱ�洢��ż��ڵ�)
*
* ������ �������
*******************************************************************/
#include<queue>
#include<iostream>
#include<stack>

struct BinaryTreeNode {
	int m_mValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	// �����д�ӡ
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
	// ���д�ӡ
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

	// ֮���δ�ӡ������
	void PrintOfZigzag(BinaryTreeNode* pRoot) {
		if (pRoot == nullptr)
			return;

		std::stack<BinaryTreeNode *>levels[2];
		int current = 0;
		int next = 1;

		levels[current].push(pRoot);
		while (!levels[0].empty() || !levels[1].empty()) {
			BinaryTreeNode* pNode = levels[current].top();
			levels[current].pop();

			if (current == 0) {
				if (pNode->m_pLeft != nullptr)
					levels[next].push(pNode->m_pLeft);
				if (pNode->m_pRight != nullptr)
					levels[next].push(pNode->m_pRight);
			}
			else {
				if (pNode->m_pRight != nullptr)
					levels[next].push(pNode->m_pRight);
				if (pNode->m_pLeft != nullptr)
					levels[next].push(pNode->m_pLeft);
			}

			if (levels[current].empty()) {
				std::cout << std::endl;
				current = 1 - current;
				next = 1 - next;
			}
		}
	}
};