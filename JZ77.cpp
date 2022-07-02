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
class Solution { //链表的遍历+bfs
public: 

    vector<vector<int> > res;
    bool l2r = true;
    void ergodic(vector<TreeNode*>& node_v) { //广度优先遍历
        if (node_v.empty()) return;
        vector<TreeNode*> temp;
        vector<int> ans;
        for (auto i : node_v) {
            cout << i->val << " ";
            if (i->left != nullptr) temp.push_back(i->left);
            if (i->right != nullptr) temp.push_back(i->right);
            if (l2r) {
                ans.push_back(i->val);
            }
            else {
                ans.insert(ans.begin(), i->val);
            }
        }
        res.push_back(ans);
        if (l2r) l2r = false;
        else l2r = true;
        cout << endl;
        ergodic(temp);
    }
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == nullptr) return vector<vector<int>>(NULL);
        vector<TreeNode*> temp;
        temp.push_back(pRoot);
        ergodic(temp);

        return res;
    }

};