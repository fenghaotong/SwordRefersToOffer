/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.10.08
*
* 面试题33: 二叉搜索树的后续遍历
* 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
*
* 分析： 对于二叉搜索树的后续遍历，最后一个节点是个分界点，前面的一组
* 数字比它小，后面几个数字比它大，然后前面一组和后面一组也是同样，利用递归。
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