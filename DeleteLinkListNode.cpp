/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.28
*
* ������18: ɾ������ڵ�
* ��Ŀһ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ
* ���ý�㡣
*
* ������������Ҫɾ���Ľڵ�ָ�룬���Կ��Ժܷ���õ�Ҫɾ���ڵ����һ���ڵ㣬
* ���԰���һ���ڵ�����ݸ�ֵΪҪɾ���Ľڵ㣬Ȼ��ɾ����һ���ڵ㣻
* ���Ҫɾ���Ľڵ�û����һ���ڵ㣬����Ҫ��ͷ�����õ�����ڵ��
* ǰ��ڵ㣬Ȼ�����ɾ��������
* ���������ֻ��һ���ڵ㣬��ôɾ���ڵ����Ҫ�������ͷ�ڵ�����Ϊ�ա�
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
		if (!pListHead || !pToBeDeleted)
			return;

		if (pToBeDeleted->m_pNext != nullptr) {
			ListNode* pNext = pToBeDeleted->m_pNext;
			pToBeDeleted->m_nValue = pNext->m_nValue;
			pToBeDeleted->m_pNext = pNext->m_pNext;

			delete pNext;
			pNext = nullptr;
		}
		else if(*pListHead == pToBeDeleted){
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
			*pListHead = nullptr;
		}
		else {
			ListNode* pNode = *pListHead;
			while (pNode->m_pNext != pToBeDeleted)
				pNode = pNode->m_pNext;

			pNode->m_pNext = nullptr;
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
		}
	}
};