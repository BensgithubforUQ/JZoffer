#include <iostream>
#include <vector>
#include <set>
using namespace std;


//递归问题主要就像两件事，第一件事，是递归结束条件，第二件事就是递归规则（即如何递归）


//涂色块问题，本题问一共有几个海岛
void island(vector<vector<char>>& g, int row, int column) { //
    if (row < 0 || column < 0 || row >= g.size() ||
        column >= g[0].size()) return;
    if (g[row][column] == '0') return; //遇到海就结束递归
    g[row][column] = '0'; //当不是海的时候，就把变成海以防递归死循环
    island(g, row + 1, column); //然后向四个方面dfs把该岛全都记录成海，防止重复记录
    island(g, row, column + 1);
    island(g, row - 1, column);
    island(g, row, column - 1);
}

int solve(vector<vector<char> >& grid) {
    // write code here
    int row = grid.size();
    int column = grid[0].size();
    int count = 0;
    for (int i = 0; i < row; i++) { //循环，找岛
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == '1') {
                island(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

//排列组合问题，本质就是看有多少种交换情况
//只要数组中两数交换，就是一种新的情况，然后用新的情况进行递归，递归完成之后回溯，原数组交换的位置往后挪
void permute(set<string>& input, string& str, int n, string temp) {
    int len = str.size();
    if (n >= len) {
        input.insert(temp);
        return;
    }
    //input.insert(temp);
    for (int i = n; i < len; i++) {
        swap(temp[n], temp[i]);
        permute(input, str, n + 1, temp); //递归
        swap(temp[n], temp[i]); //回溯

    }
}

vector<string> Permutation(string str) {
    // write code here
    vector<string> ans;
    if (str.length() == 0) return vector<string>(0, "");
    int len = str.size();
    set<string> res; //去重

    permute(res, str, 0, str);

    for (auto i : res) ans.push_back(i);
    return ans;
}



//n皇后问题，n*n棋盘上，能放多少个皇后，要求皇后不能对角线不能同行同列
bool isValid(vector<int>& p, int r, int c) {
    for (int i = 0; i < r; i++) {
        int diff_r = abs(r - i);
        int diff_c = abs(p[i] - c); //不能对角线就是计算r和c的绝对值差
        cout << p[i] << " " << c << endl;
        if (diff_r == diff_c || r == i || c == p[i]) return false;
    }
    return true;
}

void permute_Nqueen(vector<int>& p, int r, int c, int n, int& res) {
    if (r == n - 1) { //如果到了最后一层，结束，res++
        res++;
        return;
    }
    p[r] = c; //记录当前皇后位置
    for (int i = 0; i < n; i++) {
        if (isValid(p, r + 1, i)) permute_Nqueen(p, r + 1, i, n, res);  //判断下一个点位是否适合放皇后，如果适合就递归
    }
}

int Nqueen(int n) {
    // write code here、
    //大概是二维数组的回溯法？
    vector<int> column(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        permute_Nqueen(column, 0, i, n, res);
    }
    return res;
}


//嵌套括号问题
void generateBrackets(int n, int left, int right, string str, vector<string>& res) {
    if (left == n && right == n) {
        res.push_back(str);
        return;
    }
    if (left < n) generateBrackets(n, left + 1, right, str + '(', res); 
    if (right<n && left > right) generateBrackets(n, left, right + 1, str + ')', res); //要合法，就必须是左括号用的比右括号多才能用用括号
}

vector<string> generateParenthesis(int n) {
    // write code here
    //实际上可以转化成数字++的问题
    string str = "";
    vector<string> res;
    //set<string> res;
    generateBrackets(n, 0, 0, str, res);
    //for(auto i:res) cout<<i<<endl;
    return res;
}


//矩阵最长递增路径，非负数矩阵，递归+动态规划
int findAscendingMaxPath(int r, int c, int pre, vector<vector<int> >& matrix,
    vector<vector<int> >& dp) {
    int row = matrix.size();
    int column = matrix[0].size();
    if (r >= row || c >= column || r < 0 || c < 0) return 0; //判断数组越界与否？ 结束递归条件
    if (matrix[r][c] <= pre || matrix[r][c] < 0) { //判断是否递增？ 结束递归条件
        dp[r][c] = 0;
        return dp[r][c];
    }
    pre = matrix[r][c];
    if (dp[r][c] == 0) { //当没有记录当前点的最大递增路径的时候，上下左右，四个方向移动
        int up = findAscendingMaxPath(r - 1, c, pre, matrix, dp);
        int down = findAscendingMaxPath(r + 1, c, pre, matrix, dp);
        int left = findAscendingMaxPath(r, c - 1, pre, matrix, dp);
        int right = findAscendingMaxPath(r, c + 1, pre, matrix, dp);
        dp[r][c] = max(max(up, down), max(left, right)) + 1; //该点开始的最大递增路径。
    }
    return dp[r][c]; //如果之前已经记录过了，那就直接返回

}


int solve(vector<vector<int> >& matrix) {
    // write code here
    int row = matrix.size();
    int column = matrix[0].size();
    int res = 0;
    vector<vector<int> >dp(row, vector<int>(column, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            res = max(findAscendingMaxPath(i, j, -1, matrix, dp), res);
        }
    }
    return res;
}