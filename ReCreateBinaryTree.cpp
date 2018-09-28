/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.20
*
* ������7���ؽ�������
* ��Ŀ������ĳ��������ǰ����������������������ؽ��ö����������������ǰ���������������Ľ��
* �ж��������ظ������֡�
*******************************************************************/

#include<iostream>
#include<exception>
#include "include/BinaryTree.h"

using namespace std;

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = nullptr;
	root->m_pRight = nullptr;

	if (startPreorder == endPreorder) {
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invaild input.");
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	while (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invaild input");

	int leftLength = rootInorder - startInorder;
	int* leftPreorder = startPreorder + leftLength;
	if (leftLength > 0) {
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorder, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder) {
		root->m_pRight = ConstructCore(leftPreorder + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

// ====================================���Գ���===================================
void Test(char* testName, int* preorder, int * inorder, int length) {
	if (testName != nullptr)
		cout << testName << " begin:" << endl;

	cout << "The preorder sequence is:";
	for (int i = 0; i < length; i++)
		cout << preorder[i] << " ";
	cout << endl;

	cout << "The inorder sequence is:";
	for (int i = 0; i < length; i++)
		cout << inorder[i] << " ";
	cout << endl;

	//try {
	BinaryTreeNode* root = Construct(preorder, inorder, length);
	PrintTree(root);

	DestroyTree(root);
	/*}
	catch(std::exception& exception){
		cout << "Invaild Input:" << endl;
	}*/
}

//��ͨ������
void test1() {
	char testName[] = "test1 ";
	int preorder[] = { 1,2,4,7,3,5,8,6 };
	int inorder[] = { 4,7,2,1,5,3,8,6 };
	int length;
	length = sizeof(preorder)/sizeof(int);
	Test(testName, preorder, inorder, length);
}

//���������
void test2() {
	char testName[] = "test2 ";
	int preorder[] = { 1,2,4,7 };
	int inorder[] = { 4,7,2,1 };
	int length;
	length = sizeof(preorder) / sizeof(int);
	Test(testName, preorder, inorder, length);
}

// �����������
void test3() {
	char testName[] = "test3 ";
	Test(testName, nullptr, nullptr, 0);
}

int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}