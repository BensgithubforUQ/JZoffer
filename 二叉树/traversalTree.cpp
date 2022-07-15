#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

//��������ǰ�����
vector<int> pre_order_traversal(TreeNode* root) { //��νǰ����������ǣ��ȱ�����������Ȼ�����������������dfs��һ�֡�
    vector<int> res;
    if (root != nullptr)res.push_back(root->val);
    else return res;
    vector<int> left = pre_order_traversal(root->left);
    vector<int> right = pre_order_traversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

//���������������
vector<int> in_order_Traversal(TreeNode* root) { //��ν������������ǣ��ȱ���������Ȼ��������ڵ�ֵ��Ȼ�������������Ҳ��dfs��һ��
    // write code here
    vector<int>res;
    if (root == nullptr) return res;
    vector<int>left = in_order_Traversal(root->left);
    res.insert(res.end(), left.begin(), left.end());
    res.push_back(root->val);
    vector<int>right = in_order_Traversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

//�������ĺ������
vector<int> post_order_Traversal(TreeNode* root) { //traversal��ν������������Ǳ���˳��Ϊ�������������������ڵ��dfs
    // write code here
    vector<int> res;
    if (root == nullptr) return res;
    vector<int> left = post_order_Traversal(root->left);
    res.insert(res.end(), left.begin(), left.end());
    vector<int> right = post_order_Traversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
    res.push_back(root->val);
    return res;
}

//������bfs�ĵݹ�д��
void level_order_support(TreeNode* root, vector<vector<int>>& temp, int level) { //�ݹ鷨���������bfs
    if (root == nullptr) return;
    if (level > temp.size()) temp.push_back(vector<int>(0));
    temp[level - 1].push_back(root->val);
    level_order_support(root->left, temp, level + 1);
    level_order_support(root->right, temp, level + 1);
}
vector<vector<int> > levelOrder(TreeNode* root) { //�ݹ鷨��bfs
    // write code here
    vector<vector<int>> res;
    int level = 1;
    level_order_support(root, res, level);
    return res;
}

//������bfs�ǵݹ�д��������˫��ջ��
vector<vector<int> > levelOrder_deque(TreeNode* root) { //����ջ��
    // write code here
    deque<TreeNode*> level;
    vector<vector<int>> res;
    if (root == nullptr) return res;
    level.push_back(root);
    int size = 1;
    while (size) {
        int temp_size = 0;
        vector<int> temp; //temp�������ڼ�¼�����val
        for (int i = 0; i < size; i++) {//size�ǵ�ǰ��Ķ��е�size��С
            temp.push_back(level[0]->val); //���ڵ�ǰ���е�ÿ������ֵ��push
            if (level[0]->left != nullptr) { //���ڵ��к�++
                level.push_back(level[0]->left);
                temp_size++;
            }
            if (level[0]->right != nullptr) {//���ڵ��к�++
                level.push_back(level[0]->right);
                temp_size++;
            }
            level.pop_front(); //���ڵ�������Ѿ����꣬�ӽڵ��Ѿ�����queue��pop
        }
        if (temp.size() != 0) res.push_back(temp);
        size = temp_size;
    }
    return res;
}


void bfs_bendPrint(TreeNode* root, vector<vector<int>>& temp, int level, bool flag) { //֮���δ�ӡ��ʵ���ϻ���bfs��ֻ������������ķ�����һ��
    if (root == nullptr) return;
    if (level > temp.size()) temp.push_back(vector<int>(0));
    if (flag) temp[level - 1].push_back(root->val);
    else temp[level - 1].insert(temp[level - 1].begin(), root->val);
    bfs_bendPrint(root->left, temp, level + 1, !flag);
    bfs_bendPrint(root->right, temp, level + 1, !flag);
}

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> res;
    int level = 1;
    bfs_bendPrint(pRoot, res, level, true);
    return res;
}
//int main() {
//    TreeNode x(0);
//    cout << sizeof(x) << endl;
//    return 0;
//}