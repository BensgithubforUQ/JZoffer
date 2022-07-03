/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution { //JZ55简单的二叉树的深度查询
public:
    int max = 0;
    int TreeDepth(TreeNode* pRoot) {
        int temp = 0;
        if (pRoot == nullptr) return 0;
        max = dfs(pRoot, temp);
        return max;
    }

    int dfs(TreeNode* root, int temp) {
        temp++;
        if (root->left == nullptr && root->right == nullptr) {
            return temp;
        }
        int temp_r = temp;
        int temp_l = temp;
        if (root->left != nullptr) temp_l = dfs(root->left, temp_l);
        if (root->right != nullptr) temp_r = dfs(root->right, temp_r);
        max = temp_r > temp_l ? temp_r : temp_l;
        return max;

    }
};