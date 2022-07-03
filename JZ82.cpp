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
     * @param root TreeNode��
     * @param sum int����
     * @return bool������
     */
    bool hasPathSum(TreeNode* root, int sum) { //dfs �ݹ�
        // write code here
        if (root == nullptr) return false;
        sum -= root->val;
        if (sum == 0 && root->left == nullptr && root->right == nullptr)
            return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};