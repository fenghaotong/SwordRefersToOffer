/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.29
*
* 面试题29: 顺时针打印矩阵
* 题目：输入一个矩阵，按照从外到里以顺时针的顺序依次打印出每一个数字。
*******************************************************************/

class Solution {
public:
	void PrintMatrixInCircle(int **numbers, int columns, int rows, int start);
	void printNumber(int number);
	void make2dArray(int ** &x, int numberOfRows, int numberOfColumns) {
		x = new int  *[numberOfRows];

		for (int i = 0; i < numberOfRows; i++)
			x[i] = new int[numberOfColumns];
	}

	// 方法1
	void PrintMatrixClockwisely_1(int **numbers, int columns, int rows) {
		if (numbers == nullptr || columns <= 0 || rows <= 0)
			return;

		int start = 0;

		while (columns > start * 2 && rows > start * 2) {
			PrintMatrixInCircle(numbers, columns, rows, start);
			++start;
		}
	}

	void PrintMatrixInCircle(int **numbers, int columns, int rows, int start) {
		int endX = columns - 1 - start;
		int endY = rows - 1 - start;

		// 从左到右
		for (int i = start; i <= endX; i++) {
			int number = numbers[start][i];
			printNumber(number);
		}

		// 从上到下
		if (start < endY) {
			for (int i = start + 1; i <= endY; i++) {
				int number = numbers[i][endY];
				printNumber(number);
			}
		}

		// 从右到左
		if (start < endX && start < endY) {
			for (int i = endX - 1; i >= start; i--) {
				int number = numbers[endY][i];
				printNumber(number);
			}
		}
		
		// 从下到上
		if (start < endX && start < endY - 1) {
			for (int i = endY - 1; i >= start + 1; i--) {
				int number = numbers[i][start + 1];
				printNumber(number);
			}
		}
	}

	// 方法2
	void PrintMatrixClockwisely_2(int **numbers, int columns, int rows) {
		int **dir = nullptr;
		int num = 0;

		make2dArray(dir, 4, 2);
		dir[0][0] = 0; dir[0][1] = 1;
		dir[1][0] = 1; dir[1][1] = 0;
		dir[2][0] = 0; dir[2][1] = -1;
		dir[3][0] = -1; dir[3][1] = 0;

		bool flag = true;
		int i = 1, j = 0, count = 0;
		while (flag) {
			for (int h = 0; h < 4; h++) {
				i += dir[h][0];
				j += dir[h][1];
				if (numbers[i][j] == 0)
					flag = false;
				while (numbers[i][j] != 0) {
					count++;
					flag = true;
					if (count == num) {
						printNumber(numbers[i][j]);
						flag = false;
						break;
					}
					printNumber(numbers[i][j]);
					numbers[i][j] = 0;
					i += dir[h][0];
					j += dir[h][1];
				}
				i -= dir[h][0];
				j -= dir[h][1];
			}
		}
		for (int i = 0; i < 4; i++)
			delete[] dir[i];
		delete[] dir;
	}
};