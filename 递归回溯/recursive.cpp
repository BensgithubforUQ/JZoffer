#include <iostream>
#include <vector>
#include <set>
using namespace std;


//�ݹ�������Ҫ���������£���һ���£��ǵݹ�����������ڶ����¾��ǵݹ���򣨼���εݹ飩


//Ϳɫ�����⣬������һ���м�������
void island(vector<vector<char>>& g, int row, int column) { //
    if (row < 0 || column < 0 || row >= g.size() ||
        column >= g[0].size()) return;
    if (g[row][column] == '0') return; //�������ͽ����ݹ�
    g[row][column] = '0'; //�����Ǻ���ʱ�򣬾Ͱѱ�ɺ��Է��ݹ���ѭ��
    island(g, row + 1, column); //Ȼ�����ĸ�����dfs�Ѹõ�ȫ����¼�ɺ�����ֹ�ظ���¼
    island(g, row, column + 1);
    island(g, row - 1, column);
    island(g, row, column - 1);
}

int solve(vector<vector<char> >& grid) {
    // write code here
    int row = grid.size();
    int column = grid[0].size();
    int count = 0;
    for (int i = 0; i < row; i++) { //ѭ�����ҵ�
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == '1') {
                island(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

//����������⣬���ʾ��ǿ��ж����ֽ������
//ֻҪ��������������������һ���µ������Ȼ�����µ�������еݹ飬�ݹ����֮����ݣ�ԭ���齻����λ������Ų
void permute(set<string>& input, string& str, int n, string temp) {
    int len = str.size();
    if (n >= len) {
        input.insert(temp);
        return;
    }
    //input.insert(temp);
    for (int i = n; i < len; i++) {
        swap(temp[n], temp[i]);
        permute(input, str, n + 1, temp); //�ݹ�
        swap(temp[n], temp[i]); //����

    }
}

vector<string> Permutation(string str) {
    // write code here
    vector<string> ans;
    if (str.length() == 0) return vector<string>(0, "");
    int len = str.size();
    set<string> res; //ȥ��

    permute(res, str, 0, str);

    for (auto i : res) ans.push_back(i);
    return ans;
}



//n�ʺ����⣬n*n�����ϣ��ܷŶ��ٸ��ʺ�Ҫ��ʺ��ܶԽ��߲���ͬ��ͬ��
bool isValid(vector<int>& p, int r, int c) {
    for (int i = 0; i < r; i++) {
        int diff_r = abs(r - i);
        int diff_c = abs(p[i] - c); //���ܶԽ��߾��Ǽ���r��c�ľ���ֵ��
        cout << p[i] << " " << c << endl;
        if (diff_r == diff_c || r == i || c == p[i]) return false;
    }
    return true;
}

void permute_Nqueen(vector<int>& p, int r, int c, int n, int& res) {
    if (r == n - 1) { //����������һ�㣬������res++
        res++;
        return;
    }
    p[r] = c; //��¼��ǰ�ʺ�λ��
    for (int i = 0; i < n; i++) {
        if (isValid(p, r + 1, i)) permute_Nqueen(p, r + 1, i, n, res);  //�ж���һ����λ�Ƿ��ʺϷŻʺ�����ʺϾ͵ݹ�
    }
}

int Nqueen(int n) {
    // write code here��
    //����Ƕ�ά����Ļ��ݷ���
    vector<int> column(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        permute_Nqueen(column, 0, i, n, res);
    }
    return res;
}


//Ƕ����������
void generateBrackets(int n, int left, int right, string str, vector<string>& res) {
    if (left == n && right == n) {
        res.push_back(str);
        return;
    }
    if (left < n) generateBrackets(n, left + 1, right, str + '(', res); 
    if (right<n && left > right) generateBrackets(n, left, right + 1, str + ')', res); //Ҫ�Ϸ����ͱ������������õı������Ŷ������������
}

vector<string> generateParenthesis(int n) {
    // write code here
    //ʵ���Ͽ���ת��������++������
    string str = "";
    vector<string> res;
    //set<string> res;
    generateBrackets(n, 0, 0, str, res);
    //for(auto i:res) cout<<i<<endl;
    return res;
}


//���������·�����Ǹ������󣬵ݹ�+��̬�滮
int findAscendingMaxPath(int r, int c, int pre, vector<vector<int> >& matrix,
    vector<vector<int> >& dp) {
    int row = matrix.size();
    int column = matrix[0].size();
    if (r >= row || c >= column || r < 0 || c < 0) return 0; //�ж�����Խ����� �����ݹ�����
    if (matrix[r][c] <= pre || matrix[r][c] < 0) { //�ж��Ƿ������ �����ݹ�����
        dp[r][c] = 0;
        return dp[r][c];
    }
    pre = matrix[r][c];
    if (dp[r][c] == 0) { //��û�м�¼��ǰ���������·����ʱ���������ң��ĸ������ƶ�
        int up = findAscendingMaxPath(r - 1, c, pre, matrix, dp);
        int down = findAscendingMaxPath(r + 1, c, pre, matrix, dp);
        int left = findAscendingMaxPath(r, c - 1, pre, matrix, dp);
        int right = findAscendingMaxPath(r, c + 1, pre, matrix, dp);
        dp[r][c] = max(max(up, down), max(left, right)) + 1; //�õ㿪ʼ��������·����
    }
    return dp[r][c]; //���֮ǰ�Ѿ���¼���ˣ��Ǿ�ֱ�ӷ���

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