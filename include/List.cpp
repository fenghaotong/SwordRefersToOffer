/*
* htfeng
* 2018.09.14
* ������ʵ��
*/

#include<iostream>
#include "List.h"

using namespace std;

// ��������ڵ�
ListNode* CreateListNode(int value) {
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	return pNode;
}

// ��������ڵ�
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	if (pCurrent == nullptr) {
		cout << "error to connect two nodes!";
		exit(1);
	}

	pCurrent->m_pNext = pNext;
}
		
// ��ӡ����ڵ�
void PrintListNode(ListNode* pNode) {
	if (pNode == nullptr)
		cout << "The node is nullptr!";
	else
		cout << pNode->m_nValue << endl;
}

// ��ӡ����
void PrintList(ListNode* pHead) {
	cout << "PrintList start!" << endl;
	ListNode *pNode = pHead;
	if (pNode == nullptr) {
		cout << "The list is null" << endl;
	}
	else {
		while (pNode != nullptr) {
			cout << pNode->m_nValue << "\t";
			pNode = pNode->m_pNext;
		}
		cout << endl;
	}
	
	cout << "PrintList end!" << endl;
}

// �����б�
void DestroyList(ListNode* pHead) {
	ListNode *pNode = pHead;
	while (pNode != nullptr) {
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

// �������ĩβ���һ���ڵ�
void AddToTail(ListNode** pHead, int value) {
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else {
		ListNode *pNode = *pHead;

		while (pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

// ɾ���б���ֵΪvalue�Ľڵ�
void RemoveNode(ListNode** pHead, int value) {
	if (*pHead == nullptr || pHead == nullptr)
		return;

	ListNode *pToDeleted = nullptr;
	if ((*pHead)->m_nValue == value) {
		pToDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value) {
			pToDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToDeleted != nullptr) {
		delete pToDeleted;
		pToDeleted = nullptr;
	}
}