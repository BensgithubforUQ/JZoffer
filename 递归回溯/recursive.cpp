#include <iostream>
#include <vector>
#include <set>
using namespace std;

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