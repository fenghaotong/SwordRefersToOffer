/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.10
*
* ������35: ��������ĸ���
* ��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead),����
* ���������ڸ��������У�ÿ���ڵ������һ��m_pNextָ��ָ����һ���ڵ㣬
* ����һ��m_pSiblingָ��ָ�������е�����ڵ����nullptr��
*
* ������ ��һ��������ԭʼ�����Ѹ��ƺ������ڵ������Ӧ��ԭʼ����ڵ�
* ���棻�ڶ��������ø��Ƴ����Ľڵ��m_pSibling������ԭʼ�������N�ڵ��
* m_pSIblingָ��ڵ�s����ô���Ӧ���Ƴ�����N'Ҳ��Ӧ�������������������
* ��ֳ���������
*******************************************************************/

struct ComplexListNode {
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

class Solution {
public:
	// ��һ��
	void CloneNodes(ComplexListNode* pHead) {
		ComplexListNode* pNode = pHead;
		while (pNode != nullptr) {
			ComplexListNode* pCloned = new ComplexListNode();
			pCloned->m_nValue = pNode->m_nValue;
			pCloned->m_pNext = pNode->m_pNext;
			pCloned->m_pSibling = nullptr;

			pNode->m_pNext = pCloned;
			pNode = pCloned->m_pNext;
		}
	}

	// �ڶ���
	void ConnectSiblingNodes(ComplexListNode* pHead) {
		ComplexListNode* pNode = pHead;
		while (pNode != nullptr) {
			ComplexListNode* pCloned = pNode->m_pNext;
			if (pNode->m_pSibling != nullptr) {
				pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
			}

			pNode = pCloned->m_pNext;
		}	
	}

	// ������
	ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
		ComplexListNode* pNode = pHead;
		ComplexListNode* pClonedHead = nullptr;
		ComplexListNode* pClonedNode = nullptr;

		if (pNode != nullptr) {
			pClonedHead = pClonedNode = pNode->m_pNext;
			pNode->m_pNext = pClonedNode->m_pNext;
			pNode = pNode->m_pNext;
		}

		while (pNode != nullptr) {
			pClonedNode->m_pNext = pNode->m_pNext;
			pClonedNode = pClonedNode->m_pNext;
			pNode->m_pNext = pClonedNode->m_pNext;
			pNode = pNode->m_pNext;
		}

		return pClonedHead;
	}

	ComplexListNode* Clone(ComplexListNode* pHead) {
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		ReconnectNodes(pHead);
	}
};