/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.27
*
* ������13: �����˵��˶���Χ
* ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
* ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
* ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
* �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
*******************************************************************/

class Solution {
public:
	int getDigitSum(int number);
	bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
	int movingCount(int threshold, int rows, int cols) {
		if (threshold < 0 || rows <= 0 || cols <= 0) {
			return 0;
		}

		bool *visited = new bool[rows * cols];
		for (int i = 0; i < rows * cols; i++)
			visited[i] = false;
		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		
		delete[] visited;
		return count;
	}

	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited) {
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited)) {
			visited[row * cols + col] = true;

			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
		}

		return count;
	}

	bool check(int threshold, int rows, int cols, int row, int col, bool* visited) {
		if (row >= 0 && col >= 0 && row < rows && col < cols
			&& getDigitSum(row) + getDigitSum(col) <= threshold
			&& !visited[row * cols + col])
			return true;
		return false;
	}

	int getDigitSum(int number) {
		int sum = 0;
		while (number > 0) {
			sum += number % 10;
			number = number / 10;
		}
		return sum;
	}
};