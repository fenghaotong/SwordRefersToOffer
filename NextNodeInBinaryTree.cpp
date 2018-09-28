/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.20
*
* ������8���������µ�һ���ڵ�
* ��Ŀ������һ�Ŷ�����������һ���ڵ㣬����ҳ�����������е���һ���ڵ㡣
*******************************************************************/

#include<iostream>
#include<exception>
#include "include/BinaryTree.h"

using namespace std;

BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr){
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;

		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr){
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != nullptr && pCurrent == pParent->m_pRight){
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}

// ====================================���Գ���===================================
void Test(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* ecpected) {
	if (testName != nullptr)
		cout << testName << " begin:" << endl;

	
	BinaryTreeNode* pNext = GetNext(pNode);
	if (ecpected == pNext)
		cout << "passed!" << endl;
	else
		cout << "failed!" << endl;
}

//��ͨ������
//			8
//		6		10
//	5	7		9	11
void test1() {
	char testName[] = "test1 ";
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	
	Test(testName, pNode8, pNode9);

	DestroyTree(pNode8);
}

//���������
void test2() {
	char testName[] = "test2 ";
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);

	Test(testName, pNode5, nullptr);

	DestroyTree(pNode5);
}

// �����������
void test3() {
	char testName[] = "test3 ";
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	Test(testName, pNode5, nullptr);

	DestroyTree(pNode5);
}

int main() {
	test1();
	test2();
	test3();
	

	system("pause");
	return 0;
}