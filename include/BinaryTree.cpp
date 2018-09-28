/*
*  htfeng
*  2018.09.20
*  二叉树的创建、打印和删除
*/
#include<iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pParent != nullptr) {
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		if (pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if (pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}

void PrintTreeNode(const BinaryTreeNode* pNode) {
	if (pNode != nullptr) {
		cout << "value of the Node is :" << pNode->m_nValue << endl;

		if (pNode->m_pLeft != nullptr)
			cout << "value of its Left Node is:" << pNode->m_pLeft->m_nValue << endl;
		else
			cout << "The left child is nullptr." << endl;

		if (pNode->m_pRight != nullptr)
			cout << "value of its Right Node is:" << pNode->m_pRight->m_nValue << endl;
		else
			cout << "The right child is nullptr." << endl;
	}
	else
		cout << "thie node is null." << endl;

	cout << endl;
}

void PrintTree(const BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);

	if (pRoot != nullptr) {
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);
		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot) {
	if (pRoot != nullptr) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;
		delete pRoot;
		pRoot = nullptr;
		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}