#include "Solution.h"

int Solution::dfs_JZ13(int n,int m,int rows, int cols, vector<vector<int>>& visited1) {
	if (n > rows || m > cols|| visited1[n][m]== 0 || visited1[n][m] == 2) {
		return 0;
	}
	else {
		cout << n << " " << m << endl;
		visited1[n][m] = 2;
		return 1 + dfs_JZ13(n + 1, m, rows, cols, visited1) + dfs_JZ13(n, m + 1, rows, cols,visited1); //1��[0,0]
	}
}


int Solution::movingCount(int threshold, int rows, int cols) {
	/*������һ�� rows �к� cols �еķ���
		�����[0, 0] ��[rows - 1, cols - 1] ��
		һ�������˴�����[0, 0] �ĸ��ӿ�ʼ�ƶ���
		ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
		���ǲ��ܽ�������������������λ֮�ʹ��� threshold �ĸ��ӡ� 
		���磬�� threshold Ϊ 18 ʱ���������ܹ����뷽��[35, 37] ��
		��Ϊ 3 + 5 + 3 + 7 = 18�����ǣ������ܽ��뷽��[35, 38] ��
		��Ϊ 3 + 5 + 3 + 8 = 19 �����ʸû������ܹ��ﵽ���ٸ����ӣ�*/
	vector<vector<int>> visited2 (100, vector<int>(100)); //��ʼ��һ����ά�������ڱ�ǿ�ȥ�ĸ��ӣ�
	/********************************�����άvector��ʼ����tm���********************************************************************/
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			int sum = i / 10 + i % 10 + j / 10 + j % 10;
			if (sum <= threshold) {
				visited2[i][j] = 1; //��ǿ�ȥ�ĸ��ӣ�ֻ�Ǳ�ǣ��ܲ���ȥ��Ҫ������������
			}
		}
	
	int num = dfs_JZ13(0, 0,rows,cols, visited2);
	
	return num;
}