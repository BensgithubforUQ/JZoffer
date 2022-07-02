/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > res;
    void bfs(vector<TreeNode*>& node_v) { //bfs和前面一个题目没区别
        if (node_v.empty()) return;
        vector<int> ans;
        vector<TreeNode*>temp;
        for (auto i : node_v) {
            ans.push_back(i->val);
            if (i->left != nullptr) temp.push_back(i->left);
            if (i->right != nullptr) temp.push_back(i->right);
        }
        res.push_back(ans);
        bfs(temp);
    }

    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == nullptr) return res;
        vector<TreeNode*>node_v;
        node_v.push_back(pRoot);
        bfs(node_v);
        return res;
    }

};