#include "Solution4.h"  //懒得分文件了，就这样罢
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        int n = grid[0].size();
        int m = grid.size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0) { //非边缘
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