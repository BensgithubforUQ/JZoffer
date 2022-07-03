#include "Solution4.h"  //���÷��ļ��ˣ���������
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param grid int����vector<vector<>>
     * @return int����
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        int n = grid[0].size();
        int m = grid.size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0) { //�Ǳ�Ե
                    grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
                }
                if (i == 0 && j > 0) {
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                }
                if (j == 0 && i > 0) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
            }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        return grid[m - 1][n - 1];
    }
};