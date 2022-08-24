#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

//打家劫舍的第三题，二叉树打家劫舍。
int rob_recursive(TreeNode* root, bool flag,
    map<pair<TreeNode*, bool>, int>& m) { //用一个存储pair的map记录每个点是否已经计算过，和计算的结果，减少重复计算，dp的思想
    if (root == nullptr) return 0;
    int ans = 0;
    if (m[pair<TreeNode*, bool>(root, false)] == 0) {
        ans = rob_recursive(root->left, true, m) + rob_recursive(root->right, true, m);
        m[pair<TreeNode*, bool>(root, false)] = ans;
    }
    else ans = m[pair<TreeNode*, bool>(root, false)];

    if (flag)
        if (m[pair<TreeNode*, bool>(root, true)] == 0) {
            ans = max(ans, root->val + rob_recursive(root->left, false, m) + rob_recursive(root->right, false, m));
            m[pair<TreeNode*, bool>(root, true)] = ans;
        }
        else ans = m[pair<TreeNode*, bool>(root, true)];
    return ans;
}
int rob(TreeNode* root) {
    // write code here
    if (root == nullptr) return 0;
    map<pair<TreeNode*, bool>, int> m;
    return rob_recursive(root, true, m);
}