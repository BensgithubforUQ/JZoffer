/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    vector<int> res;
    bool dfs(TreeNode* root, int a, int b) { //还是那套东西，dfs遍历，返回值来确定公共祖先
        if (root == nullptr) return false;
        int flag = false;
        bool l = dfs(root->left, a, b);
        bool r = dfs(root->right, a, b);
        if (root->val == a || root->val == b) flag = true;
        if ((l && r) || (l && flag) || (r && flag)) { //三个情况判断是公共祖先
            //1，左右都为真，则是公共祖先
            //2,3， 左右有一个是真，自己本身就是其中一个值。
            res.push_back(root->val);
            return true;
        }
        return flag || l || r; //返回的值要注意，只要该结点的子树查找到了，该结点就该返回真，如果该结点本身是要找的值，则更是真
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        dfs(root, o1, o2);
        if (res.empty()) return NULL;
        for (auto i : res) {
            cout << i << " ";
        }
        return res[0];
    }
};