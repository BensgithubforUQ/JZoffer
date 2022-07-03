/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) { //dfs 递归
        // write code here
        if (root == nullptr) return false;
        sum -= root->val;
        if (sum == 0 && root->left == nullptr && root->right == nullptr)
            return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};