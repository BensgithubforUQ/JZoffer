/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型
     */
    int res = 0;
    void dfs(TreeNode* root, int sum, bool del) {
        if (root == nullptr) return;
        if (!del) { //如果，没有减过，则传原值下去
            dfs(root->left, sum, del);
            dfs(root->right, sum, del);
        }
        del = true;//减值之后，就不能进上面传原值的，以后必须都减
        int temp = 0;
        temp = sum - root->val;
        if (temp == 0) res++;
        dfs(root->left, temp, del);
        dfs(root->right, temp, del);
    }
    int FindPath(TreeNode* root, int sum) {
        // write code here
        dfs(root, sum, false);
        return res;

    }
};


