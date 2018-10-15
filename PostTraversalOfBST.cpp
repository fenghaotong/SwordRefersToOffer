/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.08
*
* ������33: �����������ĺ�������
* ��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
*
* ������ ���ڶ����������ĺ������������һ���ڵ��Ǹ��ֽ�㣬ǰ���һ��
* ���ֱ���С�����漸�����ֱ�����Ȼ��ǰ��һ��ͺ���һ��Ҳ��ͬ�������õݹ顣
*******************************************************************/

class Solution {
public:
	bool PostTraversalOfBST(int sequence[], int length) {
		if (sequence == nullptr || length <= 0)
			return false;

		int root = sequence[length - 1];

		int i = 0;
		for (; i < length; i++) {
			if (sequence[i] > root)
				break;
		}

		int j = i;
		for (; j < length; j++) {
			if (sequence[j] < root)
				return false;
		}

		bool left = true;
		if (i > 0)
			left = PostTraversalOfBST(sequence, i);

		bool right = true;
		if (i < length - 1)
			right = PostTraversalOfBST(sequence + i, length - i - 1);

		return (left&&right);
	}
};