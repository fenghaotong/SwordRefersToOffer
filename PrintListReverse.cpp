/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.14
*
* ������6����β��ͷ��ӡ����
* ��Ŀ������һ�������ͷ�ڵ㣬��β��ͷ��������ӡÿ���ڵ��ֵ��
*******************************************************************/

#include<iostream>
#include "include/List.h"
#include<stack>

using namespace std;

// ������
void PrintListReversingly_Iteratively(ListNode* pHead) {
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty()) {
		pNode = nodes.top();
		cout << pNode->m_nValue << "\t";
		nodes.pop();
	}
	cout << endl;
}

// �ݹ鷨
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
	}
	cout << pHead->m_nValue << "\t";
}

// ====================���Դ���====================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	cout << "Reversed:" << endl;
	PrintListReversingly_Iteratively(pHead);
	PrintListReversingly_Recursively(pHead);
	cout << endl;
}

// 1->2->3->4->5
void Test1()
{
	cout << "Test1 begins." << endl;

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// ֻ��һ����������: 1
void Test2()
{
	cout << "\nTest2 begins." << endl;

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// ������
void Test3()
{
	cout << "\nTest3 begins." << endl;

	Test(nullptr);
}

int main() {
	Test1();
	Test2();
	//Test3();
	system("pause");
	return 0;
}
