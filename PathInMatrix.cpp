/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.25
*
* 面试题12: 矩阵中的路径
* 题目： 设计一个函数，用来判断一个矩阵中是否存在一条包含某字符串所有
* 字符的路径，路经可以从矩阵中的任意一个开始，每一步可以在矩阵中向左、
* 右、上、下移动一格，如果一条路径经过了矩阵的某一格，那么该路径不能再
* 次进入格子
*******************************************************************/

#include<iostream>

using namespace std;

bool hasPathCore(const char* matrix, int rows, int cols, int row, 
	int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str) {
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
				return true;
			}
		}
	}

	delete[] visited;

	return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, 
	int col, const char* str, int& pathLength, bool* visited) {
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	if (row > 0 && row < rows && col > 0 && col < cols
		&& matrix[row * cols + col] == str[pathLength]
		&& !visited[row * cols + col]) {
		
		++pathLength;
		visited[row * cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);

		if (!hasPath) {
			--pathLength;
			visited[row * cols + col] = false;
		}
	}

	return hasPath;
}

//=========================================测试代码==========================================
void Test(char* testName, const char* matrix, int rows, int cols, const char* str, bool excepted) {
	if (testName != nullptr)
		cout << testName << ":" << endl;

	bool result = hasPath(matrix, rows, cols, str);
	cout << result << " " << excepted << endl;
	if (excepted == result)
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;

}

// 功能测试
void test1() {
	char test[] = "test1:";
	const char matrix[] = "abtgcfcsjdeh";
	const char str[] = "bfce";
	bool excepted = 1;
	Test(test, matrix, 3, 4, str, excepted);
}

// 边界测试
void test2() {
	char test[] = "test2:";
	const char matrix[] = "abtgcfcsjdeh";
	const char str[] = "abfb";
	bool excepted = 0;
	Test(test, matrix, 3, 4, str, excepted);
}

//特殊输入测试
void test3() {
	char test[] = "test3:";
	bool excepted = 0;
	Test(test, nullptr, 0, 0, nullptr, excepted);
}
int main() {
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}         