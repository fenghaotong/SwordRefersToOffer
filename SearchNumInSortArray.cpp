/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.07
*
* ������53: ���������������г��ֵĴ���
* ��Ŀһ: ���������������г��ֵĴ�����

* ������ʹ�ö��ֲ��ң��ҵ���һ��k�͵ڶ���k
*
* ��Ŀ��: 0~n-1��ȱʧ������
*
* ��Ŀ��: ������������±���ȵ�Ԫ��
*******************************************************************/

class Solution {
public:
	// ��Ŀһ
	// �õ���һ��k
	int GetFirstK(int* data, int length, int k, int start, int end) {
		if (start > end)
			return -1;

		int middleIndex = (start + end) / 2;
		int middleData = data[middleIndex];

		if (middleData == k) {
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
				return middleIndex;
			else
				end = middleIndex - 1;
		}
		else if (middleData > k)
			end = middleIndex - 1;
		else
			start = middleIndex + 1;

		return GetFirstK(data, length, k, start, end);
	}

	//�õ����һ��k
	int GetLastK(int* data, int length, int k, int start, int end) {
		if (start > end)
			return -1;

		int middleIndex = (start + end) / 2;
		int middleData = data[middleIndex];

		if (middleData == k) {
			if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
				return middleIndex;
			else
				start = middleIndex + 1;
		}
		else if (middleData < k)
			start = middleIndex + 1;
		else
			end = middleIndex - 1;

		return GetFirstK(data, length, k, start, end);
	}

	int GetNumberOfK(int* data, int length, int k) {
		int number = 0;
		if (data != nullptr && length > 0) {
			int first = GetFirstK(data, length, k, 0, length - 1);
			int last = GetLastK(data, length, k, 0, length - 1);

			if (first > -1 && last > -1)
				number = last - first + 1;
		}

		return number;
	}

	// ��Ŀ��
	int GetMissingNumber(const int* numbers, int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int left = 0;
		int right = length - 1;
		while (left <= right) {
			int middle = (right + left) >> 1;
			if (numbers[middle] != middle) {
				if (middle == 0 || numbers[middle - 1] == middle - 1)
					return middle;
				right = middle - 1;
			}
			else
				left = middle + 1;
		}
		if (left == length)
			return length;

		return -1;
	}

	// ��Ŀ��
	int GetNumberSameAsIndex(const int* numbers, int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int left = 0;
		int right = length - 1;
		while (left <= right) {
			int middle = left + (right - left) >> 1;
			if (numbers[middle] == middle)
				return middle;

			if (numbers[middle] > middle)
				right = middle - 1;
			else
				left = middle + 1;
		}

		return -1;
	}
};