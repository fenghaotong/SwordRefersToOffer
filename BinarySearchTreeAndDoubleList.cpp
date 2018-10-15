/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.10
*
* ������36: ��������˫������
* ��Ŀ������һ�ö��������������ö���������ת����һ�������˫������Ҫ��
* ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
* 
*******************************************************************/

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	void CovertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);
	BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
		BinaryTreeNode *pLastNodeInList = nullptr;
		CovertNode(pRootOfTree, &pLastNodeInList);

		BinaryTreeNode* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
			pHeadOfList = pHeadOfList->m_pLeft;

		return pHeadOfList;
	}

	void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
		if (pNode == nullptr)
			return;

		BinaryTreeNode *pCurrent = pNode;

		if (pCurrent->m_pLeft != nullptr)
			CovertNode(pCurrent->m_pLeft, pLastNodeInList);

		pCurrent->m_pLeft = *pLastNodeInList;
		if (*pLastNodeInList != nullptr)
			(*pLastNodeInList)->m_pRight = pCurrent;

		*pLastNodeInList = pCurrent;

		if (pCurrent->m_pRight != nullptr)
			CovertNode(pCurrent->m_pRight, pLastNodeInList);
	}
};