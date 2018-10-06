/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.06
*
* ������32: ���ϵ��´�ӡ������
* ��Ŀһ�������д�ӡ(PrintFromTopToBottom)
* ��Ŀ�������д��ϵ��´�ӡ������(print)
*
* ������ �������
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
};