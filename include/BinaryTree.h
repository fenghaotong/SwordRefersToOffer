
/*
* htfeng
* 2018.09.20
* 二叉树的结构与接口
*/
#pragma once
struct  BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

_declspec(dllexport) BinaryTreeNode* CreateBinaryTreeNode(int value);
_declspec(dllexport) void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
_declspec(dllexport) void PrintTreeNode(const BinaryTreeNode* pNode);
_declspec(dllexport) void PrintTree(const BinaryTreeNode* pNode);
_declspec(dllexport) void DestroyTree(BinaryTreeNode* pRoot);