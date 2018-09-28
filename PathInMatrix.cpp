/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.25
*
* ������12: �����е�·��
* ��Ŀ�� ���һ�������������ж�һ���������Ƿ����һ������ĳ�ַ�������
* �ַ���·����·�����ԴӾ����е�����һ����ʼ��ÿһ�������ھ���������
* �ҡ��ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·��������
* �ν������
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

//=========================================���Դ���==========================================
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

// ���ܲ���
void test1() {
	char test[] = "test1:";
	const char matrix[] = "abtgcfcsjdeh";
	const char str[] = "bfce";
	bool excepted = 1;
	Test(test, matrix, 3, 4, str, excepted);
}

// �߽����
void test2() {
	char test[] = "test2:";
	const char matrix[] = "abtgcfcsjdeh";
	const char str[] = "abfb";
	bool excepted = 0;
	Test(test, matrix, 3, 4, str, excepted);
}

//�����������
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