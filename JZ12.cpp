#include "Solution.h"



void Solution::findString_dfs(int n, int m, vector<vector<char>> &matrix, string& word, int pos) {
	if (flag) return;
	if (n >= 0 && m >= 0 && m < size2 && n < size1 && visited[n][m] == 0 && word[pos] == matrix[n][m]) {
		if (pos == size3 - 1) {
			flag = 1;
			return;
		}
		visited[n][m] = 1; //flag��֦
		findString_dfs(n - 1, m, matrix, word, pos+1);
		findString_dfs(n + 1, m, matrix, word, pos+1); //�ݹ�
		findString_dfs(n, m - 1, matrix, word, pos+1);
		findString_dfs(n, m + 1, matrix, word, pos+1);
		visited[n][m] = 0; //flag����
	}
	
}


bool Solution::hasPath(vector<vector<char> >& matrix, string word) {
	size1 = matrix.size();
	size2 = matrix[0].size();
	size3 = word.size();

	visited = vector<vector<int>>(size1, vector<int>(size2, 0));
	for (int n = 0; n < size1; n++) {
		//��һ����ʱ���������
		for (int m = 0; m < size2; m++) {
			//��һ��queue�������������
			if (matrix[n][m] == word[0]) {
				findString_dfs(n, m, matrix, word, 0);
				if (flag) return true;
			}
		}
	}
	return false;
}