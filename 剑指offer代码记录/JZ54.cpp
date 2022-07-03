#include<iostream>
#include<vector>
#using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    vector<int> treenode;
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if (k == 0) return -1;
        if (proot == nullptr) return -1;
        dfs(proot);
        if (treenode.size() < k) return -1;
        for (auto i : treenode) {
            k--;
            if (k == 0) return i;
            cout << i << endl;
        }
        return 0;
    }

    void dfs(TreeNode* root) {
        if (root->left != nullptr) dfs(root->left);
        treenode.push_back(root->val);
        if (root->right != nullptr)dfs(root->right);
        return;
    }
};