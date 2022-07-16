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


bool symmetrical_recursion(TreeNode* l, TreeNode* r) { //递归写法，判断是否是对称的二叉树
    if (l == nullptr && r == nullptr) return true;
    if (l == nullptr || r == nullptr) return false;
    if (l->val != r->val) return false;
    return true && symmetrical_recursion(l->left, r->right) && symmetrical_recursion(l->right, r->left); //主要思想就是一个递归
}

bool isSymmetrical(TreeNode* pRoot) {
    if (pRoot == nullptr) return true;
    return symmetrical_recursion(pRoot->left, pRoot->right);
}

bool isSymmetrical_iterate(TreeNode* p) { //迭代写法，类似层序遍历的手法
    deque<TreeNode*> tree;
    if (p == nullptr) return true; //空树是对称的
    tree.push_front(p->left);
    tree.push_back(p->right);
    while (!tree.empty()) {
        TreeNode* l = tree.front();
        TreeNode* r = tree.back();
        tree.pop_front();
        tree.pop_back();
        if (l == nullptr && r == nullptr) continue; //空节点
        if (l == nullptr || r == nullptr || (r->val != l->val)) return false;
        //不是上述情况，说明不是空节点，并且两个点的val相等，那么继续考虑后面的情况
        tree.push_front(l->right);
        tree.push_front(l->left);
        tree.push_back(r->left);
        tree.push_back(r->right);
    }
    return true;
}

bool flag = true;
int lowestCommonAncestor(TreeNode* root, int p, int q) { //二叉搜索树中子节点的公共祖先，递归做法1，不利用特性，二叉树找公共祖先通用
    // write code here
    if (root == nullptr) return 0;
    int count = 0;
    count += lowestCommonAncestor(root->left, p, q);
    count += lowestCommonAncestor(root->right, p, q);
    if (root->val == q || root->val == p) count++;
    if (count == 2 && flag) {
        flag = false; //这个地方很关键，因为要找最近的祖先，所以整个flag，第一次找到之后就再不进这一步
        return root->val;
    }
    return count;
}

int lowestCommonAncestor_recursion(TreeNode* root, int p, int q) { //递归操作2，利用二叉搜索树的特性
    // write code here
    if (root == nullptr) return 0;
    int mx = max(p, q);
    int mn = min(p, q); //利用二叉搜索树的性质，左侧子树严格小于根节点
    if (root->val >= mn && root->val <= mx) return root->val;
    int res = 0;
    if (root->val > mx) res = lowestCommonAncestor(root->left, p, q); 
    if (root->val < mn) res = lowestCommonAncestor(root->right, p, q);
    return res;
}
//int main() {
//    TreeNode x(0);
//    cout << sizeof(x) << endl;
//    return 0;
//}