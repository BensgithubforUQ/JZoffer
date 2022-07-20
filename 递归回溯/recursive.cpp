#include <iostream>
#include <vector>
#include <set>
using namespace std;

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