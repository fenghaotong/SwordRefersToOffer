/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.14
*
* 面试题6：从尾到头打印链表
* 题目：输入一个链表的头节点，从尾到头反过来打印每个节点的值。
*******************************************************************/

#include<iostream>
#include "include/List.h"
#include<stack>

using namespace std;

// 迭代法
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

// 递归法
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
	}
	cout << pHead->m_nValue << "\t";
}

// ====================测试代码====================
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

// 只有一个结点的链表: 1
void Test2()
{
	cout << "\nTest2 begins." << endl;

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
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
