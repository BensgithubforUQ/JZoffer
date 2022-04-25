#include "Solution.h"

int Solution::dfs_JZ13(int n,int m,int rows, int cols, vector<vector<int>>& visited1) {
	if (n > rows || m > cols|| visited1[n][m]== 0 || visited1[n][m] == 2) {
		return 0;
	}
	else {
		cout << n << " " << m << endl;
		visited1[n][m] = 2;
		return 1 + dfs_JZ13(n + 1, m, rows, cols, visited1) + dfs_JZ13(n, m + 1, rows, cols,visited1); //1是[0,0]
	}
}


int Solution::movingCount(int threshold, int rows, int cols) {
	/*地上有一个 rows 行和 cols 列的方格。
		坐标从[0, 0] 到[rows - 1, cols - 1] 。
		一个机器人从坐标[0, 0] 的格子开始移动，
		每一次只能向左，右，上，下四个方向移动一格，
		但是不能进入行坐标和列坐标的数位之和大于 threshold 的格子。 
		例如，当 threshold 为 18 时，机器人能够进入方格[35, 37] ，
		因为 3 + 5 + 3 + 7 = 18。但是，它不能进入方格[35, 38] ，
		因为 3 + 5 + 3 + 8 = 19 。请问该机器人能够达到多少个格子？*/
	vector<vector<int>> visited2 (100, vector<int>(100)); //初始化一个二维数组用于标记可去的格子，
	/********************************这个二维vector初始化有tm天坑********************************************************************/
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			int sum = i / 10 + i % 10 + j / 10 + j % 10;
			if (sum <= threshold) {
				visited2[i][j] = 1; //标记可去的格子，只是标记，能不能去还要看相连不相连
			}
		}
	
	int num = dfs_JZ13(0, 0,rows,cols, visited2);
	
	return num;
}