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
     * @param p int整型
     * @param q int整型
     * @return int整型
     */


    vector<int> pos;
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        if (root == nullptr) return 0;
        int count = 0;
        if (root->val == p || root->val == q) count = 1;
        count += lowestCommonAncestor(root->left, p, q);
        count += lowestCommonAncestor(root->right, p, q);
        if (count == 2) //pos.push_back(root->val);
            return root->val;
        cout << pos.size() << endl;
        return count;
    }
};