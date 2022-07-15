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

//二叉树的前序遍历
vector<int> pre_order_traversal(TreeNode* root) { //所谓前序遍历，就是，先遍历左子树，然后遍历右子树，就是dfs的一种。
    vector<int> res;
    if (root != nullptr)res.push_back(root->val);
    else return res;
    vector<int> left = pre_order_traversal(root->left);
    vector<int> right = pre_order_traversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

//二叉树的中序遍历
vector<int> in_order_Traversal(TreeNode* root) { //所谓中序遍历，就是，先遍历左树，然后输入根节点值，然后遍历右子树，也是dfs的一种
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

//二叉树的后序遍历
vector<int> post_order_Traversal(TreeNode* root) { //traversal所谓后序遍历，就是遍历顺序为左子树，右子树，根节点的dfs
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

//二叉树bfs的递归写法
void level_order_support(TreeNode* root, vector<vector<int>>& temp, int level) { //递归法层序遍历，bfs
    if (root == nullptr) return;
    if (level > temp.size()) temp.push_back(vector<int>(0));
    temp[level - 1].push_back(root->val);
    level_order_support(root->left, temp, level + 1);
    level_order_support(root->right, temp, level + 1);
}
vector<vector<int> > levelOrder(TreeNode* root) { //递归法，bfs
    // write code here
    vector<vector<int>> res;
    int level = 1;
    level_order_support(root, res, level);
    return res;
}

//二叉树bfs非递归写法，辅助双端栈。
vector<vector<int> > levelOrder_deque(TreeNode* root) { //辅助栈法
    // write code here
    deque<TreeNode*> level;
    vector<vector<int>> res;
    if (root == nullptr) return res;
    level.push_back(root);
    int size = 1;
    while (size) {
        int temp_size = 0;
        vector<int> temp; //temp数组用于记录当层的val
        for (int i = 0; i < size; i++) {//size是当前层的队列的size大小
            temp.push_back(level[0]->val); //对于当前层中的每个结点的值，push
            if (level[0]->left != nullptr) { //根节点有后++
                level.push_back(level[0]->left);
                temp_size++;
            }
            if (level[0]->right != nullptr) {//根节点有后++
                level.push_back(level[0]->right);
                temp_size++;
            }
            level.pop_front(); //根节点的数据已经存完，子节点已经存入queue，pop
        }
        if (temp.size() != 0) res.push_back(temp);
        size = temp_size;
    }
    return res;
}


void bfs_bendPrint(TreeNode* root, vector<vector<int>>& temp, int level, bool flag) { //之字形打印，实际上还是bfs，只不过插入数组的方法不一样
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