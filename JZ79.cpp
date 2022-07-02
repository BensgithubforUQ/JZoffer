class Solution {
public:
    bool balance = true;
    int dfs(TreeNode* pRoot, int d) {
        if (pRoot == nullptr) return d;
        d++;
        int right = dfs(pRoot->right, d);
        int left = dfs(pRoot->left, d);
        int diff = right - left;

        if (diff * diff > 1) balance = false;
        return max(right, left);
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
        cout << dfs(pRoot, 0);

        return balance;
    }
};