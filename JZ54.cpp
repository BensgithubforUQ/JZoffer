#include<iostream>
#include<vector>
#using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param proot TreeNode��
     * @param k int����
     * @return int����
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